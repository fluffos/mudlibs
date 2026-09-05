
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("倚天屠龙记", ({"yitiantulong ji", "ji"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一本金装本的金庸签名的倚天屠龙记。\n");
                set("unit", "本");
                set("value", 10);
                set("material", "paper");
        }
        setup();
}


