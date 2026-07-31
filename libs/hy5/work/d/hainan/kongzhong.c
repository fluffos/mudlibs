// Room: /d/hainan/kongzhong.c

inherit ROOM;

void create()
{
	set("short", "天空中");
	set("long", @LONG
天空中的景色美么？ 你可别下来呀,要不然就死了.
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
