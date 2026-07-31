// Room: /d/jingzhou/guandao2.c
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "官道" );
        set("long", @LONG
你走在一条大官道上，两旁不时有人从你身边走过，可以分辩
出有几个是江湖中人。西面隐约可以看见荆州，东边和一条小路相连。
LONG
        );
        set("exits", ([
  "east" : __DIR__"guandao1",
  "west" : __DIR__"guandao3",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

