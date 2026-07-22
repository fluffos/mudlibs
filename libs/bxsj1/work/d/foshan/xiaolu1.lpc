//xiaolu1.c 

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
北面是一条上山的小路，南面就是岭南山口了。东北面隐隐传来哭声，西
北面传来阵阵木鱼声，间或有诵经的声音传来。
LONG
	);
	set("outdoors", "佛山");

	set("objects",([
		NPC_D("poorman") : 1,
	]));

	set("exits", ([
		"northup" : __DIR__"xiaolu2",
		"south" : __DIR__"lingnan",
		"northeast" : __DIR__"fenchang",
		"northwest" : __DIR__"zumiao",
	]));
	setup();
}
