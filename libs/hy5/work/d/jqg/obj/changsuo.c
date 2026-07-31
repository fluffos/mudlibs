// changsuo.c 树皮索
// By River 99.5.25
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"树皮索"NOR, ({ "shupi suo", "suo" }));
        set_weight(1000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根由枣树皮搓成一条极长的树皮索子。\n");
                set("material", "wood");
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_fu","fu");
}
 
int do_fu(string arg,object obj)
{
       object me = this_player();
       object ob = this_object();
       if(me->is_busy() || me->is_fighting())
               return notify_fail("你正忙着哪！\n");
       if(!arg || arg != "shugan" || ! obj=(present("zao shugan", me)))
               return notify_fail("你准备将树皮索缚在哪里？\n");
       tell_object(me,"你将绳索一端缚在树干中间。\n");       
       me->set_temp("jqg/fu", 1);
       obj->set("long","这是一根枣树的枝干，长约一丈五尺，你已经将绳索一端缚在树干中间了。\n");
       obj->set("jqg/fu", 1);
       destruct(ob);
       return 1;
}
