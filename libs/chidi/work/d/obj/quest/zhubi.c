inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name("÷Ï± ", ({"Zhu bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "’‚ø… «±¶±¥∞°°£\n");
                set("unit", "÷ª");
               set("owner_name","÷Ïµ§≥º");
               set("owner_id","zhu danchen");
        }
}
