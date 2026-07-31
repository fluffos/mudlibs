// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是「海洋」巫师的休息所在，刚粉刷过的四周墙壁上光
秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本
巫师留言簿(board)。
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"down" : __DIR__"guest_room",
                "west" : __DIR__"proom",
                "east" : __DIR__"edit_room",
	 	"up":    __DIR__"robot_court",
	 	"north": "/d/death/outjail",
	 	"south": __DIR__"work"
	]));
        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( dir=="down" && !wizardp(me) );
                return notify_fail("这里只有巫师才登进去。\n");
this_player()->move("/d/biwu/hole");
}
