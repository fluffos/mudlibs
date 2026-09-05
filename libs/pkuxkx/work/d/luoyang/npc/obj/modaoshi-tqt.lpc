inherit ITEM;
#include "modaoshi.h"
#include <ansi.h>
void create()
{
        
        set_name(HIR"磨刀石"NOR, ({"modao shi", "shi", "stone" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "最高级别的磨刀石，据说一次能恢复十点武器耐久度。\n");
                set("unit", "块");
                set("value", 200);
                set("point", 10); //恢复永久耐久的点数
               
        }
}

void init()
{	
	add_action("do_mo", ({ "mo", }));
}

int do_mo(string arg)
{
    return modao(arg);

}