//山洞
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "雪洞");
	set("long", @LONG
	这是雪山中的一个洞,洞内风雪虽然小了点,但是奇寒无比,看来没
有什么生命可以在这里生存。洞的西南是一块巨大的冰壁。  
LONG
	);
	
	set("exits", ([
                "south" : __DIR__"hole9",
                "north":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole"+(random(10)+1),
                  ]));
        set("item_desc",([
             "wall":"从壁后隐隐看到有些透明，跟别的地方不一样。\n"
             ]) );
	setup();
}
void init()
{
       add_action("do_break","break");
}
int do_break(string arg)
{
      int n;
      object ob,axe;
      ob=this_player();
     if(arg!="bingbi")
      {
       write("不要随便砸东西，万一砸到人怎么办，就是砸不到人\n"+
"砸到花花草草的也不好嘛！\n");
       return 1;        
      }
      
      if( !ob->query_temp("weapon")) 
     {
      write("没有工具怎么的干活？\n");
      return 1;
     }
     axe=ob->query_temp("weapon");
     if(axe->query("id")!="snow axe")
     {
     write("没有合适的工具怎么的干活？\n");
     return 1;
      }
    message_vision(YEL"$N走到冰壁前，举起破冰斧，运足内力砸了过去！\n"NOR,ob);
    n=(int)ob->query("neili");
    if (n >= 1000)
	{
        message_vision(
        "$N只听一声轰响，冰壁被你的神力砸了个大洞。！\n", this_player());
        set("exits/southwest", "/d/feihu/bearhole");
        this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 5, this_object());
     }
     else
	{
		message_vision(
		RED"结果只听一声闷哼，$N被冰壁的反弹力震得眼前一黑....\n"NOR, this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }

    return 1;
}
void close(object room)
{
    message("vision",HIR"洞顶忽然掉下来一块大冰块，将洞口封了个严严实实。\n"NOR, room);
    room->delete("exits/southwest");
}
