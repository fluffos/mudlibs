// Room: /d/city/xidajie1.c
// Lklv modify 2001.9.27 饿了，一会回家咯

inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。街上的行人比
以前也多了许多，东面是扬州的著名风景“瘦西湖”，西边是西城门。南边是
一家珠宝店，而北边则是一座大酒楼，挂着“太白遗风”的招帘，门额上悬挂
一方横匾，“瘦西湖酒馆”五字擦得闪闪发亮, 乃是顾炎武的手笔。阵阵酒香
肉香让你垂涎欲滴。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"xidajie2",
                "south" : __DIR__"zhubaodian",
		"west" : __DIR__"ximen",
		"north" : __DIR__"jiulou",
	]));

        set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
        ]));
	set("incity",1);
	setup();
	quarter_pass();
}

void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。街上的行人比
以前也多了许多，东面是扬州的著名风景“瘦西湖”，西边是西城门。南边是
一家已经关门了的珠宝店，而北边则是一座已经打烊了的大酒楼，挂着一幅招
帘，门额上悬挂一方横匾，黑暗之中看不太清匾上的字迹。
LONG
		);
		delete("exits/north");
		delete("exits/south");
	}
	else {
		set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。街上的行人比
以前也多了许多，东面是扬州的著名风景“瘦西湖”，西边是西城门。南边是
一家珠宝店，而北边则是一座大酒楼，挂着“太白遗风”的招帘，门额上悬挂
一方横匾，“瘦西湖酒馆”五字擦得闪闪发亮, 乃是顾炎武的手笔。阵阵酒香
肉香让你垂涎欲滴。
LONG
		);
		set("exits/north", __DIR__"jiulou");
		set("exits/south", __DIR__"zhubaodian");
	}
	call_out("quarter_pass", 30);
}
