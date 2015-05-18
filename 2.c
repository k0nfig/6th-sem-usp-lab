#include<stdio.h>
#include<unistd.h>

void main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("Job control supported %d\n",_POSIX_JOB_CONTROL);
	#else
		printf("Job control not supported\n");
	#endif
	#ifdef _POSIX_PRIORITY_SCHEDULING
		printf("PRIORITY SCHEDULING supported %li\n",_POSIX_PRIORITY_SCHEDULING);
	#else
		printf("PRIORITY_SCHEDULING not supported\n");
	#endif
	#ifdef _POSIX_SAVED_IDS
		printf("SAVED IDS supported %d\n",_POSIX_SAVED_IDS);
	#else
		printf("SAVED_IDS not supported\n");
	#endif
	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("CHOWN RESTRICTED supported %d\n",_POSIX_CHOWN_RESTRICTED);
	#else
		printf("CHOWN_RESTRICTED not supported\n");
	#endif
	#ifdef _POSIX_NO_TRUNC
		printf("Truncation option supported %d\n",_POSIX_NO_TRUNC);
	#else
		printf("Truncation option not supported\n");
	#endif
	#ifdef _POSIX_VDISABLE
		printf("Disable for char terminal files supported %d\n",_POSIX_VDISABLE);
	#else
		printf("Disable for char terminal files not supported\n");
	#endif
}
