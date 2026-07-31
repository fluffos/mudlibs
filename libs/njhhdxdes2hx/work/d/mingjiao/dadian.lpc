#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "明教大殿");
        set("long", "这里是光明顶大殿，是明教会客的地点。\n");
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"houhuayuan1",
 ]));
        set("objects", ([
                CLASS_D("mingjiao") + "/zhang" : 1,
 ]));
        setup();
        "/obj/board/mingjiao_b"->foo();
	replace_program(ROOM);

}


