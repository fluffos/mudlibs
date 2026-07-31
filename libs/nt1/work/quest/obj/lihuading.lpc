#include <ansi.h> 
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "神木王鼎" NOR, ({ "shenmu-wangding"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "个");
            set("long","这是一个七寸长，三寸厚的木鼎，上面刻满了钟鼎文\n");
            set("material", "silver");
        }
        setup();
}

