// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** look.c
**
*/
#include <mudlib.h>
inherit VERB_OB;
inherit M_GRAMMAR;
void do_my_look_obj(object ob);
int need_to_be_alive() {
    return 0;
}
void do_look_str(string str)
{
}
mixed can_look_str(string str) 
{
    object here;
    here=this_body();
    while(objectp(here))
    {
	object *p_list;
        string *p_id;
	p_list=deep_inventory(here);
	foreach(object o in p_list)
	{
		p_id=o->query_id();
		if(member_array(str,p_id)!=-1)
		{
			if(default_checks()==1) {
				do_my_look_obj(o);
				return 1;
			}
			return default_checks();
		}
	}
	here=environment(here);
    }
    return "这似乎不太可能。\n";
}
void do_look() {
    environment(this_body())->do_looking(1);
}
void do_my_look_obj(object ob) 
{
    string str;
    
    str = ob->long();
    if (sizeof(str) && str[<1] != '\n') str += "\n";
    if (strlen(str)>8000)
        more(str);
    else  
        write(str);
    if ((ob->is_living())&&(ob!=this_body()))
    {
        string p_name;    
        p_name=this_body()->short();
        tell(({ ob }) ,p_name+"正盯着你看，不知打的什么鬼主意。\n",MSG_INDENT);
    }
}
mixed * query_verb_info()
{
    return ({ 
         ({"STR",""}),
    });
    
}
