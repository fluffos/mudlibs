// gao.c 龟苓膏
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"龟苓膏"NOR, ({"guiling gao","gao"}));
        set_weight(3000);
        set("unit", "块");
        set("long", "这是一块用乌龟甲和茯苓配置成的龟苓膏，功能延年益寿。\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="gao")
        {
                if ((int)me->query("max_jingli")<=300) {
                        write(YEL"你吃下了一块龟苓膏，只觉得精神健旺之极，精力直
欲奔腾而出。\n"NOR);
                        me->add("max_jingli",20);
                        me->add("jingli",20);
                }
                else {
                        write("你吃下了一块龟苓膏，但是好象没什么用。\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
