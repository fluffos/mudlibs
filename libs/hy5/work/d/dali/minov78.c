//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "榕树雨林");
	set("long", @LONG
这是一片湿润的雨林，脚下水汪汪的无路可行，十数丈高的巨大
榕树盘根错节，树干粗得几个人合抱也围不住。榕树的树枝下垂到泥
水中反过来扎根，成为特意的景致。雨林虽然少有走兽，却是飞禽聚
居的乐土，身手零活的台夷猎人攀越在大榕树浮露的根枝上，用短弩
射猎飞鸟。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov76",
		]));

	set("objects", ([
		__DIR__"npc/tylieren" : 1,
	]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
