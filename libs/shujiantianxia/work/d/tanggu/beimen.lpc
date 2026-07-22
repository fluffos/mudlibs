
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "北城门");
	set("long", @LONG
这里就是塘沽口的北城门了，城门口一队队官兵正在盘查过往的百姓。一
个手持长剑身穿铁甲的武将在门口巡视。城门的墙上张贴着一纸告示(gaoshi)。
LONG );
	set("exits", ([
		"south" : __DIR__"stbeijie2",
//                "northeast" : "/d/daizhou/guandao1",
	]));

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("outdoors", "塘沽");

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n塘沽知府\n";
}
