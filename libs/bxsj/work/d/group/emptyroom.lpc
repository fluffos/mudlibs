// emptyroom.c
// by augx@sj  2/26/2002
// this room for group guard when they are killed just and wait for revive

inherit ROOM;

void create()
{
	set("short","空房间");
	set("long","这里无左无右无上无下无前无后，是帮派精灵所居之处。\n");
	set("outdoors", "group");
	set("no_clean_up",1);
	setup();
}

int clean_up()
{
	return 1;
}
