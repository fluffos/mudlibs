//#pragma save_binary
#include <mudlib.h>
#include <uid.h>

inherit DAEMON;

int cmd_master(string arg)
{
	seteuid(ROOT_UID);
	destruct(master());
	if( arg=="-s" ) destruct("/adm/obj/simul_efun");
	to_chinese("???");
	file_size("???");
	write("Ok.\n");
	return 1;
}

int help()
{
	write( "Syntax: master\n"
		"Effect: Updates the master object.\n"
	);
	return 1;
}
