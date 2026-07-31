inherit ROOM;

void create()
{
        set("short", "汴梁南街");
        set("long",
"这里是南大街了，西边是一家店铺，墙上写着一个大大的“当”字，\n"
"仔细倾听，可以听到压低的讨价还价的声音，东边是一家钱庄，不时传来\n"
"钱两银锭的叮当声。\n"
);
        set("outdoors", "bianliang");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"nandajie2",
                "south" : __DIR__"chengmen",
        ]));  
        set("objects", ([
//                "/d/shaolin/npc/tiao-fu" : 1,
//                "/d/city2/npc/xiaofan" : 1,
        ]));

        setup();
  }
