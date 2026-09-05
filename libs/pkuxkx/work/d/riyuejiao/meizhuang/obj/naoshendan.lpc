//naoshendan 三尸脑神丹
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	call_out("destroying",300);
        add_action("do_eat", "eat");
}

void destroying()
{
	destruct(this_object());
	return;
}

void create()
{
        set_name(HIR "三尸脑神丹" NOR, ({"dan", "naoshen dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗火红色的丹丸。服用之时对身体有补，但一年以后如不服解药则会中毒而死，
且死前行事颠倒，比猪狗尚且不如。\n");
		set("mingjiao",1);
                set("value", 100);

        }
        setup();
}


int do_eat(string arg)
{
	object me=this_player();
	mapping fam;
	int age;
	
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
	fam = this_player()->query("family");
	age = (int)me->query("age");
          if(!fam || fam["family_name"] != "日月神教")  return notify_fail("你不是日月神教弟子，无法食用神丹！\n");
	if (((int) me->query("riyue_drug") == 999 ) 
	|| ((int)me->query("riyue_drug") < age )
	&& (fam["family_name"] == "日月神教" ))
	{
	        me->add("max_jingli", 50);
        	message_vision(HIG "$N吃下一颗三尸脑神丹，只觉得精神一振！\n" NOR, me);
		me->set("riyue_drug",age);
		me->delete("attitude");
	}
	else if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教" )
		{
			if ((int)me->query("max_jingli") > 50)
				{ me->add("max_jingli",-50);}
			else me->set("max_jingli",0);
        		message_vision(HIR "$N吃下一颗三尸脑神丹，只觉肝肠寸断，当即毒发身亡 !\n" NOR, me);
             me->delete("attitude");
            me->receive_damage("qi", 0, "三尸脑神丹毒发");
			me->die();
		}
		else {	if ((int)me->query("max_jingli") > 100)
				{ me->add("max_jingli",-100); }
			else me->set("max_jingli",0);
	        	message_vision(HIR "$N又吃下一颗三尸脑神丹，只觉腹如刀绞，原来是吃得太多，毒性提前发作了 !\n" NOR, me);
            me->receive_damage("qi", 0, "三尸脑神丹毒性提前发作");
			me->die();
		     }
	destruct(this_object());
	return 1;			
}
