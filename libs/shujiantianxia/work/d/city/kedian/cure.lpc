#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "十香软筋散解药" NOR, ({"shixiang ruanjinsan cure", "cure"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 1);
                set("unit", "小包");
        }
       setup();
}

void init()
{ 
        add_action("do_fu","fu");
}

int do_fu(string arg)
{
        object me, ob;
        me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("帮谁解毒呢？\n");
        
        message_vision(HIG"$N把一小包十香软筋散的解药让$n服下了。\n"NOR, me, ob);
        ob->clear_condition("ruanjin_poison");
        destruct(this_object());
        return 1;
}

