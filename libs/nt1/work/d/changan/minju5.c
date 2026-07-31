// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set("long", @LONG
房间里甚是宽敞，里面摆设朴素而自然，左侧是一个古色古色的精雅
梳妆台，前面摆有两张红木圆椅。右侧墙壁上挂有一幅美女抚琴图，上面
配有几行笔迹清秀的隶体小字，内侧则是一张红色帐幔垂挂的低矮木榻。
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : __DIR__"huarui5",
        ]));

        setup();
        replace_program(ROOM);
}
