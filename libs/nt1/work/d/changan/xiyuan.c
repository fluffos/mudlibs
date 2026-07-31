// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit AREA_ROOM;

void create ()
{
        set ("short", "戏院");
        set("long", @LONG
这里屋深幽暗，屋子西端搭有一座精巧但已有点退色的戏台。戏台两
边挂有数盏明亮的灯笼。前几排有些矮凳，后面是一些红油茶桌和宽背扶
手椅。
LONG );
        set("exits", ([
        	"south" : __DIR__"liande-beikou",
        ]));
        set("objects", ([
        	__DIR__"npc/xizi" : 1,
        ]));

        set("area/ziyuan", "戏曲");
        setup();
}


