//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
行进在南诏崎岖的山林中。高山耸立，雨林茂密繁盛，树木大都
枝杈横生，给行路带来额外困难。附近山民经常行走才开出这样的道
路来，尽管如此，行旅仍然需要挟带砍刀，随时准备砍除路边树木横
出的障碍。
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov16",
		"eastup" : __DIR__"minov18",
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
