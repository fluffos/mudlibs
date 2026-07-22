
inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是【江湖】巫师的休息所在，刚粉刷过的四周墙壁上光
秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本
巫师留言簿(board)。
LONG );

   set("objects",([
    ]));
	set("exits", ([ /* sizeof() == 1 */
              "west" : __DIR__"newsroom",
        "east" : __DIR__"meeting",
               "up" : __DIR__"wizard_job",
	 	"down" : __DIR__"guest_room"
	]));
        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

       call_other("/d/board/wiz_b", "???");
	replace_program(ROOM);
}
