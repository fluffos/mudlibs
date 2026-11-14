/* These must be one character long! */
#define RINIT	1       /* Request initialisation */
#define RCOMMAND 2      	/* Send a command */ 
#define RACK 	3	/* Remote acknowledgement of created body etc */
#define NACK 	4	/* Remote negative acknowledgement etc */
#define RRESPONSE 5	/* Command response (what you see etc) */
#define RFLUSH 6	/* Flush remote output buffer (what you see etc) */
#define RPROMPT 7	/* Set remote prompt */
#define RHANGUP 8	/* leave remote state */
#define RROUTE 9	/* in case they go through *another* gate! */

#define MAX_REMOTE	20

