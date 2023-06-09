/* Name: Eva Stenberg
 * Date: 10/13/2022
 * Title: Lab3 - This program demonstrates the usage of IPC between processes
 * using pipes to execute the command "cat /etc/passwd | grep root"
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
//1 = file descriptor of stdout
//0 = file descriptor of stdin
int main()
{
	int fds[2];
	pipe(fds);
	//Child 1 duplicates downstream into stdin
	if(fork() == 0)
	{
		dup2(fds[0], 0); //takes what is going downstream and sends it to stdin
		close(fds[1]); //child 1 closes upstream end of pipe
		execlp("grep", "grep", "root", NULL);
	}
	//Child 2 duplicates upstream into stdout
	else if(fork() == 0)
	{
		dup2(fds[1], 1); //takes what is going upstream and sends it to stdout
		close(fds[0]); //child 2 closes downstream end of pipe
		execlp("cat", "cat", "/etc/passwd", NULL);
	}
	else //parent closes both ends and waits for children
	{
		close(fds[0]); //parent closes both ends of pipe
		close(fds[1]); 
		wait(0);
		wait(0);
	}
	return 0;
}