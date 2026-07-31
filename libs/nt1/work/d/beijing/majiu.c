// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short","马厩");
        set("long", @LONG
这是北京城的马厩，常年供应新鲜草料。北京自古天子脚下，啥都有
规矩，客店也特会伺候人，马夫们会把马牵到马厩好生照看，将它们喂饱
饮足，再洗刷得干乾净净，一直伺候到客人上路。马厩雨檐下的烂木柱上
钉着一块破木牌(paizi)。马厩中堆放著几堆草料，正中有一口泔槽。
LONG );
        set("outdoors", "beijing");
        set("no_fight", 1);
        set("no_beg", 1);
        set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
        ]));
        set("item_desc", ([
                "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往            扬  州  城:  rideyz
                赫图阿拉城:  rideht


TEXT]));
        set("exits",([ /* sizeof() == 1 */
                "east"      : __DIR__"niaoshi",
        ]));
        set("no_clean_up", 0);
        setup();
        
        // replace_program(ROOM);
}
