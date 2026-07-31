// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit AREA_ROOM;

void create ()
{
        set ("short", "珠宝行");
        set("long", @LONG
珠宝行中珠光宝气四射，眩的人有些睁不开眼睛。精致的长柜中陈设
着各类首饰珠宝玉器，几个老行家正陪着客人挑选所需珠宝。一个雕花木
架上摆着颗三尺多高的玉树，珍贵之外又透着淡雅秀丽，曲折含蓄之气。
LONG );
        set("exits", ([
        	"south" : __DIR__"yongtai-beikou",
        ]));
        set("objects", ([
        	__DIR__"npc/jinfuhuan"  : 1,
        ]));
        set("area/ziyuan", "珠宝");

        setup();
}
