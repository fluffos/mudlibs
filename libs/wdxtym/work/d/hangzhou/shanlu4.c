// shanlu4.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
走在这弯弯的小路上，看着沿途山峰云影，松竹青葱，岩石斑驳。
不禁感到胸怀舒畅，颇想长居此地。西上便到了上天竺，东下就到了
龙井。
LONG);
	set("exits", ([
	    "westup"   : __DIR__"faxisi",
	    "eastdown" : __DIR__"shanlu5",
	]));
	set("outdoors", "hangzhou");
	set("max_room", 4);
	setup();
}
