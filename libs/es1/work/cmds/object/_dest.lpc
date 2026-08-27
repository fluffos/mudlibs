//#pragma save_binary
 
//	File	:  /cmds/xtra/_dest.c
//	Creator	:  Huthar/Wayfarer@Portals
//	Updated	:  Watcher@TMI (02/19/93) to search with get_object()
//		   and an optional object wipe before destruction
//
//	This is the wizard destruct command.

#include <mudlib.h>
#include <protects.h>

inherit DAEMON;

#define SYNTAX "Syntax: dest [-a] [object]\n"
 
int dest_all(object act_ob, int silent)
{
	int i;
	object *ob;
	
	ob = deep_inventory(act_ob);
 
	for(i = 0; i < sizeof(ob); i++) {
		if( (member_array( file_name(ob[i]), PROTECT_FILES ) != -1) &&
			!member_group(geteuid(act_ob), "admin") )
		continue;
		
		if( !silent ) write("Desting: " + identify(ob[i]) + "\n");
 
		if( !(ob[i]->is_player() && interactive(ob[i])) ) {
			ob[i]->remove();
			if( ob[i] ) destruct(ob[i]);
		}
	}
	return 1;
}

int cmd_dest(string str)
{
	object ob, act_ob;
	string msg;
	int clean;
	
	act_ob = previous_object(); 
 
	notify_fail( SYNTAX );
	if(!str || str == "") return 0;
 
	if( str == "all" ) return dest_all(act_ob, 0); 

	if( sscanf(str, "-a %s", str) == 1 ) clean = 1;

	if( !(ob = get_object(str)) ) {
		write("Dest: Could not locate that object.\n");
		return 1;
	}

	if( (member_array( file_name(ob), PROTECT_FILES ) != -1) &&
		!member_group(geteuid(act_ob), "admin") ) {
		write("You can't destruct this object!\n");
		return 1;
	}
	
	if( interactive(ob) && !member_group(geteuid(act_ob), "admin")) {
		write("Dest: Permission denied.\n");
		return 1;
	}

	if( clean ) dest_all(ob, 1);

	if( environment(ob) == this_player() ||
		environment(ob) == environment(this_player()))
		tell_room( environment(this_player()), 
			(string)act_ob->query_c_mdest(ob) + "\n" ,
			this_player()
		);
 
	ob->remove();
	if( ob ) destruct(ob);

	write( "Ok.\n"); 
	return 1;
}

int help() {
	
	write( SYNTAX + "\n" +
	"This command will search for the inputed object, and remove it\n" +
	"from existence. Only admin may remove interactive objects. If\n" +
	"the -a flag is used, it will clean the object's inventory first.\n");
 
return 1; }
 
