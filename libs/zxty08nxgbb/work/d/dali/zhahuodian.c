// Room: /d/dali/zhahuodian.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：22时12分39秒。

inherit ROOM;

void create()
{
	set("short", "杂货店");
	set("long", @LONG
这里是大理城的杂货铺。专门经营一些人们日常用的生活用品，
由于老板与人和善，而且这里的东西便宜实惠，所以这里的生意一直
还不错。靠墙的架子上摆著各种生活必需用品，中间一张柜台，店主
人正坐在柜台后面算帐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie2",
]));
        set("objects", ([
                __DIR__"npc/zhen" : 1,
        ]));

	setup();
}
