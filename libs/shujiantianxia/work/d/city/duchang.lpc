// Room: /city/duchang.c

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声，北边是赌「大
小」的房间，西面是赌「牌九」的房间，楼上的拱猪房灯火通明。
LONG
        );

        set("item_desc", ([
                "paizi" : "二楼是拱猪房。\n",
        ]));
        set("exits", ([
                "east" : __DIR__"nandajie3",
       "west" : __DIR__"dating1",
        "south" : __DIR__"gusaifang",
        "up" : __DIR__"duchang2",
        ]));
        set("objects", ([
                  __DIR__"npc/duke" : 2,
        ]));

        set("coor/x",90);
        set("coor/y",-20);
        set("coor/z",0);
        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
        if( me->query("no_quest") && dir != "east" ){
        	return notify_fail("\n");
        }
        return ::valid_leave(me, dir);
}
