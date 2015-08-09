#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/poll.h>

#define MAX_BUFFER_SIZE		512
char readBuf[MAX_BUFFER_SIZE];

#define NUM_MESSAGES		100
#define DEVICE_NAME		"/dev/rpmsg_pru31"

int main (void){
	struct pollfd pollfds[1];
	int i;
	int result = 0;

	pollfds[0].fd = open(DEVICE_NAME, O_RDWR);

	if(pollfds[0].fd < 0) {
		printf("Failed to open %s\n", DEVICE_NAME);
		return -1;
	}

	printf("Opened %s, sending %d messages\n\n", DEVICE_NAME, NUM_MESSAGES);

	for(i = 0; i < NUM_MESSAGES; i++){
		result = write(pollfds[0].fd, "hello world!", 13);
		if(result > 0)
			printf("Message %d: Sent to PRU\n", i);			
			
		result = read(pollfds[0].fd, readBuf, MAX_BUFFER_SIZE);
		if(result > 0)
			printf("Message %d received from PRU:%s\n\n", i, readBuf);
	}
	
	printf("Received %d messages, closing %s\n", NUM_MESSAGES, DEVICE_NAME);

	close(pollfds[0].fd);

	return 0;
}

