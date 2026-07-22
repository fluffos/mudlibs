// guandao1.c 官道
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条大道，西面通往武功镇。道上的行人很多，大多是低着头
自己赶自己的路。忽然在你的身后响起得得的马蹄声，不一会儿，几匹
骏马从你身边飞驰而过，掠起了一片黄沙。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : __DIR__"daguandao",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


