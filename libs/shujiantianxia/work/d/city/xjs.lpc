// /d/city/xjs.c 小金山
// this is made by beyond update 1997.7.5
// Lklv modified at 2002.1.23 天地会分堂

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"小金山"NOR);
	set("long",@long
小金山原名为长春岭，四面环水，山和园林都在湖心的小岛上，山顶筑，
风亭山上植松柏。山东麓墙内有小桂花厅，与之相连的还有一座朝东的花厅，
内有对联一幅：“月来满地水，云起一天山。”
long);
	set("exits",([
		"west" : __DIR__"dhq",
	]));
        set("objects", ([
                NPC_D("tdh/lishikai"): 1,
        ]));
	set("outdoors", "扬州");
	setup();
}
