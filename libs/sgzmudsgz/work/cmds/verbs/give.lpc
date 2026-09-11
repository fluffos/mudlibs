/* Do not remove the headers from this file! see /USAGE for more info. */
// Updated by tset on 14 Oct 1998 -- fixed that famous give to yourself bug
/*
** give.c
**
*/
//ok
#include <mudlib.h>
#include <verb.h>
#include <move.h>
inherit VERB_OB;
inherit CHINESE_DA;
void do_give_obj_to_liv(object ob, object liv);
void my_give_num_obj_to_liv(int amount, object o, object who);

mixed can_give_str_to_str(string str,string str2)
{
	mixed ret;
	object o;
	object* objs=all_inventory(this_body());
	o=ENV_OB(str2);
	if(!objectp(o))
	{
		write("找不到"+str+"。\n");
		return;
	}
	if(!o->is_living())
	{
		write(o->short()+"好象不是人。\n");
		return;
	}
	if(str=="all")
	{	if(!sizeof(objs)) return "你没什么好给的。\n";
		return 1;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(!ret) return "你要给什么？\n";
	return 1;

}
void do_give_str_to_str(string str,string str2)
{
	mixed ret;
	object liv;
	object* objs=all_inventory(this_body());
	liv=ENV_OB(str2);
	if(str=="all")
	{	
		foreach(object o in objs)
			do_give_obj_to_liv(o,liv);
		return;
	}
	ret=PARASE_D->retrieve_num_object( str, objs);
	if(objectp(ret))
	{
		do_give_obj_to_liv(ret,liv);
		return;
	}
	my_give_num_obj_to_liv(ret[0],ret[1],liv);

}

void do_give_obj_to_liv(object ob, object liv) {
	mixed tmp;
    mixed ret=liv->indirect_give_obj_to_liv(ob, liv);
    if(stringp(ret)) {write(ret);return;}
	ret=ob->query_can_give();
	if(!ret) ret=ob->short()+"不能乱给人。\n";
	if(stringp(ret))
	{
		write(ret);return;
	}
    if(ob->query_is_money())
    {
        write("钱给出去可就没有了。\n");
        destruct(ob);
        return;
    }
    if ( this_body() == liv ) {
	write("自己给自己东西？\n");
	return;
    }
    //### Need to check the return value
    ob->move(liv);
    tmp = ob->move(liv);
    if (tmp == MOVE_OK) 
    {
        if(ob)
			this_body()->targetted_action("$N把$o交给$T。\n", liv, ob);
		else
			printf("OK\n");
    } 
    else
    write(tmp);
}

void my_give_num_obj_to_liv(int amount, object o, object who)
{
    string s;
    mixed o1;
    if ( this_body() == who ) {
        write("自己给自己东西？\n");
        return;
    }
    if((o->is_mergeable()))
    {
       o1=o->split(amount);
       if(o1==-1)
       {
         printf("你没有那么多%s可给呀。\n",o->query_chinese_id());
         return;
       }

       if(objectp(o1)){
	if(o1->query_is_money())
	{	
		if(!who->query_accept_money())
		{   write  ("钱给出去就没了。\n");
			destruct(o1);
			return;
		}
		else
		{
			this_body()->targetted_action("$N给$T"+chinese_number(amount)+
				o1->query_unit()+"$o。\n",who,o1);
			who->receive_money(this_body(), amount, o1->query_id()[0]);
			destruct(o1); // money never really give
			return;
		}

	}
	do_give_obj_to_liv(o1, who);
	return;
	}

    }
    write("奇怪。\n");
}

mixed * query_verb_info()
{
    return ({ ({ "STR to STR" }) });
}
