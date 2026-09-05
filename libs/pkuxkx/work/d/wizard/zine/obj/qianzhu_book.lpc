// sword_book.cc
inherit F_SAVE;
inherit ITEM;
#define QZWDS "/data/business/qzwds"
string query_save_file()
{
        return QZWDS;
}
#include <ansi.h>
void create()
{
        set_name(WHT"千蛛万毒手精义"NOR, ({ "qianzhu jingyi","jingyi", "book" }));
        set_weight(600);
		set("unit", "本");
		set("long","这本书是关于运用千蛛万毒手的一些技巧，不知何人所著，你可以研究(yanjiu)一下。\n");
		set("value", 1);
		set("material", "paper");
}
void init()
{
	add_action("do_yanjiu", "yue");
	add_action("do_yanjiu", "du");
	add_action("do_yanjiu", "fan");
	add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu()
{
    string msg;
    object me=this_player(),ob=this_object();
	string *owners=({"pkuxkxpkuxkxpkuxkx"}),owner;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
        return 1;
	}
	if (me->query("qianzhu-wandu")>=4)
	{
		tell_object(me,"你已完全领悟了这本书中的技巧。\n");
		message_vision("$N不禁仰天大笑三声：“哈哈，哈哈，哈哈哈！”，随后用内力把"+ob->query("name")+"化为灰烬。\n",me);
		destruct(this_object());
        return 1;
	}
	if (ob->query("owner"))
	{
		owner=ob->query("owner");
		ob->restore();
		if (ob->query("owners"))
		{
			owners=ob->query("owners");
		}
		owners+=({owner});
		ob->delete("owner");
		ob->set("owners",owners);
		ob->save();
	}
	ob->restore();
	if (ob->query("owners"))
	owners=ob->query("owners");
    if (member_array(me->query("id"),owners)==-1)
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query_skill("qianzhu-wandu",1)<10)
    {
        tell_object(me,"你根本不会千蛛万毒手，遑论技巧？\n");
        return 1;
    }
    if (me->query("qianzhu-wandu")<1)
	{
        tell_object(me,"你的基础还没打好，一步登天不太可能。\n");
        return 1;
    }
	if (me->query_skill("qianzhu-wandu",1)<649&&me->query("qianzhu-wandu")>=1)
	{
		tell_object(me,"你的基础还没打好，无法领会下一层的精义。\n");
        return 1;
	}
	if (me->query_skill("qianzhu-wandu",1)<999&&me->query("qianzhu-wandu")>=2)
	{
		tell_object(me,"你的基础还没打好，无法领会下一层的精义。\n");
        return 1;
	}
	if (me->query("jing")<200)
	{
		tell_object(me,"你现在精神不济，无法领会此书中的精义。\n");
        return 1;
	}
	if (me->query("neili")<200)
	{
		tell_object(me,"你现在内力不济，无法领会此书中的精义。\n");
        return 1;
	}
    message_vision(HIB"$N"+HIB+"开始认真研读$n"+HIB+"，开始揣摩千蛛万毒手的使用技巧！\n"NOR, me,this_object());
    me->add("tqt/qzwds/improve_point",1+random(me->query("int")));
	me->add("jing",-100);
	me->add("neili",-100);
	if (me->query("tqt/qzwds/improve_point")>me->query("qianzhu-wandu")*1000)
	{
		me->add("qianzhu-wandu",1);
		me->set("tqt/qzwds/improve_point",0);
		tell_object(me,"你对千蛛万毒手的领悟进入了第"+chinese_number(me->query("qianzhu-wandu"))+"层\n");
	}
    return 1;		
}
