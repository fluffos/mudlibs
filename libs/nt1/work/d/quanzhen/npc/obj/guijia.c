// guijia.c 乌龟甲
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB"乌龟甲"NOR, ({"gui jia","jia"}));
        set_weight(800);
        set("unit", "块");
        set("long", "这是一块乌龟甲，上面有各种花纹，看来可以入药。\n");
        setup();
}

