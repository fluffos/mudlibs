#include <erq.h>
#define ERQ_DIR	"/usr/local/bin"
#define GPG_BIN	"gpg"

void gpg_callback(mixed result) {
	debug(as_lpc(result),"gpg");
}

int gpg(string args) {
	int res;
	args = GPG_BIN + " " + args;
	debug(args,"gpg");
	res = send_erq( ERQ_EXECUTE, args, #'gpg_callback );
	switch( res ) {
		case ERQ_OK:
			debug("ERQ_OK - operation succeeded","gpg");
			break;
		/*case ERQ_E_ARGSLENGTH:
			debug("ERQ_E_ARGSLENGTH - too long command","gpg");
			break;
		case ERQ_E_ARGFORMAT:
			debug("ERQ_E_ARGFORMAT - illegal argument given","gpg");
			break;*/
		case ERQ_E_ARGNUMBER:
			debug("ERQ_E_ARGNUMBER - too many arguments","gpg");
			break;
		case ERQ_E_ILLEGAL:
			debug("ERQ_E_ILLEGAL - command from outside ERQ_DIR requested","gpg");
			break;
		case ERQ_E_PATHLEN:
			debug("ERQ_E_PATHLEN - commandpath too long","gpg");
			break;
		case ERQ_E_FORKFAIL:
			debug("ERQ_E_FORKFAIL - command could not be forked","gpg");
			break;
		case ERQ_SIGNALED:
			debug("ERQ_SIGNALED - command terminated the signal","gpg");
			break;
		case ERQ_E_NOTFOUND:
			debug("ERQ_E_NOTFOUND - no process found to wait() for","gpg");
			break;
		case ERQ_E_UNKNOWN:
			debug("ERQ_E_UNKNOWN - unknown exit condition from wait()","gpg");
			break;
		default:
			debug("wonky response ("+res+")from send_erq()","gpg");
	}
	return res;
}

void create() {
	debug("gpg daemon loaded","gpg");
}
