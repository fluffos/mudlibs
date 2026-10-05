#include <ansi.h>

inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"金色鲤鱼"NOR, ({"gloden fish", "fish","yu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "尾");
                set("long", "这是一尾极为罕见的金色鲤鱼。\n");
                set("value", 20000);
        }
        setup();
}

int do_eat(string arg)
{
        int force_limit, neili_limit ;

        object me = this_player();

        force_limit = me->query_skill("force")*10;
        neili_limit = me->query("max_neili");
        
        if (!id(arg)||(arg!="fish"&&arg!="golden fish"))
        return notify_fail("你要吃什么？\n");

        if ( neili_limit <= force_limit  )
        {
              me->add("max_neili",2);
              me->add("neili",2);

                message_vision(HIY "$N吃下一尾金色鲤鱼，感到满口生津。.\n" NOR, this_player());
        }
        else
                message_vision(HIY "$N吃下一尾金色鲤鱼，但是好象没什么用.\n" NOR, this_player());

        destruct(this_object());
        return 1;
}

