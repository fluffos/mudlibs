// Room: /d/dali/yamen.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时28分57秒。

inherit ROOM;

void create()
{
	set("short", "衙门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分放两
头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前巡逻。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yamen2",
  "east" : __DIR__"xbdajie1",
]));

                 set("objects", ([
    __DIR__"npc/yayi" : 4,
        ]));

         
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "west")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}
