//04zq_gift.c  by Yom 2004-9-28 0:27
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("愿望",({"04wish"}));
	set("long","你希望能得到什么呢(wish)?\n");
	set("unit","个");
	set("value",1);
	set("weight",1000000);
	
	set("no_give",1);
	set("no_drop",1);
	set("no_store",1);
	
	setup();
}

void init()
{
    add_action("do_wish","wish");
}

int do_wish(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("别乱来，嗯，这样不太好吧？\n");
    if( arg == "04wish" ) 
    {
		if ( (int)me->query("04zq_gift" ) > 0 ) 
			return notify_fail("你的心情我理解，可是，sigh，你还是忍忍吧!\n");
		
		message_vision(HIG"\n$N虔诚地念念有词，突然如有所获，欣喜之情溢于言表，难道天上真的有神仙？\n"NOR,me);
		
		write("你突然感觉精神一振，过节就是开心啊～\n");
		
		switch( rand(10) )
		{
			case 0:
				me->add("max_neili",50);
				write("你的最大内力增加了!\n");
				break;
			case 1:
				me->add("max_jingli",50);
				write("你的最大精力增加了!\n");
				break;
			case 2:
				me->add("max_qi",50);
				write("你最大气增加了!\n");
				break;
			case 3:
				me->add("max_jing",50);
				write("你最大精增加了!\n");
				break;
			case 4:
				me->add("str",2+rand(2));
				write("你的臂力增加了!\n");
				break;
			case 5:
				me->add("int",2+rand(2));
				write("你的悟性增加了!\n");
				break;
			case 6:
				me->add("con",2+rand(2));
				write("你的根骨增加了!\n");
				break;
			case 7:
				me->add("dex",2+rand(2));
				write("你的敏捷增加了!\n");
				break;
			case 8:
				me->add("per",3);
				write("你的容貌增加了!\n");
				break;
			case 9:
				me->add("kar",3);
				write("你的福缘增加了!\n");
				break;
		}
		
		me->set("04zq_gift",1);
		destruct(this_object());
     }
     return 1;
}