// room: /d/quanzhou/sheku.c
// Eric 96.9.26

inherit ROOM;

void create()
{
        set("short", "蛇窟");
        set("long", @LONG
这里是蛇窟，到处都是金色的毒蛇，只听得四下里簌簌作响，几条
毒蛇向你扑来，北面雾气腾腾看不太清楚。
这儿唯一的出口是东面。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"wuminggudi",
        ]));
        set("objects", ([ 
            __DIR__"npc/snake" : 5,
         ]) );

        set("no_clean_up", 0);
        set("outdoors", "quanzhou");

        setup();
        replace_program(ROOM);
}

