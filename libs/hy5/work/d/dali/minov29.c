//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "议事堂");
	set("long", @LONG
这间大竹楼的中层是普麽部的议事堂，村中长老逢要日便在此聚
议族内大事，也在此接待外族贵客，或会晤大理国官府派来的使者。
屋内以本族的图腾壁画、鸟兽皮毛装饰四壁。
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov80",
		"up" : __DIR__"minov30",
		]));

	set("objects", ([
		__DIR__"npc/tyzuzhang" : 1,
	]));

	set("cost", 2);
	setup();
}
