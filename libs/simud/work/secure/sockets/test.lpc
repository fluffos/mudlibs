#include "socket.h"

void cb(int fd, int action, mixed a, mixed b) {
	debug("fd = "+fd+", action = "+action);
	debug("a = "+as_lpc(a));
	debug("b = "+as_lpc(b));
}

void create() {
	int fd = SOCKETD->socket_listen(9998, #'cb);
}
