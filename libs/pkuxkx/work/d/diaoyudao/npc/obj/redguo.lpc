// redguo.c 红果
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
   set_name(HIR"红果"NOR,({"red guo","redguo", "guo"}));
   set_weight(50);
   if(clonep() )
     set_default_object(__FILE__);
   else{
   	set("long","一枚红灿灿的野果，散发出香浓的气味，使你不禁想上去咬一口。\n");
	set("unit","枚");
   	set("value",1000);
       }
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");
		
	message_vision(HIR "$N吃下一枚红果，香甜的滋味使你心情舒畅，精神振奋。\n" NOR, this_player());
        me->add("jing",50);
         me->add("qi",50);
        if ((me->query("jing"))>=(me->query("max_jing"))) me->set("jing",(me->query("max_jing")));
	if ((me -> query("qi"))>=(me -> query("max_qi"))) me->set("qi",  (me->query("max_qi")));
	destruct(this_object());
        return 1;
}
