// jinchuang.c 八龙神魔丹

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "八龙神魔丹" NOR, ({"bmsd danMR"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是贯通奇经八脉的无上至宝。\n");
                set("tianji1", 999999);
		    set("no_get", 1);
		    set("no_give", 1);
		    set("no_sell", 1);
		    set("no_steal", 1);

                set("no_sell", 1);set("value", 200);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{    
   int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat 八龙神魔丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

 CHANNEL_D->do_channel(this_object(), "rumor", "恭喜" + me->name() + "打通了"HIR"全身大小周天经脉"HIM",功力已如神人。。\n");

                effect++;
                write(HIM "你觉得自己的头脑更清醒了。"NOR"\n");
                me->set("meridian/手三阳经", 0);
				me->set("meridian/手三阴经", 0);
				me->set("meridian/阴维脉", 0);
				me->set("meridian/阳维脉", 0);
				me->set("meridian/阳跷脉", 0);
				me->set("meridian/阴跷脉", 0);
				me->set("meridian/冲脉", 0);
				me->set("meridian/带脉", 0);
               
				me->add("gain/break", 10000);
				me->add("gain/armor", 10000);
				me->add("gain/2dp", 99999);
				me->add("gain/2ap", 99999);
				me->add("gain/attack", 99999);
				me->add("gain/defense", 99999);
				me->add("gain/damage", 99999);
				me->add("gain/max_qi", 99999);
                write("\n "+HIR+"恭喜你："+NOR+HIG+"服用八龙神魔丹，奇经八脉步入天人之境！！！ "+NOR);
        
		
		if(me->query("meridian/冲脉") >=0
		&& me->query("meridian/带脉") >=0
		&& me->query("meridian/阳维脉") >=0
		&& me->query("meridian/阴维脉") >=0
		&& me->query("meridian/阳跷脉") >=0
		&& me->query("meridian/阴跷脉") >=0
		&& me->query("meridian/手三阴经") >=0
		&& me->query("meridian/手三阳经") >=0)
	{
		me->add("max_neili", 999999);
		me->add("max_qi", 999999);
		me->add("gain/2ap", 99999);
		me->add("gain/2dp", 99999);
		tell_object(me,HIG"恭喜你！成功打通8条经脉，一时间只觉全身真气行走全身，生生不息。"NOR"\n");
		message_vision(HIY"$N长啸一声，啸声清越激昂，连绵不绝！！！"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}