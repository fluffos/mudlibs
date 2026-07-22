// /d/plummanor/shiji.c 石级
// By Jpei

inherit ROOM;

void create()
{
	set("short", "石级");
	set("long", @LONG
这条山边的石级蜿蜒曲折，不知拐了多少个弯。走到石级尽头，可以看到
东边有条小路，折向南边。远处是大片的梅林。
LONG
);
/*	set("objects",([
		__DIR__"npc/you" : 2,
	]));*/
	set("outdoors","梅庄");
	set("exits", ([
		"east" : __DIR__"road1",
		"west" : __DIR__"hubian",
	]));
	setup();
}
