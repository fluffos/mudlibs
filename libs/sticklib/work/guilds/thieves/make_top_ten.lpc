#include "dirs.h"

int i;
object *u;

void
foo()
{
    u = users();

    i = sizeof(u) - 1;

    call_out("check", 1);
}

void
check()
{
    if (present("tmark", u[i]))
	call_other(GDIR + "top_ten", "check_top_ten", u[i]);

    i--;

    if (i >= 0) call_out("check", 1);
}

