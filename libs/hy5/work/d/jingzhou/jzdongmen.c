// Room: /d/jingzhou/jzdongmen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "荆州东门" );
        set("long", @LONG
荆州西门，荆州历来都是军事要地，因此城墙坚实无比，城楼高高
耸立，来往的人很多，荆州也是从蜀地进入中原的必经之路，所以各色
人等混杂，你还是小心一点。东去是通往扬州的路。
LONG
        );
        set("outdoors", "jingzhou");
        set("objects", ([
            __DIR__"npc/bing" : 2,
        ]));

        set("exits", ([
  "east" : __DIR__"guandao3",
  "west" : __DIR__"dongdajie2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

