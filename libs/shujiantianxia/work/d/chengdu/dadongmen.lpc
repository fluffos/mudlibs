// /d/chengdu/dadongmen.c
// By Jpei

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "大东门");
	set("long", @LONG
这是就是成都的东城门了。成都地处川中，一向少有战事困扰。但是朝廷
还是驻扎了重兵。城门的墙上张贴着一纸告示(gaoshi)。
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
                "west" : __DIR__"ddajie4",
		"east" : __DIR__"eroad1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("outdoors", "成都");
	set("incity",1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n益州刺史\n司马远\n";
}
