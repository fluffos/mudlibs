// chocolate.c 巧克力

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"巧克力"NOR, ({ "chocolate"}) );
        set("no_give", 1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是一颗德国出产的巧克力，香喷喷的，让你口水直流。
TEXT
                );
                
                set("unit", "颗");
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
        
        if(!arg||arg=="")
        	return notify_fail("什么？\n");
        if( arg == "chocolate" || arg == "巧克力")
{	
	message_vision("$N慢慢的剥开糖纸，把$n一口吞了下去。\n",me,ob);
	me->add("potential", 500);
        tell_object(me,HIW"你的潜能增加了" + chinese_number( 500 ) + "点！\n"NOR);
        me->add("combat_exp", 2000);
        tell_object(me,HIW"你的经验增加了" + chinese_number( 2000 ) + "点！\n"NOR);
	me->add("score",1000);
	tell_object(me,HIW"你的江湖威望增加了"+ chinese_number(1000) + "点！\n"NOR);
	destruct(ob);
	}	
	return 1;
}