#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"东长安街"NOR);
	set("long", @LONG
这里往东是京城的东门。一直向西走就可以到达皇宫了。城门下有一
些执勤的兵士，时下虽已天下太平，但一干兵将还是英姿勃勃，警
惕的盯着往来人士。东边出城便是通往东海的官道。
LONG
	);

	set("exits", ([
 "west" :__DIR__"dchjie4",
 "east" :__DIR__"dzhimen",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

