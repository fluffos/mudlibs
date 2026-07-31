//Room: /d/dali/biluoshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","碧罗山下");
	set("long",@LONG
此间正处碧罗山脚下，几层梯田沿山坡而上，土地看来一点也不
肥沃，作物较稀疏。乌夷地区农业颇落后，行换季轮耕，村民在不同
的季节耕作不同的田地，许多附近的梯田正荒芜着无人耕作。
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"yixibu",
	]));
	setup();
}

