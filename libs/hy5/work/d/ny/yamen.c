
// Room: /d/snow/yamen.c

inherit ROOM;

void create()
{
	set("coor",({-75,4870,10}));
	set("short", "宁远城衙门");
	set("long",
"此乃宁远城县衙大堂，正中一张硕大案几的后面端坐着宁远城县令━━狄振山，头顶高挂匾额\n"
"，上书“正大光明”四个大字。两边衙役林立......你真的不心虚？\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yamen_yard",
]));
	set("objects", ([ /* sizeof() == 3 */
//  __DIR__"npc/judge_guard" : 4,
  __DIR__"npc/judgeman" : 1,
]));

	setup();
	replace_program(ROOM);
}
