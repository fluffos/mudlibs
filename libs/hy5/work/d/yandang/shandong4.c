// Room: /d/yandang/shandong4.c

inherit ROOM;

void create()
{
	set("short", "隐虎洞");
	set("long", @LONG
刚走进洞中,你就听到一阵呼呼噜噜的声音,是什么呢,当你仔细寻
找,就会发现在洞顶挂满了大大小小的蝙蝠,远远看去,只见一片闪闪
的雪红的目光,这是一群吸血蝙蝠,快逃吧!
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shandong2",
  "southeast" : __DIR__"shandong3",
  "northup" : __DIR__"shandong5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bat.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
