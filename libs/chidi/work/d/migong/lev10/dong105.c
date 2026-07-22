#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_pick(string arg);

void create()
{
		set("short", YEL"岩洞"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了。左面的
岩石上有些从没见过的植物(zhiwu)。 
LONG NOR);
	set("exits", ([
		"out" : __DIR__"dong104",
                	]));
                set("item_desc",([
            "zhiwu" : "有点象海棠的植物，可以摘(pick)下来看看。\n"
        ]) );
           set("objects", ([
              __DIR__"npc/boss1" : 1,
             __DIR__"npc/boss2" : 6,
                ]));
	set("no_clean_up", 0);
        set("caocount", 1);
	setup();
	
}
void init()
{
        add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object me=this_player();
        object obn;
              if( !arg || arg != "zhiwu" )
        {
             write("你要拿什么呀!\n");
             return 1;
        }
message_vision("$N在岩石前站定，深呼一口气，突然跃起。\n", this_player());
         if(query("caocount") > 0)
             {
message_vision("$N伸手一摘，手中多了一物。\n", this_player());
                 obn = new("/d/migong/obj/haitang");
                 obn->move(me);
                 add("caocount",-1);
             }
             else
message_vision("$N定睛一看，发现植物以被人拿走了。\n", this_player());
          return 1;
        }
        
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "out" && objectp(present("bailei", environment(me))))
                return notify_fail(HIY"全真败类"NOR"喝道：“给我乖乖的留下吧?\n");
      

        return ::valid_leave(me, dir);
}
