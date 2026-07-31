// zhou.c
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

void create()
{
        set_name("腊八粥", ({ "zhou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "碗");
                set("long", "这是一碗珍贵的补品腊八粥。\n");
                set("value", 20000);
        }
        setup();
}

int do_eat(string arg)
{
        int force_limit, neili_limit ;

        object me = this_player();

        force_limit = me->query_skill("force",1)*10;
        neili_limit = me->query("max_neili");

        if (!id(arg)||(arg!="gao"&&arg!="zhou"))
        return notify_fail("你要吃什么？\n");

        if ( neili_limit <= force_limit  )
        {
             me->add("max_neili",random(50));
             me->add("neili",25-random(50));

message_vision(HIY "$N吃下一碗腊八粥，顿然间只觉一股热气直沁心肺...\n" NOR, this_player());
        }
        else
message_vision(HIY "$N吃下一碗腊八粥，但是好象没什么用...\n" NOR,this_player());

        destruct(this_object());
        return 1;
}

