//yupei.c
//by dwolf         

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( YEL"玉佩"NOR, ({ "yupei" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
		set("long", MAG"这是田七爷给女儿田思思的信物，上面有些字。"NOR);
                set("value", 30000);
        }
        setup();
}
