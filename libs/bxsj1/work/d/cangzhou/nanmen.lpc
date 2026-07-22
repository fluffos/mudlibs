// Room: /d/cangzhou/nanmen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "南门");
        set("long", @LONG
这是就是沧州城的南城门了，城墙被当成了广告牌，贴满了花花绿绿各行
各业的广告，一个手持长剑、身穿铁甲的武将被附近的欢声笑语所吸引，漫不
经心地盘查着过往的行人。
LONG );
        set("exits", ([
                "north" : __DIR__"nanjie1",
                "south" : __DIR__"sroad1",
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
