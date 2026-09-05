// yelguo.c 黄果
// hongdou 98.10.04

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void init()
{
        add_action("do_eat", "eat");
	add_action("do_bao", "bao");
}

void create()
{
   set_name(HIY"黄果"NOR,({"yellow guo","yelguo", "guo"}));
   set_weight(50);
   if(clonep() )
     set_default_object(__FILE__);
   else{
   	set("long","一枚黄澄澄的野果，果中散发出的清香使你不禁想上去咬一口。\n");
	set("unit","枚");
   	set("value",1000);
       }
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");

        if ( (int)me->query_skill("force")>= 50 )
        {
           me->add("max_jingli", (random(2)));
        }
	message_vision(HIY "$N吃下一枚黄果，顿然间只觉一股辛辣之气直入丹田......\n" NOR, this_player());
	me->add("jing", -20);
	me->add("qi", -10);
        destruct(this_object());
        return 1;
}

int do_bao(string arg)
{
        object me = this_player();
	object hu;
	hu=new("/d/diaoyudao/npc/obj/guohu");
        if (!id(arg)) return notify_fail("你要剥开什么？\n");
	switch(random(5))
	{           
           case 0: tell_object(me,"你剥开果肉，里面的果核太小了，你随手扔到了地上。\n");
                   break;
	   case 1: tell_object(me,"你剥开果肉，里面的果核太小了，你随手扔到了地上。\n");
                   break;
	 default : tell_object(me,HIY "你将黄果的果肉剥开，拿出了里面的果核。\n" NOR);
		   hu->move(me);
		   break;
	}
//        me->unconcious();
        destruct(this_object());
        return 1;
}