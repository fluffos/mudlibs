// pill.c
// pill.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_usex", "use");
	add_action("do_usex", "eat");
}


int do_usex( string arg)
{  	
	if ( (int)this_player()->query("hunmi") ) return 0;
	else this_object()->do_use(arg);
}