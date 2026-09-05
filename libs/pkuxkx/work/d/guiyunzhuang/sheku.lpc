// room:sheku.c

inherit ROOM;

void create()
{
        set("short", "蛇窟");
        set("long", @LONG
这里是蛇窟，到处都是毒蛇，只听得四下里簌簌作响，几条
毒蛇向你扑来。
LONG);
        set("exits", ([ 
	    "west" : __DIR__"sheku1",
            "east" : __DIR__"shanlu3",
        ]));
        set("objects", ([ 
            __DIR__"npc/snake" : 1,
	    __DIR__"npc/snake1":1,
	    __DIR__"npc/snake2":1,
 	    __DIR__"npc/snake3":1,
         ]));

        set("no_clean_up", 0);
        set("outdoors", "guiyunzhuang");

        setup();
        replace_program(ROOM);
}

