// Room: /d/cangzhou/ximen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "西门");
        set("long", @LONG
这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上
方勉勉强强可以认出“西门”两个大字。这里是罪犯逃往西域的必经之地，官
兵们戒备森严，动不动就截住行人盘问。一条笔直的青石板大道向东西两边延
伸。
LONG );
        set("exits", ([
		"east" : __DIR__"xijie1",
		"west" : __DIR__"wroad1",
        ]));
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("outdoors", "沧州");

	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n沧州知府\n南仁通\n";
}
