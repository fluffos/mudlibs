// Room: /d/fengtian/fangjia.c

inherit ROOM;

string go_enter(object me);

void create()
{
	set("short", "方华林家");
	set("long", @LONG
这是一间普通的大瓦房，屋子里陈设非常简单，木柱子上的
油漆已经剥落，地上满是尘土，几行清晰的脚印格外醒目。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"kd9",
	"west" : __DIR__"houyuan",
"enter" : __DIR__"quest1",
]));


	setup();
}


