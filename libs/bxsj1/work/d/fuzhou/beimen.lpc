// Room: /d/fuzhou/beimen.c
// lklv modify 2001.9.10

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "北门");
	set("long", @LONG
这里是福建首府福州的北门。入此门向南可到福州府、往佛山镇，出此门
向北可抵江浙一带。城门的墙上张贴着一纸告示(gaoshi)。
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
                "north" : __DIR__"road5",
                "south" : __DIR__"beijie",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("outdoors", "福州");
	setup();
}
string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n福州巡府\n某某某\n";
}
