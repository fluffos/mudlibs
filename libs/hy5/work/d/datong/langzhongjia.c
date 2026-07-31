// Room: /open/dt/langzhongjia.c

inherit ROOM;

void create()
{
	set("short", "郎中家");
	set("long", @LONG
一进门你就隐隐闻到一股草药气味，走进堂屋，冲门的中堂
上挂着一副神农尝百草图，画中神农左手拿着一根不知名的小草
放入嘴中仔细品尝，似是在分辨草药的药性，右手持笔在纸上记
录着什么，一付悲天悯人的博大情怀跃然纸上。房间布置得很简
单，只是屋角一个大大的药柜颇为引人注目。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhuxiang2",
]));


	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
