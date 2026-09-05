
#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("情报",({ "qing bao", "paper"}) );
        set("long","这是一份情报，是江北的丐帮弟子用生命换来的。\n");
        set_weight(4000);
        set("gb_newbie_is_qingbao",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "份");
                set("value", 0);            
			}
        setup();
}

