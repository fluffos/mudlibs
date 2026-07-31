inherit ROOM;
 
void create()
{
        set("short", "圣姑堂");
        set("long",@LONG
这里是黑木崖的圣姑所在地“圣姑堂”。堂上五彩云罗，煞
是漂亮。堂中一位妙龄女子，青衫小袖，明艳不可方物。
LONG );
        set("exits", ([
            "east"   : __DIR__"chitang",
        ]));
        set("objects", ([
            __DIR__"npc/ren" : 1,
            __DIR__"npc/shinu":2,
        ]));       
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
