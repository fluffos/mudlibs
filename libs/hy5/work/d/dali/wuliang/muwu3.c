// cool 980725
// Modify By River 98/12
//COOL@SJ,9908
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "石屋里");
        set("long", @LONG
这里是石屋里了，里面黑漆漆的，什么也看不清楚，阳光都被门口的一块
大岩石挡住了，只能透过几缕石缝中透过来的阳光，你打量着这间屋子。
LONG
        );

        set("item_desc", ([
              "yan" : "一块大岩石，可以试着推开!。\n",
        ]));
        setup();
}

void init()
{   
       object room,ob;
       ob=this_player();
       if( ! ( room = find_object(__DIR__"muwu3")))
         room = load_object(__DIR__"muwu3");
       if(!present("duan yu", room))
       if (interactive(ob)
        && !present("qingnian nanzi", room)
        && ob->query_temp("duanyu/find2")){
         new(__DIR__"npc/dy")->move(room);
         }
       if (userp(ob)) {
	  remove_call_out("close");
          call_out("close", 2, this_object());
          }
	  add_action("do_tui", "tui");
          add_action("do_tui", "push");
}

int do_tui(string arg)
{
       int i;
        i = this_player()->query("neili");
       if( !arg || arg!="yan" ) 
         return notify_fail("你要推什么？\n");
        message_vision("$N站在门后，把双掌放在岩上，深深的吸了一口气，双臂一发劲，大喝一声“开”。\n", this_player());
       if ( i >=800 ){
        message_vision("$N只听一阵轰响，大石缓缓的移开了！\n", this_player());
        set("exits/out", __DIR__"muwu2");
        this_player()->add("neili",-800);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
       else {
        message_vision("$N却见大石纹丝不动，看来$N的内力还不够。\n", this_player());
        this_player()->set("neili",0);
        }
    return 1;
}

void close(object room)
{
      message("vision","大石缓缓移动，把石屋再次封住了。\n", room);
      room->delete("exits/out");
}
