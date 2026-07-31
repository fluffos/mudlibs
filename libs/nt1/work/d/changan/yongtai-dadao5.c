// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create ()
{
        set ("short", "永泰大道");
        set("long", @LONG
城内街道，以南北三条并行的大街，和东西的二条主街互相交错而成。
五条大街在这清朗的夜初，却见人来车往，灯火通明，别有一番热闹。其
他小街横巷，则依这些主街交错布置，井然有序。
LONG );
        set("exits",([//sizeof() == 2
        	"south" : __DIR__"yongtai-nankou",
        	"north" : __DIR__"yongtai-dadao4",
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
        
