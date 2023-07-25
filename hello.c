#include <sys/syscall.h>
#include <unistd.h>

#ifndef DOCKER_IMAGE
	#define DOCKER_IMAGE "hello-world"
#endif

#ifndef DOCKER_GREETING
	#define DOCKER_GREETING "Hello from kubedock!"
#endif

#ifndef DOCKER_ARCH
	#define DOCKER_ARCH "amd64"
#endif

const char message[] =
	"\n"
	DOCKER_GREETING "\n"
	"This message shows that your installation appears to be working correctly.\n"
	"\n"
	"To generate this message, we took the following steps:\n"
	" 1. The Podman client contacted the Kubedock daemon.\n"
  " 2. The Kubedock daemon created a Pod using the Kubernetes API based on the \"" DOCKER_IMAGE "\""
	" 3. A kubelet daemon on a cluster node pulled the \"" DOCKER_IMAGE "\" image from the container registry.\n"
	"    (" DOCKER_ARCH ")\n"
	" 4. The container runtime created a new container from that image which runs the\n"
	"    executable that produces the output you are currently reading.\n"
	" 4. Kubedock streamed that output to the Podman client, which sent it\n"
	"    to your terminal.\n"
	"\n"
	"To try something more ambitious, you can run an http server container with:\n"
	" $ podman run --name httpd -d -p 8080:8080 python python -m http.server 8080\n"
	"\n";

int main() {
	//write(1, message, sizeof(message) - 1);
	syscall(SYS_write, STDOUT_FILENO, message, sizeof(message) - 1);

	//_exit(0);
	//syscall(SYS_exit, 0);
	return 0;
}
