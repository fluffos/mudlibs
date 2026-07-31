// Room: /d/songshan/shuyuan.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "嵩阳书院");
	set("long", @LONG
这里原是嵩阳寺。现在文化昌明，就改成了嵩阳书院，和睢阳
书院，岳麓书院，白鹿书院合称天下 "四大书院" 。北宋程颢程颐
曾在此讲学。院内有古柏三株，汉武帝巡游至此，册封为大将军，
二将军，三将军。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao2",
		"northwest" : __DIR__"shandao3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

