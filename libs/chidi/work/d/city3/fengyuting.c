// Room: /d/chengdu/fengyuting.c
// oooc 1998/06/28 

inherit ROOM;

void create()
{
	set("short", "风雨亭");
	set("long", @LONG
你站在亭里，看着亭外灰蒙蒙的天，不禁有一种“山雨欲来风
满楼”的感觉。向西望是层起彼伏的街道，行人来来往往。向东望
是山麓，郁郁葱葱的树林中露出了一角飞掾。远处传来了肃穆庄重
的钟声，你的灵台一片清明。
LONG
	);

	set("exits", ([
                "westdown" : __DIR__"xiaojie3",
	]));
        set("objects", ([
            __DIR__"npc/youke" : 2,
        ]));


	setup();
	replace_program(ROOM);
}

