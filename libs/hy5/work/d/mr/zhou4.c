// /u/beyond/mr/zhou4.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名老艄公手持长竹篙，正在船
尾吃力地撑着船。
LONG
	);
	set("outdoors", "mr");
        set("no_fight",1);

	setup();
	replace_program(ROOM);
}



