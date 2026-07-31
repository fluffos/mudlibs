// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是地狱巫师的休息所在，刚粉刷过的四周墙壁上光秃秃的
什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫师留言
簿(board)。地上则是零零碎碎的一些BUG，到处乱爬。
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"down" : __DIR__"guest_room"
	]));
	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
}
