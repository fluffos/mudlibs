// /d/city/beimen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是就是扬州城的北城门了，城门口一队队官兵正在盘查过往的百姓，一
个手持长剑身穿铁甲武将正在门口巡视，近些时候因为江南一带的贩私盐愈演
愈烈，所以朝廷以办事不利的罪名撤消了程要发的官职，上京问斩了，派了一
位新的巡抚大人，弄的现在人心惶惶，谁都不敢在城门久留。城门的墙上张贴
着一纸告示(gaoshi)。
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beidajie1",
		"north" : __DIR__"hsroad1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("outdoors", "扬州");
	set("incity",1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州巡府\n赵城之\n";
}
