//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "泸水沿岸");
	set("long", @LONG
一条土路沿着泸水纵贯谷地南北，脚下泸水滔滔流去，长年累月
冲刷着谷中大地，东面碧罗雪山、西面的高黎山皆高耸蔽日。土路北
通此谷中心大镇巴的甸，南连数个乌夷小部落。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov41",
		"south" : __DIR__"minov45",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
