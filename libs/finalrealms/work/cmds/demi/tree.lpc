// Taken from Various people, this prints inheritance trees
 // Moredhel stole pieces from Me, Laggard and Maui :)
// Asmodean '97
// 
#include <cmd.h>

inherit CMD_BASE;

 protected int listrecurse(string indent, string what, object me)
{
    int i;
    string *thislevel;
    object ob = find_object(what);

    if(ob == 0)
    {
	tell_object(me,what+" is not loaded.\n");
	return 1;
    }

    thislevel = inherit_list(ob);
    for(i = 0; i < sizeof(thislevel);i++)
    {
	tell_object(me,indent+thislevel[i]+"\n");
     listrecurse(indent+"  ", thislevel[i], me);
    }
    return 1;
}

int cmd(string what, object me)
{
object ob;

    if (!what)
    {
	tell_object(me,query_verb()+" <object_name>\n");
    return 1;
    }

    ob = find_object(what);

    if(ob == 0)
    {
	what = me->query_current_path()+"/"+what;
	ob = find_object(what);
    }
    if(ob == 0)
    {
	tell_object(me,what+" is not loaded.\n");
	return 1;
    }

    tell_object(me,what+" inherits:\n");
   listrecurse( "  ", what, me);
    return 1;
}


