#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	object me;
	me=environment(this_object());
	if(!me) 
	{
		remove_call_out("des");
		call_out("des",1,this_object());
		return;
	}
	if(!living(me)&&!query("dis"))
	{
		set("dis",1);
		message_vision(HIW"千年灵丹缺乏人气的维持，落到地上竟化为了灰烬！\n"NOR,this_object());
		remove_call_out("des");
		call_out("des",1,this_object());
		return;
	}
        add_action("do_eat", "eat");
}
int des(object obj)
{
	destruct(obj);
	return 1;
}

int move(string arg)
{
	if(!query("moved"))
	{
		set("moved",1);
		::move(arg);
		return 1;
	}
	remove_call_out("inspect");
	call_out("inspect",1,this_object(),environment(this_object()));
	::move(arg);
	return 1;
}
int inspect(object lingdan,object me)
{
	object room;
	if(!me)
	{
		message_vision(lingdan->query("name")+HIR"缺乏人气的维持，落到地上竟化为了灰烬...\n"NOR,environment(lingdan));
		destruct(lingdan);
		return 1;
	}
/*	room=environment(lingdan);
	if(!living(room))
	{
		message_vision(lingdan->query("name")+HIR"缺乏人气的维持，落到地上竟化为了灰烬...\n"NOR,environment(lingdan));
		destruct(lingdan);
		return 1;
	}
*/
	return 1;
}
void create()
{
        set_name(HIB"千年灵丹"NOR, ({"qiannian lingdan", "qiannian", "lingdan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
				set("no_give",1);
				set("no_get",1);
				set("no_sell",1);
                set("unit", "份");
                set("long", "这是mudy炼的一颗千年灵丹，吃下后会对武功大大促进！\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
	int num,exp;	
	mapping skills;
	object me=this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
		if(me!=environment(this_object()))
			return 1;
	if(me->query("mudyxmas/lingdan"))
	{
        message_vision(HIG "$N吃下一颗千年灵丹，脸上泛出一层淡淡的红色！\n" NOR, me);
		num=me->query("mudyxmas/lingdan");
		exp=10000/num;
		if(exp<100) exp=100;
		me->add("combat_exp",exp);
		tell_object(me,"你感到你的经验有所增加！\n");
		me->add("mudyxmas/lingdan",1);
		destruct(this_object());
		return 1;
	}
	me->add("mudyxmas/lingdan",1);
        skills=me->query_skills();
        if(mapp(skills))
        {
        	string *skname;
                skname=keys(skills);
                for(int i=0;i<sizeof(skills);i++)
				{
                        skills[skname[i]]++;
				tell_object(me,HIC"你的［"+to_chinese(skname[i])+"］进步了!\n"NOR);
				}
        }
        message_vision(HIG "$N吃下一颗千年灵丹，脸上泛出一层淡淡的红色！\n" NOR, me);
		tell_object(me,HIW"你吃下一颗千年灵丹之后觉得个方面的武功都有所进步！\n"NOR);

       	destruct(this_object());
       	return 1;
}
