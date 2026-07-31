//nezhamiao.c  by meteor

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short","哪吒行宫");
        set("long", @LONG
哪吒行宫中香火鼎盛，当中一座八尺哪吒像(xiang) 三首八臂法
身，分别持火尖枪，乾坤圈，混天绫，九龙神火罩，阴阳剑，威风凛
凛。旁边分别塑着一个跪着的小鬼，双手托盘(pan) ，高举过头，里
面放着来参拜祈福的善男信女们捐出的银钱。正中一个锦缎缝制的蒲
团(putuan)虽然很旧，但依然干净。
LONG );
        set("exits",([
                "north" : "/u/meteor/workroom",
        ]));
        set("item_desc", ([
                "xiang"  : "威武的哪吒立像，背后还有一朵很大的莲花衬托，但是你觉得很奇怪
的是，哪吒的风火轮并没有在塑像的脚下。\n",
                "pan"    : "盘中散落着一些银钱，你大概算了一下，也有几十两银子。\n",
                "putuan" : "一个锦缎缝制的蒲团，中间有少许凹陷，看来是经常有人在这里跪拜(kneel)。\n"
        ]));

        setup();
}


