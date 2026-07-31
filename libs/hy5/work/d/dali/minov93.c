//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "河边");
	set("long", @LONG
你来到河边，两侧山壁几乎是直上直下，西面是一条大河自北滚
滚而来，在此折向东奔腾而去，河水汹涌，巨浪滔天，发出一阵阵骇
人的轰响。此处河谷稍窄，前面有三根粗藤条绑在一棵大树上，另一
端跨河而过，似可攀援而过。此去向南乃是崇山峻岭。
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov92",
		"south" : __DIR__"minov52",
		]));

	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
