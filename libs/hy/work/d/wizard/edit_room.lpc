// Room: /d/wizard/edit_room.c

inherit ROOM;

void create()
{
	set("short", "修改记录室");
	set("long", @LONG
这里的公告板上记录着巫师们建设的记录。
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"west" : __DIR__"wizard_room"
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	"/clone/board/wized_b"->foo();
	replace_program(ROOM);
}
