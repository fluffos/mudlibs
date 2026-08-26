// _config.c
// Gives all relevant info about the runtime config file settings
// Uses the get_config efun. I'm not sure when get_config got added, 
// since it's not mentioned in the ChangeLogs ;) ;)
//
// This file may die whenever Beek adds unforseen stuff ;)
// Leto 02/05/95

#include <mudlib.h>

inherit DAEMON ;

int is_define(string foo,int flag);

int cmd_config() { 


string * config, * defines;
string input,output;
int i;

// read the runtime_config.h file

	input = read_file("/include/driver/runtime_config.h");

	if(!input) {
		notify_fail("Can't find /include/driver/runtime_config.h,"
		       	    "see help for details\n");
		            return 0;
	}
	config = explode(input,"\n");
	// Dump everything not starting with #define
	defines = filter_array(config,"is_define",this_object(),0);
	for (i=0;i<sizeof(defines);i++) {
    		sscanf( defines[i], "%*s__%s__%*s", defines[i] );
    	}
	// now dump everything Beek says which is irrelevant ;)
	defines = filter_array(defines,"is_define",this_object(),1);
	// show in the format: __XXX__ = returnvalue
	for (i=0;i<sizeof(defines);i++) {
		defines[i] = "__"+defines[i]+"__"+" = "+get_config(i);
	}
	// Now let's see it
	output = implode(defines,"\n");
	input = temp_file("cfg",this_player());
	write_file(input,output); // confusing euh? :)
	this_player()->more(input);
	return 1; 
}

int is_define(string foo, int flag) {

	string tmp;

	if (!flag) return sscanf(foo,"%sdefine %s",tmp, tmp);
	else 
	   {
	    if(!sscanf(foo,"%sdefine %s",tmp, tmp))
	    return 1;
	    else return 0;
	}
 
}

string help() {

	return ( wrap (
"This command returns all the information you want to know about the "
"config.mud file. Intended for admins without shell access, or those "
"admins who forgot what they defined in options.h and the Makefile ;)\n"
"You should have a link from your driver/include directory to /include/driver "
"in your mudlib and have 0.9.20(?) or above!"
));
}
