// Room: /d/wizhome/incahome/beimen.c
// Date: inca 98/08/13

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北京北箭楼");
	set("long", @LONG
这是北京北箭楼，由于北方的环境恶化，经过几年的风沙侵蚀显得有些破败。
城门正上方勉勉强强可以认出“北门”两个大字，城墙上贴着几张通缉告示
(gaoshi)。罪犯常常从这里逃出京城，官兵们戒备森严，动不动就截住行人
盘问。一条笔直的青石板大道向南北两边延伸。北边是郊外，骑马的、坐轿
的、走路的，行人匆匆。南边是城里。
LONG
	);
        set("outdoors", "city2");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"north" : __DIR__"nroad1",
                "southdown" : "d/beijing/xisi2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}

