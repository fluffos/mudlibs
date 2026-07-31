//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "乌夷民居");
	set("long", @LONG
这是一所乌夷族的房屋。此间正处市镇，四周无山势可依，门口
正对巷陌。青石大房，装修颇为不俗，大门是精心雕制的，刻有
日、月、虎豹等精美的图案，看来这里是乌撒部的祭祀大屋。
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov42",
		"enter" : __DIR__"minov44",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
