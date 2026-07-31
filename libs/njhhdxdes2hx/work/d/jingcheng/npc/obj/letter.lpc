//letter.c
//by dwolf
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( YEL"家信"NOR, ({ "letter", "xin" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
		set("long",
	MAG"这是秦歌给女儿玉儿的信，上面有些字。"NOR);
                set("value", 30);
                set("material", "paper");
        }
        setup();
}
