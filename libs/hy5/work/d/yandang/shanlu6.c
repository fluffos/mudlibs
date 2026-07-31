// Room: /d/yandang/shanlu6.c

inherit ROOM;

void create()
{
	set("short", "合掌峰");
	set("long", @LONG
合掌峰由灵峰和依天峰合成,峰高270米左右,在群峰环绕中直插云天
在夜晚,若位置得当,双峰就成为展翅欲飞的苍鹰,有诗云'灵峰有奇石,入
夜化为鹰,势欲凌空去,苍茫万里征.'
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lieren.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shanlu5",
  "enter" : __DIR__"guanyin",
]));

	setup();
	replace_program(ROOM);
}
