// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit AREA_ROOM;

void create()
{
        set("short", "望星楼二楼");
        set("long", @LONG
二楼是酒楼的雅座。在这里的客人们都低言慢语，不象楼下的客人那
般狂呼豪饮。二楼卖的酒菜也是望星楼掌厨最拿手的。两旁挂着长联直贯
屋角：君即饮此觞，对酒高歌，人醉楼头，待刘伶同乐；余亦醺一梦，临
风把盏，云横江上，与王粲销愁。
LONG );

        set("exits", ([
        	"down" : __DIR__"jiulou",
        ]));
        set("objects", ([
        	__DIR__"npc/yang-laoban" : 1,
        ]));

        set("area/ziyuan", "人口");
        setup();
}
