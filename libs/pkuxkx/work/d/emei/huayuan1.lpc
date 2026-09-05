// Room: /d/emei/huayuan1.c 峨嵋派 花园

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long",
"从后院往西走就到了这里，这是一个大花园，长满了\n"
"各种奇花异草。四周就是弟子们的寝房了，所以虽然有弟\n"
"子不断进进出出，但还是很安静。\n"
        );

        set("exits", ([
		"north" : __DIR__"room1",
                "south" : __DIR__"room3",
		"east" : __DIR__"houyuan",
		"west" : __DIR__"room2",
               ]));
        setup();
        replace_program(ROOM);
}
