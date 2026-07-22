// Room: /d/huashan/path1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "山脚下");
	set("long", @LONG
这里是华山脚下，南面就是素有「奇峰天下第一山」的西岳华山，华山由
于远望宛如一朵白莲花，因而得名（古时，「华」与「花」通）。西面有个小
村庄，北边有几间房屋。
LONG
	);
	set("exits", ([
		"west" : "/d/village/eexit",
		"north" : __DIR__"yuquan",
		"southeast" : __DIR__"shaluo",
		"south" : __DIR__"shulin",
	]));
        set("objects",([
                NPC_D("tiao-fu") : 1,
        ]));
	set("outdoors", "华山" );
	setup();
}
