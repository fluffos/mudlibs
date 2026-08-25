#pragma strict_types
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}



protected int cmd(string str, object me) {
    object *inv,*tmp;
    object targ;
   object ob,ob2;
    string s,result = "";

    if (this_player(1) != me) return 0;

    notify_fail("Usage: allinv <player>\n");
    if (!str) return 0;
    targ = find_player(str);
    if (!targ) {
	notify_fail("No such player "+str+"\n");
	return 0;
    }
    inv = all_inventory(targ);
   foreach(ob in inv){

        if (!catch(s = (string)ob->short()) && s) ;
        else if (!catch(s = (string)ob->query_name()) && s) ;  
	else s = "** No Desc **";
	result += sprintf("%s (%O)\n", s, ob);
	tmp=all_inventory(ob);
	if ( sizeof(tmp) ) {
            foreach(ob2 in tmp){
        	if (!catch(s = (string)ob2->short()) && s) ;
        	else if (!catch(s = (string)ob2->query_name()) && s) ;  
		else s = "** No Desc **";
		result += sprintf("    %s (%O)\n", s, ob2);
	    }
	}
    }
    return this_player()->more_string(result);
}
