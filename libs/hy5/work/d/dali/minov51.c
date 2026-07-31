//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "梯田");
	set("long", @LONG
东泸水河谷气候较温暖，乌夷先民沿山坡开垦了不少梯田。此间
乃是低坡，层层梯田沿坡而上，土地看来并不肥沃，作物较稀疏，乌
夷地区农业颇为落后，多行换季轮耕，附近山上的一些梯田在这个季
节正荒芜着。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov42",
		]));

	set("objects", ([
		__DIR__"npc/wynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
