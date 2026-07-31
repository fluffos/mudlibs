// Room: /open/dt/jiangjunfu.c

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
这是一间军府府。扇朱木大门紧紧关闭着。“肃静”“回避”
的牌子分放两头石狮子的旁边。前面有一个大鼓，显然是供
小民鸣冤用的。几名衙役在门前巡逻。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie5",
]));

        set("objects",([
       "/d/city/npc/bing" :2,
       "/d/city/npc/yayi" :2,	
       "/d/city/npc/wujiang" :1,		
]));
	setup();
	replace_program(ROOM);
}
