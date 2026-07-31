//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "桑林");
	set("long", @LONG
一大片桑树林生长在低山的缓坡山腰上。养蚕、纺丝是摆夷族的
重要副业，摆夷妇女大都擅织丝，编织自己穿着的短裙，也用来和临
"近部落交换些其它物品。一群摆夷姑娘正在林间忙着采摘桑叶。
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov21",
		]));

	set("objects", ([
		__DIR__"npc/bycaisang.c" : 3,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
