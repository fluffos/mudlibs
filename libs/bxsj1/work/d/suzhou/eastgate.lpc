// Room: /city/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着几张
官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。一条
笔直的青石板大道向东西两边延伸，西边是城里。
LONG
	);
        set("outdoors", "苏州");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
	//	"east" : "",
        //	"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		NPC_D("guanfu/wujiang") : 1,
		NPC_D("guanfu/bing") : 2,
	]));
	set("incity",1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n苏州知府\n赵知仁\n";
}
