#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"奉先殿"NOR);
	set("long",
HIC"这是皇家供奉祖宗的地方。殿中轻烟缭绕，正中的桌子上摆放着
皇家列祖列宗的灵位。\n"NOR
	);

	set("exits", ([
        "south" : __DIR__"guang4",
	]));

	setup();
	replace_program(ROOM);
}
