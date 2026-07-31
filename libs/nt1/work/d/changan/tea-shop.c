// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit AREA_ROOM;

void create()
{
        set("short", "茶馆");
        set("long", @LONG
这间茶房是长安的闲人杂聚的场所，里面横七竖八的百放着一些木制
的桌椅。一个说书的老人正在滔滔不绝的讲着什么。一些茶客一边品茶，
一边听书，一边绘声绘色交头接耳，如果你要想打听江湖掌故和谣言，来
这里准没错。
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"south" : __DIR__"qixiang2",
        ]));
        set("objects", ([
        	__DIR__"npc/teawaiter" : 1,
        	__DIR__"npc/laoren" :1,
        ]) );
        set("area/ziyuan", "客源");

        setup();
}
