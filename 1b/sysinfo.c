#include <sys/sysinfo.h>

int main(){
	struct sysinfo u;
	sysinfo(&u);

	printf("%ld ", u.uptime);
	printf("%lu ", u.totalram);
	printf("%lu ", u.freeram);
	printf("%lu ", u.sharedram);
}
