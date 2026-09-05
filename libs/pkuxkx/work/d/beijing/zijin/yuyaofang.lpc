// Room: /d/beijing/zijin/yuyaofang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"御药房"NOR);
	set("long",
HIC"这是禁城中的御药房，存放了大量珍贵药材．满屋药香扑鼻而来，几个
药罐正嘟嘟冒泡，旁边几个小太监在轻轻扇着金香炉。几位太医正在争论着
什么，不知道是否是皇上龙体欠安。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"sikongchu",
  	"north" : __DIR__"rijingmen",
]));
        set("objects",([
                "/d/beijing/npc/obj/yuchandan" : 1 + random(2),
        ]));

	setup();
	replace_program(ROOM);
}
