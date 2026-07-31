// Room: /chengdu/zhubaopu.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "周记珠宝铺");
	set("long", @LONG
这是一家专营金银、珠宝类的首饰店，老板和蔼可亲，热情周
到。如果你想找件礼物送给你的心上人，那就不要再犹豫了，赶紧
到钱庄取钱吧。
LONG
	);

	set("exits", ([
                "west" : __DIR__"beijie",
	]));

	setup();
	replace_program(ROOM);
}

