// Room: /d/songshan/fengchangtai.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "封禅台");
	set("long", @LONG
峻极封禅台由大麻石所建，每块大石都凿得极是平整。地势
甚为宽阔。这里独立天心，万峰在下，云开日朗，纤翳不生。极
目北望，可遥见成皋玉门，黄河有如一线，西向隐隐见到洛阳伊
阙，东南都是叠叠重山。
LONG );
	set("exits", ([
		"eastdown" : __DIR__"junjigate",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

