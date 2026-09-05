#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( YEL"黑木令"NOR, ({ "heimu ling", "ling" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",YEL "这是块枯焦的黑色木头，长约半尺，上面雕刻有花纹文字。\n"NOR);
		set("material","wood");
		set("mingjiao",1);
                set("no_give",1);
                set("no_drop",1);
                set("value",1);
                set("no_sell",1);
                 }
        setup();
}


