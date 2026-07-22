// /d/hz/beimen.c 北门

#include <ansi.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short",HIY"北门"NOR);
	set("long", @LONG
这里就是杭州城的北门了，俗话说：上有天堂，下有苏杭。慕名而来的
游客络绎不绝，而站在城门口把守的官兵，也细细盘查过往的游客，他见你
走过来，连忙上前盘查。城门口贴着一张告示(gaoshi)。
LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits",([
                  "north" : "/d/group/entry/hzqsd7",
                  "south" : __DIR__"qsddao6",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("outdoors", "杭州");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n杭州知府\n王忠\n";
}

