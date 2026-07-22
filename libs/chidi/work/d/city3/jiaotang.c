// Room: /chengdu/jiaotang.c
// oooc: 1998/6/28

inherit ROOM;

void create()
{
	set("short", "教堂");
	set("long", @LONG
这是一个由英国人开的教堂。当初马可波罗远渡重洋来到中国
的时候，曾经到过这儿听牧师传道，可见历史相当悠久。由于今天
不是礼拜，所以教堂里也没几个人。前方是一个耶稣受难的雕像。
雕像的下面站着一个牧师，满脸含笑地望着你。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"xiaojie3",
	]));

	set("objects", ([
		__DIR__"npc/chuanjiaoshi" :1 
	]));

	setup();
	replace_program(ROOM);
}

