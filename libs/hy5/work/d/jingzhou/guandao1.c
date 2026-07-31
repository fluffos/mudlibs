// Room: /d/jingzhou/guandao1.c
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "官道" );
        set("long", @LONG
你走在一条大官道上，两旁不时有人从你身边走过，西面通向
荆州，东边是一条小路。
LONG
        );
        set("exits", ([
  "east" : __DIR__"road7",
  "west" : __DIR__"guandao2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

