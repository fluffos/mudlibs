// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
        set("short", "音乐厅");
	set("long", @LONG
     这里就是著名的音乐厅了，到处都是跳动的音符，飘忽的旋律.
优美的曲调直冲你的心底，又散发向四肢而去，你感觉舒服透了.
LONG );

	set("exits", ([ /* sizeof() == 1 */
  	"out" : __DIR__"wizard_room" ,
  	"city":"/d/city/guangchang",
  	]));

	set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();

 //   call_other("/clone/board/plan_b", "???");
//	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
