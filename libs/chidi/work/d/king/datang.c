// Room: /city/dating.c    by king
inherit ROOM;
void create()
{
        set("short", "风啸楼大厅");
        set("long", @LONG
  这里有是风啸楼的大堂，进入这里，你就感到一阵暖思，原来
这里有人在练神功，你看见墙上的绝学(juexue)忙过去看。
LONG
        );
        set("item_desc", ([
                "juexue": "风啸楼剑法，暗器和斧法，枪法很厉害。\n",
        ]));
        set("exits", ([
                "south" : __DIR__"damen",
//                "enter" : __DIR__"liansword",
                "east" : __DIR__"xingtang",
                "west" : __DIR__"tianwei",
                "north" : __DIR__"jinglei",
        ]));
        set("objects", ([
        __DIR__"npc/king" : 1,
]));
        setup(); 
        replace_program(ROOM);
}

