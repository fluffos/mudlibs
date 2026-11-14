

#define PR_MINF		0	/* minor page faults */
#define PR_MAJF		1	/* major page faults */
#define PR_NSWAP	2	/* swaps */
#define PR_INBLK	3	/* input blocks */
#define PR_OUBLK	4	/* output blocks */
#define PR_MSND		5	/* messages sent */
#define PR_MRCV		6	/* messages received */
#define PR_SIGS		7	/* signals received */
#define PR_VCTX		8	/* voluntary context switches */
#define PR_ICTX		9	/* involuntary context switches */
#define PR_SYSC		10	/* system calls */
#define PR_IOCH		11	/* chars read and written */
#define PR_RTIME	12	/* total lwp real (elapsed) time */
#define PR_UTIME	13	/* user level CPU time */
#define PR_STIME	14	/* system call CPU time */
#define PR_TTIME	15	/* other system trap CPU time */
#define PR_TFTIME	16	/* text page fault sleep time */
#define PR_DFTIME	17	/* data page fault sleep time */
#define PR_KFTIME	18	/* kernel page fault sleep time */
#define PR_LTIME	19	/* user lock wait sleep time */
#define PR_SLPTIME	20	/* all other sleep time */
#define PR_WTIME	21	/* wait-cpu (latency) time */
#define PR_STOPTIME	22	/* stopped time */
