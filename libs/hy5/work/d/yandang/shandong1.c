// Room: /d/yandang/shandong1.c

inherit ROOM;

void create()
{
	set("short", "云雾洞");
	set("long", @LONG
云雾洞真是名不虚传,在一片高高低低的山岩中,隐隐有云雾飘出,
当你仔细搜索时,却一无所见.洞中比较潮湿,时而能听到水珠从洞顶掉
到地上,'叮'的一声.西面是透天洞,东面是含珠洞.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"shanlu8",
  "westup" : __DIR__"shandong2",
  "eastup" : __DIR__"shandong3",
]));

	setup();
	replace_program(ROOM);
}
