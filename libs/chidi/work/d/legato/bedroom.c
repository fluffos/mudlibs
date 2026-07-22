// Room: bedroom.c
// Date: Mar.2 1998

#include <room.h>
inherit ROOM;

void init();
int do_jump(string arg);
int valid_leave(object me, string dir);

void create()
{
      set("short", "卧室");
      set("long", @LONG
这是灵剑公子的卧室，里面简朴整洁，桌子上散落着两三本书，床头上悬着
一柄宝剑。蒙着绿纱的小窗透过一片叶影，傍着金丝雀清脆的啾啾声萦绕在
雕花梁上。墙壁挂着一幅装裱精美的山水画（hua),显得屋子恬静，典雅。
    
LONG );
      set("item_desc", ([
            "hua" : "你仔细一看，画框好象是经常有人动的样子，被磨的有些
发亮了。\n",
      ]));
     
      set("exits", ([
         
          "south": __DIR__"keting",
      ]));
      set("no_fight", 1);
      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
}

void init()
{
      add_action("do_push", "push");
}

int do_push(string arg)
{

      object ob;
      object me = this_player();
      int dex = this_player()->query_dex();

      if (arg != "hua" && arg != "out")
            return command("push "+arg);

      message_vision("$N你使劲扳动栏杆，你的脚下忽然露出一个大洞
你一脚踩空掉了下去。\n", me);
      if ((dex <= 30)&&(random(3)<2))
            message_vision("只听＂啪＂地一声$N整个脸贴在空谷回音的石壁上压得平平的。\n", me);
      else
            message_vision("$N提一口气，轻颖地飘落在下面的空地上！\n", me);

      me->move(__DIR__"mishi");

      return 1;
}


 

