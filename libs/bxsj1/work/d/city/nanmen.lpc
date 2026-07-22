// Room: /d/city/nanmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是扬州的南城门，城墙上贴着一张官府的告示(gaoshi)。扬州是淮盐的
集散地，往来的盐贩子很多，几个官兵正在认真地检查过往的行人，查看他们
是否携带有私盐。南边的青石大道可以一直通到远处长江北岸的码头。
LONG
	);
        set("outdoors", "扬州");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south" : __DIR__"jiangbei",
                "north" : __DIR__"nandajie1",
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
