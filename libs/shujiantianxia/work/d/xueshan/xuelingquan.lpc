// Room: xuelingquan.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "雪灵泉");
	set("long", @LONG
这是由雪山积雪融化汇流而成的一条小溪，流到这里，地势平坦，蓄成了一汪
泉水(quanshui)，清澈甘冽，冰凉透骨。真是：
    水穷行到处，云起坐看时。
    千山遮不住，毕竟东流去。
    水远，怎知流水外，却是乱山更远。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"shanlu5",
		"southdown" : __DIR__"fengjiantai",
	]));
        set("outdoors", "雪山");
	set("coor/x",-300);
  set("coor/y",160);
   set("coor/z",20);
   setup();
}
void init()
  {
	if (is_wanted(this_player()))
		return;
        add_action("do_tiao", "tiao");
  }
int do_tiao(string arg)
{
        object ob;
        ob = this_player();

        if( arg != "quanshui" ) 
             return notify_fail("你要往那里跳？\n");

        message_vision("$N纵身往泉水中跳了下去。\n",ob);
        ob->move(__DIR__"quanshui");
        return 1;
}
