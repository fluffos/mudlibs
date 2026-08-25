// Updated by stefan on 10 Jan 1997 and by fire on Dec 14 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** drop.c
**
*/
#include <mudlib.h>
#include <move.h>
inherit VERB_OB;
void my_drop_wrd_obj(string amount, object o);

mixed can_drop_str(string str)
{
	mixed ret;
	object* objs=all_inventory(this_body());
	if(str=="all")
	{	if(!sizeof(objs)) return "你没什么好扔的。\n";
		return 1;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(!ret) return "你要扔什么？\n";
	return 1;
}
void my_drop(object ob)
{
    mixed tmp=ob->query_can_drop();
    string *obb_idda;
    if(!tmp) tmp=ob->short()+"不能扔。\n";
	if(stringp(tmp))
	{
		write(tmp);return;
	}
    tmp = ob->drop();
    if(ob->query_is_money())
    {
        write("钱丢出去可就没有了。\n");
        destruct(ob);
        return;
    }
    if (!tmp) tmp = "你不能丢这样东西。\n";
    if (stringp(tmp)) {
        write(tmp);
        return ;
    }
    obb_idda=ob->query_id();
    if(ob->is_mergeable())
    {
        this_body()->simple_action("$N丢下"+"$o。\n",ob);
        tmp = ob->move(environment(this_body()));
        return;
    }
    tmp = ob->move(environment(this_body()));
    if (tmp == MOVE_OK) 
    {
        if(ob)
	      	this_body()->simple_action("$N丢下一"+ob->query_unit()+"$o。\n",ob);
		else
			printf("OK\n");
    } 
    else
    write(tmp);

}
void do_drop_str(string str)
{
	mixed ret;
	object* objs=all_inventory(this_body());
	if(str=="all")
	{	
		foreach(object o in objs)
			my_drop(o);
		return;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(objectp(ret))
	{
		my_drop(ret);
		return;
	}
	my_drop_wrd_obj(ret[0],ret[1]);
}

void my_drop_wrd_obj(string amount, object o)
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
         printf("你没有那么多%s可扔呀。\n",o->query_chinese_id());
         return;
       }
       if(objectp(o1))
             my_drop(o1);       
        return;
    }
	if(o->query_is_money())
	{
		write("钱不能乱扔。\n");
		return;
	}
	write("奇怪。\n");
	return;
}
mixed * query_verb_info()
{
 return ({ ({ "STR" }),({"put"}) });
}
