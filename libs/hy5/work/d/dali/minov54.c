//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "碧罗山下");
	set("long", @LONG
此间正处碧罗山脚下，几层梯田沿山坡而上，土地看来一点也不
肥沃，作物较稀疏。乌夷地区农业颇落后，行换季轮耕，村民在不同
的季节耕作不同的田地，许多附近的梯田正荒芜着无人耕作。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
