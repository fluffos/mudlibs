// Room: /d/china/junying/xiaozhen/jiulou2.c

inherit ROOM;

void create()
{
	set("short", "醉仙阁二楼");
	set("long", @LONG
这里是醉仙阁的二楼，由于醉仙阁的名气，所以小镇上和来
往的达官贵人都来这里用饭。窗外是熙熙攘攘的中央广场，楼内
是一片觥筹交错，老板在四处招呼着客人。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"jiulou",
]));
	set("objects",([
	__DIR__"npc/zuixiange_boss" : 1,
]));
        set("NORIDE","小店楼梯太窄，您老骑着坐骑可是上不去。");
	setup();
	replace_program(ROOM);
}
