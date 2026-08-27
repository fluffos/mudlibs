// This is the NEW virtual server of rooms in /d/noden/daemon_tower
// By Ruby@ES 6/30, 1995

#include <daemons.h>
#include <mudlib.h>

#define TEMPLATE ROOM

void create()
{
	seteuid(getuid());
}
void clean_up()
{
	destruct(this_object());
}

// This function is called when the driver try to compile an object of
// the name _*.c in daemon_tower
object compile_object(string s)
{
	object obj;
	string *fname, index, new_name;

	seteuid(getuid(this_object()));
	fname = explode(s, "/");
	index = fname[sizeof(fname)-1];
	new_name = replace_string(s, index, "_"+index);
	if( file_size(new_name+".c") <= 0 )
// 	we have virtual map in noden , so ... connect to map server ..
		return (object)call_other("/d/noden/virtual/noden_server","compile_object",s);
//	if without virtual map ... choose below
//		return error("File not exist: "+new_name+"\n");

	obj = new(TEMPLATE);
	call_other(new_name,"create",obj);
//	obj->reset();
	destruct(find_object(new_name));
	return obj;
}
