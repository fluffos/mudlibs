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
        set_name("人参果", ({"renshen guo", "renshen", "guo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", GRN"东北特产  滋补佳品\n"NOR);
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
 
 //       me->add("max_jingl",50);
 //       me->add("potential",50);
 //       me->add("mud_age",86200);
  //      me->add("max_qi",100);
       
 //       me->add("shen",10000);


message_vision(HIY"$N吃下一颗人参果，心中说不出的舒服 !\n" NOR, me)
;
        destruct(this_object());
        return 1;
}
