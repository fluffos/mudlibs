inherit ITEM;
#include "modaoshi.h"
#include <ansi.h>
void create()
{
        string* color=({RED,YEL,BLU,GRN});
        set_name(color[random(sizeof(color))]+"磨刀石"NOR, ({"modao shi", "shi", "stone" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块普普通通的磨刀石，不知道有啥用处。\n");
                set("unit", "块");
                set("value", 200);
                set("point", 2); //恢复永久耐久的点数
               
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