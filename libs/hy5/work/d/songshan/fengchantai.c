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
		"eastdown" : "/d/songshan/shandao8",
	"westup" : __DIR__"fengchantai2",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/bo": 1,
		CLASS_D("songshan")+"/sha": 1,
                __DIR__"master/master" : 1,

	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 850);
	set("coor/z", 90);
	setup();
	//replace_program(ROOM);
}



int valid_leave(object me, string dir)
{
        if(((int)me->query("jinyong/book8")!=9)&&(dir == "westup"))
        {
                return notify_fail("里面正在举行五岳大会，刀枪无眼，不要进去找死了。\n");
        }

        return ::valid_leave();
}
