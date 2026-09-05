// Room: /xiaocun2/jiudian.c
// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "酒店");
	set("long", @LONG
这是一家专门经营酒的店铺。这里的酒在附近可是数一数二，据说连扬州醉
仙楼的酒都是这里供应的。酒店的老板嗜酒如命，号称「千杯不倒」，人豪爽且
友善，在此地极为出名。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/jiushen": 1,
	]));
	setup();
	replace_program(ROOM);
}