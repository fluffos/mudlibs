// Room: /open/dt/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long", @LONG
门口的布帘上用蓝靛写了一个大大的“当”字，使人看了就
不舒服。走进门来，一道长长的柜台把房间分成两半，柜台里坐
着一个长着八字胡的朝奉，他正对着一个来当金链子的人说道：
你这条项链虽然份量不轻，但成色不是很好，而且又旧又破，最
多只能值十两银子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao2",
]));

	set("objects",([
	__DIR__"npc/pawnboss" : 1,
]));

	setup();
}
