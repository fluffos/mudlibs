// apply.c 苹果

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"蛋糕"NOR, ({ "cake"}) );
        set("no_give", 1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是一小块奶油蛋糕，蛋糕上写着：Marry Chirstmas！
白皙的奶油散发出阵阵诱人的香味，让你忍不住想吃(eat)一口。
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
        if( arg == "cake" || arg == "蛋糕"){	

	message_vision("$N拿起一个$n，狼吞虎咽的猛咬了几口。\n",me,ob);
	me->add("food",40);
	me->add("water",40);;
	me->add("str",1);
	me->add("dex",1);
	tell_object(me,HIC"你的身法和膂力都增加了一点。\n"NOR);
	destruct(ob);
	}
	return 1;
}