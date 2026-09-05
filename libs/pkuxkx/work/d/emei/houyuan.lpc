// Room: /d/emei/houyuan.c 峨嵋派 后园

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后园");
        set("long",
"这里是千佛庵的后园，这是一个极为宽阔的大院子，\n"
"左右两边各有一个庭院，西边的庭院是弟子们的寝房，东\n"
"边的庭院是俗家弟子的寝房。\n"
        );

        set("exits", ([
		"north" : __DIR__"houmen",
                "south" : __DIR__"shendeng",
		"west" : __DIR__"huayuan1",
               ]));
        set("objects", ([
          __DIR__"houshan/npc/nigu" : 1,  
             ]));
        setup();
        replace_program(ROOM);
}
