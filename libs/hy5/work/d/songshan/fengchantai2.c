inherit ROOM;

void create()
{
	set("short", "封禅台");
	set("long", @LONG
峻极封禅台由大麻石所建，每块大石都凿得极是平整。地势甚为宽
阔。这里独立天心，万峰在下，云开日朗，纤翳不生。极目北望，可遥
见成皋玉门，黄河有如一线，西向隐隐见到洛阳伊阙，东南都是叠叠重
山。
LONG );
	set("exits", ([
		"eastdown" : "/d/songshan/fengchantai",
	]));
	set("objects", ([
                "/d/jinyong/book8/songshan/npc/linghu" : 1,
		"/d/jinyong/book8/songshan/npc/moda" : 1,
		"/d/jinyong/book8/songshan/npc/yu" : 1,
		"/d/jinyong/book8/songshan/npc/yue-buqun" : 1,
		"/d/jinyong/book8/songshan/npc/zuo" : 1,
		"/d/jinyong/book8/songshan/npc/renwoxing" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
