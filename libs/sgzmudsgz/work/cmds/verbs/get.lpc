//**************************************************************************
// Updated by stefan on 10 Jan 1997 and fire on Dec 12 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** get.c
**
*/
#include <mudlib.h>
#include <move.h>
#include <setbit.h>
#include <verb.h>
inherit VERB_OB;
void my_get_wrd_obj(string amount, object o);
// no multiple object support yet 
mixed can_get_str(string str)
{
	mixed ret;
	object* objs=all_inventory(environment(this_body()));
	if(str=="all")
	{	if(sizeof(objs)<=1) return "周围没什么好拿的。\n";
		return 1;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(!ret) return "你要拿什么？\n";
	return 1;
}
void my_get(object ob)
{
    mixed tmp = ob->get();
    if (!tmp) tmp = "你不能拿这样东西。\n";
    if (stringp(tmp)) {
        write(tmp);
        return ;
    }
    if(ob->query_is_money())
    {  	this_body()->simple_action("$N拾起"+"$o。\n",ob);
	    tmp = ob->move(this_body()); // 钱一定能检起来
		return;
	}
    if(ob->is_mergeable())
    {
        string t="$N拾起"+ob->short();
        tmp=ob->move(this_body());
        if(tmp==MOVE_OK)
        {
		   this_body()->simple_action(t);
           ob->set_flag(TOUCHED);
        }
        return;
    }
    tmp = ob->move(this_body());
    if (tmp == MOVE_OK)
	{
       this_body()->simple_action("$N拾起一"+ob->query_unit()+"$o。\n",ob);
       ob->set_flag(TOUCHED);
	   return;
	}
    if (tmp == MOVE_NO_ERROR)
    {
        return;
    }
    if (tmp == MOVE_NO_ROOM) tmp = "你负荷过重了！\n";
    if (!tmp) tmp = "这好象不太可能。\n";
    write(tmp);
}
void do_get_str(string str)
{
	mixed ret;
	object* objs=all_inventory(environment(this_body()))-({this_body()});
    
	if(str=="all")
	{	
		foreach(object o in objs)
		{	if(o->get()==1)
				my_get(o);
		}
		return;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(objectp(ret))
	{
		my_get(ret);
		return;
	}
	my_get_wrd_obj(ret[0],ret[1]);
}

void my_get_wrd_obj(string amount, object o)
{
    string s;
    int number;
    int p_realnum;
    mixed o1;
    if((o->is_mergeable()))
    {
       o1=o->split(amount);
       if(o1==-1)
       {
         printf("你没有那么多%s可拿呀。\n",o->query_chinese_id());
         return;
       }
       if(objectp(o1))
             my_get(o1);       
        return;
    }
	if(o->query_is_money())
	{
		write("钱要拿就全拿。\n");
		return;
	}
	write("奇怪。\n");
	return;
}
void do_get_obj_from_obj(object o1,object o2)
{
	my_get(o1);
}
mixed * query_verb_info()
{
    return 
        ({ 
            ({ "STR","OBJ from OBJ"})
        });
}
