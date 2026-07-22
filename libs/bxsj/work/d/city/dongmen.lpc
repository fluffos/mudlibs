// Room: /d/city/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是扬州东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着
几张官府的告示(gaoshi)。官兵们警惕地注视着过往行人，通缉犯最好小心为
妙。一条笔直的青石板大道向东西两边延伸。东边是郊外，隐约可见一片一望
无际的树林，神秘莫测。
LONG
	);
        set("outdoors", "扬州");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/group/entry/yzeroad1",
		"south" : __DIR__"yzyunhe",
		"north" : "/d/zhiye/biaoju1",
		"northeast" : __DIR__"guandimiao",
		"west" : __DIR__"dongdajie0",
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
	return FINGER_D->get_killer() + "\n扬州知府\n赵城之\n";
}
