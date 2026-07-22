// Room: /d/cangzhou/beimen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "北门");
        set("long", @LONG
这里是沧州城的北城门，往西北去就到了溏沽了。北方的冬天总是很冷，
官兵们都冻的缩手缩脚的，两个穿着重甲的士兵正好搜查一个挑着担子进城的
老汉。
LONG );
        set("exits", ([
                "north" : __DIR__"nroad1",
        	"south" : __DIR__"beijie1",
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
