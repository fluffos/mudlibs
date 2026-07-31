// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create ()
{
        set ("short", "麒祥街");
        set("long", @LONG
麒祥街是长安城北一条东西向的大道，街面宽敞洁净，街上十分热闹，
人来人往川流不息。大街的两旁商家云集，大大小小的店铺比邻而立。街
的北边有一座酒楼，对面是一家客栈。
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"kezhan",
        	"north" : __DIR__"jiulou",
        	"west" : __DIR__"yongtai-beikou",
        	"east" : __DIR__"qixiang2",
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
