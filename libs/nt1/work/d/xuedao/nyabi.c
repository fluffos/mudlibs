// nyabi.c

inherit ROOM;
void create()
{
        set("short","北崖壁");
        set("long",@long
这里是一处陡峭的崖壁，地上到处是被踩得黑乎乎的积雪。零零落
落的有几个血刀弟子在练功。
long );
        set("exits",([
                "south" : __DIR__"shandong2",
        ]));
        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));
        set("outdoors", "xueshan");
        setup();
        replace_program(ROOM);
}
