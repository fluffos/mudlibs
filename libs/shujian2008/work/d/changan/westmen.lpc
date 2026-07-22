// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/westmen.c

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "安定门");
        set("long", @LONG
这里是长安城的西城门。护城河既深又阔，而且城高墙厚，有一夫当关，
万夫莫开之势。仰望城楼，只见城楼高处满布哨兵，戒备森严。城墙上贴着官
府的告示(gaoshi)，官兵们正在认真地检查每一个过往的行人。
LONG
        );
        set("outdoors", "长安");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "east" : __DIR__"westjie4",
                "west" : __DIR__"westroad1",
                "up"   : __DIR__"westchl",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && (objectp(present("guan bing", environment(me))) || objectp(present("wu jiang", environment(me))))&& 
                dir == "up")
                return notify_fail("官兵拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n长安知府\n";
}

