// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "财务厅");
	set("long", "这里是啸天会向弟子发放工资和活动经费的地方，房间里
一张木案后面帐房正在结算这个月的花销。从这儿向北是神风
堂大厅，东面是帐房。\n");

	set("exits", ([
                "east" : __DIR__"bjg",
                "north" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}

