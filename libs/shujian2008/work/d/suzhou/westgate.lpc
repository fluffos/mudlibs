// Room: /city/ximen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上
方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告示(gaoshi)。
这里是罪犯逃往西域的必经之地，官兵们戒备森严，动不动就截住行人盘问。
一条笔直的青石板大道向东西两边延伸。西边是郊外，骑马的、座轿的、走
路的，行人匆匆。你加快了脚步，生怕官兵找碴。东边是城里。
LONG
	);
        set("outdoors", "苏州");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits",([
		"west" : __DIR__"qsgdao3",
		"east" : __DIR__"xidajie2",
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
