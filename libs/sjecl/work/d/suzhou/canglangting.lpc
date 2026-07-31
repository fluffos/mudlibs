inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC"沧浪亭"NOR);
	set("long", @LONG
仓浪亭在苏州的北大街南侧，因为环境相对幽雅，使得男女老少都喜爱
在这里闲庭散步。在亭中放眼望去，四周一片碧绿的草坪，亭子翼然于耸翠
之中，飞檐凌空琵琶形牌科，布满檐口四周，亭上的额匾和石柱上的楹联(lian)
使人更加喜爱这里。
LONG
);
	set("outdoors", "苏州");
	set("item_desc", ([
		"lian" :     "清风明月本无价 近水远山皆有情\n"
	]));
	set("exits", ([
		"north" : __DIR__"beidajie1",
		"southeast" : __DIR__"dongdajie3",
		"south" : __DIR__"baodaiqiao",
		"southwest" : __DIR__"xidajie1",
	]));

	set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
        ]));

	set("incity",1);
	setup();
}
