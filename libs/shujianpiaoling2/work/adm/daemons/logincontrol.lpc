// startcontrol.c
#include <ansi.h>
#include <command.h>
#include <globals.h>
void create()
{
        seteuid( ROOT_UID );
	call_out("releaselock",300);
}

int releaselock()
{
	LOGIN_D->set_daemonlock(0);
	return 1;
}

