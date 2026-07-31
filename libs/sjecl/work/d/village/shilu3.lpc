// Room: /d/village/shilu3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人
家不多，而且大都生活很艰辛。这是一条东西走向的碎石路，北面是间小酒馆，
一个幌子挂在房檐下。
LONG
        );
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"north" : __DIR__"jiusi",
		"west" : __DIR__"shilu5",
	]));
	set("objects", ([
		NPC_D("poorman"): 1
	]) );

        set("no_clean_up", 0);
        set("outdoors", "华山");

	setup();
}
