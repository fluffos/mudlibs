#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( YEL"腰牌"NOR, ({ "yao pai", "pai", "yaopai" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",YEL "这是一块铜制的腰牌，供军中传递信息时作为凭证。\n"NOR);
                set("value",0);
                 }
        setup();
}

void init()
{
        call_out("dest", 2000);
}

void dest()
{
        destruct(this_object());
}
