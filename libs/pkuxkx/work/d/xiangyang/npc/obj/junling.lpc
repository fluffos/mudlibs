
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( YEL"襄阳军令"NOR, ({ "jun ling", "ling", "junling" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long",YEL "这是一金皮大令，军中调兵谴将，全靠它了。\n"NOR);
                set("value", 0);
                 }
        setup();
}

void init()
{
        call_out("dest", 1800);
}

void dest()
{
        destruct(this_object());
}
