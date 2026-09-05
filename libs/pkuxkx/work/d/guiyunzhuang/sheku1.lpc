// room: sheku1.c

inherit ROOM;

void create()
{
        set("short", "蟒蛇洞");
        set("long", @LONG
这里是蛇窟，到处都是毒蛇，只听得四下里簌簌作响，几条
毒蛇向你扑来，里面雾气腾腾看不太清楚。
LONG);
         set("exits", ([ 
            "east" : __DIR__"sheku",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake3":2,
             __DIR__"npc/snake4":1,
         ]));

        set("no_clean_up", 0);
        set("outdoors", "guiyunzhuang");

        setup();
        replace_program(ROOM);
}

