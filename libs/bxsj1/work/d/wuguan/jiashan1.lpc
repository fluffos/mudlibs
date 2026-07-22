// jiashan1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"假山"NOR);
         set("long",@LONG
看来很久没人到这里来了，周围杂草丛生，树木荒凉。回头就是你刚才钻
过来的大缝隙（feng）。乱草树木丛中有一堆杂乱石块，其中一块光滑的大石
头（shi）特别引人注目。
LONG
    );
	 set("outdoors","武馆");
		 
         set("item_desc", ([
             "shi" : "这块大石头下面好象有什么东西，不知能不能移开(move)它。\n",
	     "feng" :BLU"一条黑乎乎的缝隙，好象可以钻（zuan）过去。\n"NOR,
	 ]));

	 setup();
}

void init()
{
    add_action("do_move", "move");
    add_action("do_move", "tui");
    add_action("do_zuan", "zuan");
}

int do_move(string arg)
{
        int j,exp;
        exp = this_player()->query("combat_exp");
	j=this_player()->query("jing");
        if( !arg || arg!="shi" ) {
                write("你想要推什么？\n");
                return 1;
        }
        message_vision(YEL"$N深深地吸了口气，缓缓推动大石头。\n\n"NOR, this_player());
        if ( exp > 1000 && j >= 90) {
          message_vision(HIG"只见大石头慢慢地前移，$N把大石头移开了！发现一个黑乎乎的洞口。\n"NOR, this_player());
          set("exits/enter", __DIR__"mishi");
          this_player()->set("jing",j-30);
          remove_call_out("close");
          call_out("close", 5, this_object());
        }
        else {
          message_vision(HIG"$N累的气喘吁吁，可是大石头根本没有动。\n"NOR, this_player());
          this_player()->set("jing",10);
        }
        return 1;
}

void close(object room)
{
        message("vision",HIY"大石头滚回了原位，又挡住了洞口。\n"NOR, room);
        room->delete("exits/enter");
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (arg !="feng") 
        return notify_fail("你往哪里钻啊？\n");
        if( arg=="feng"){            
            write(HIG"你转身用力地往缝隙里钻，费力地穿过了缝隙。\n\n"NOR);
            me->start_busy(2);
            me->move(__DIR__"jiashan");
        }
        return 1;
}
