// Room: /city/ximen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "通泗门");
	set("long", @LONG
通泗门是扬州的西门，青砖砌成。城门前沿着城墙，在护城河边种
着扬柳，因而扬州被称为「绿柳城郭」。几个士兵站在城门口，检查着
过往行人车辆。这里是罪犯逃往西域的必经之地，官兵们戒备森严，动
不动就截住行人盘问。城墙上贴着几张通缉告示(gaoshi)。 
    一条笔直的青石板大道向东西两边延伸。西边是郊外，骑马的、座
轿的、走路的，行人匆匆。东边是城里。往北是一片桃林。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"north" : "/d/taohuacun/taohua1",
                "south" : __DIR__"youju",
                "southwest" : "d/jingzhou/road1",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/d/mingjiao/npc/fenggongying" : 1,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

