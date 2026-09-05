// guohu.c 果核
// hongdou 98.10.04

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
   	set_name(WHT"果核"NOR,({"guo hu","guohu", "hu"}));
	set_weight(50);
	if(clonep() )
     		set_default_object(__FILE__);
   	else{
   	set("long","一枚饱满的黑褐色果核，里面的果仁不知会是什么味道？\n");
	set("unit","枚");
       }
}

int do_eat(string arg)
{
        object me = this_player();
	
        if (!id(arg)) return notify_fail("你要吃什么？\n");

        if ( (int)me->query_skill("force")>= 150 )
        {
	   switch(random(2))
	   {           
                case 0: me->add("max_jingli", (random(3)+3));     
			break;
        	case 1: me->add("max_neili", (random(3)+3));
			break;
	   }
	}
	tell_object(me,HIY"你砸开坚硬的果壳，吞下里面的果仁，只觉浑身躁热......\n"NOR);
	me->add("jing", -((int)((me->query("max_jing"))*3)/4));
	me->add("qi", -((int)((me->query("max_qi"))*3)/4));
        destruct(this_object());
        return 1;
}

//        me->unconcious();
