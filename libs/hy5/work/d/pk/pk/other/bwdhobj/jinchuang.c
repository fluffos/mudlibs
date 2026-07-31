// jinchuang.c 金创药
#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("金创药", ({"jinchuang yao", "jin", "jinchuang", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 3000);
                    set("heal_up", 1);
               set("heal_up", 1);
               set("medicine", "drug");
                set("unit", "些");
                set("long", "这是武林人士必备的金创药。\n");
                set("base_value", 5000);
                set("base_unit", "包");
                set("base_weight", 30);
        }
        set_amount(1);
}

int do_eat(string arg)
{
   object me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("你现在不需要用金创药。\n");
        else {
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N此药 为比赛专用，药被没收了！\n\n" NOR,
                       me);
	destruct(this_object());   
       return 1;       
}

                this_player()->add("eff_qi", 100);
                message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player());
                add_amount(-1);
                return 1;
        }
}
