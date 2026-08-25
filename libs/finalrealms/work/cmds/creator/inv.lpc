// Modified allinv (cause inv just vanished one day.. ;)
// Randor, 25-mar-98
#pragma strict_types
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

    position = 1;
}

protected int cmd(string str, object me) {
    object *inv,*tmp;
    object targ;
    string s,result = "";

    if (this_player(1) != me) return 0;

    if (!str) 
       {
       notify_fail("Usage: inv <object>\n");
       return 0;
       }

    if(!sizeof(tmp = wiz_present(str, me)))
      return 0;
    targ=tmp[0];
    inv = all_inventory(targ);
    result="Inv of "+desc_object(targ)+":\n";
    foreach (object ob in inv) {

        if (!catch(s = (string)ob->short()) && s) ;
        else if (!catch(s = (string)ob->query_name()) && s) ;  
	else s = "** No Desc **";
	result += sprintf("%s (%O)\n", s, ob);
    }
    return this_player()->more_string(result);
}
