// nanmen  by netkill

inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这里是昆明的南门，高高的城楼上写着大大的南门两个字，由此南去，
就是滇池了，出入南门的人很少，只有些渔民不时提着新鲜的鱼进城来卖。
LONG );

	set("exits", ([
                "south" : "/d/wudujiao/road1",
                "southeast" : "/d/foshan/dlroad7",
		"north" : __DIR__"nandajie2",
		
	]));

	
	setup();
	replace_program(ROOM);
}

