// Room: /d/yanjing/yanjinyuan/yanjinyuan.c

inherit ROOM;

void create()
{
	set("short", "研经院");
	set("long", @LONG
眼前是一栋大屋，宫中常见的那种，金碧琉璃瓦，朱红大铁门，墙高数丈，
更像一座小小的城堡。周围翠柏森森，遮住了阳光，远一处的景物就看不见了。
两边由守卫看守。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shouwei.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
