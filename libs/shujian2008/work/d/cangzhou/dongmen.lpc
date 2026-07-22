// Room: /d/cangzhou/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", "东门");
        set("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着几张官
府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。一条笔直
的青石板大道向东西两边延伸。城外的郊野里有一片树林。
LONG );
        set("exits", ([
                "west" : __DIR__"dongjie1",
        	"east" : __DIR__"eroad1",
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
