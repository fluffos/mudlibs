// apply.c 苹果

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG"苹果"NOR, ({ "apple"}) );
        set("no_give", 1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是一个又青又绿的大苹果，让你忍不住想咬(eat)一口。
TEXT
);
	set("unit", "个");
	set("base_weight", 500);
	set("value", 0 );

}

        setup();
}
void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me,ob;
 	me = this_player();
 	ob = this_object();
        
        if(!arg || arg=="")
        	return notify_fail("什么？\n");
        if( arg == "apple" || arg == "苹果"){	

	message_vision("$N拿起一个$n，狼吞虎咽的吞了下去。\n",me,ob);
	me->add("food",40);
	me->add("water",40);
	me->add("max_neili",100 + random(100));
	me->set("neili",me->query("max_neili"));
	me->add("con",1);
	me->add("kar",1);
	tell_object(me,HIC"你的体质和运气都增加了一点，内力也提高了！\n"NOR);
	destruct(ob);
	}
	return 1;
}