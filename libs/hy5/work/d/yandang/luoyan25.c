// Room: /d/yandang/luoyan25.c

inherit ROOM;

void create()
{
	set("short", "冷雁池塘");
	set("long", @LONG
从竹林出来,在你面前的是一个池塘,池水荡漾,水波澜澜,天上明月
入池,在水中月影流波,池边疏枝横斜,暗香浮动,当此良辰美景,对绝色佳
人,人间天上,不外如是.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan26",
  "south" : __DIR__"luoyan24",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
