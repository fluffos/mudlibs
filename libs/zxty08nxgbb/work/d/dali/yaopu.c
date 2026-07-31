// Room: /d/dali/yaopu.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时57分49秒。

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家神秘的药铺，座落在东大街和市中心的交界处，普通的
门面和招牌，街坊们都说这家药铺的药灵验的很。从药柜上的几百个
小抽屉里散发出来的一股浓浓的药味，让你几欲窒息。据说这家店铺
有一种很神密的药物。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie1",
]));

        set("objects", ([
                __DIR__"npc/moyixin" : 1,
        ]));

	setup();
}
