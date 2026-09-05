#pragma save_binary
// invitation
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"做客请帖"NOR, ({"home qing tie"}) );
        set_weight(10);
        set("no_drop",1);
		set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
        }
}
