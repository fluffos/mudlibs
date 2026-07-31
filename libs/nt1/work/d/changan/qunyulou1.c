// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit AREA_ROOM;

void create()
{
        set("short", "群玉楼大厅");
        set("long", @LONG
群玉楼大厅。三面都糊着纱窗，窗棂纵横交错，分成大小格式的花纹，
每一格都有一方小玻璃镶嵌着，显得甚为雅致，玻璃内灯光流映生辉，案
头所供养的梅花，疏影横斜，也贴在玻璃窗上。炫目的朝阳从琉璃窗格透
入，微风轻拂，缕缕幽香，沁人心脾。
LONG );
        set("exits", ([ /* sizeof() == 2 */
        	"north" : __DIR__"qunyulou",
        	"up"   : __DIR__"qunyulou2",
        ]));
        set("objects", ([
        	__DIR__"npc/lingfeixue" : 1,
        ]) );
        set("area/ziyuan", "美女");

	setup();
}
