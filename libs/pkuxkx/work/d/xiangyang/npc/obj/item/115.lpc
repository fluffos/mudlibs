// /u/china/renshenguo.c
// --by china--
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
	set_name(GRN"天仙玉露"NOR,({"tianxian yulu","yulu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
		set("long","一棵"GRN"天仙玉露"NOR".\n");
                set("value", 100);
        }
        setup();
}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));   
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("max_jing"));   
        me->set("neili", me->query("max_neili"));
        me->set("food",400);
        me->set("water",400);

	message_vision(HIY"$N吃下一棵"GRN"天仙玉露"NOR",心中说不出的舒服。\n"NOR,me);
;
        destruct(this_object());
        return 1;
}
