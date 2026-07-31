// Room: /d/jingzhou/jznanmen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "荆州南门" );
        set("long", @LONG
你来到荆州的南门，荆州历来都是军事要地，因此城墙坚实无比，城
楼高高耸立，由此向南，是去云南的路，不过那边山高路远，很不好走，
你可得多多注意一些。

LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
]));

        set("exits", ([
  
  "north" :__DIR__"nandajie2",
  "south" :__DIR__"nanshilu",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

