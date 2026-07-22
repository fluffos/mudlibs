#include <room.h>
inherit ROOM;

void init();
int do_jump(string arg);
int valid_leave(object me, string dir);

void create()
{
      set("short", "石室");
      set("long", @LONG
这里是一个石室，四周都是由方方整整的大石头砌成，约有一仗多高
左右两边墙壁的正中间是镶嵌了一排夜明玉，发出绿莹莹的光，还能
看清周围的情况，只是空荡荡的什么也没有！
    
LONG );
      set("item_desc", ([
            "玉石" : "你仔细一看，有一块玉石有一些暗淡，好象被磨的
不太亮了。\n",
      ]));
     
      set("exits", ([
         
          "south": __DIR__"mangdong",
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

      if (arg != "玉石" && arg != "out")
            return command("push "+arg);

      message_vision("$N你走了过去使劲推动玉石，你的脚下忽然露出一个
大洞你一脚踩空掉了下去。\n", me);
      if ((dex <= 30)&&(random(3)<2))
            message_vision("只听＂啪＂地一声$N整个脸贴在空谷回音的石壁上压得平平的。\n", me);
      else
            message_vision("$N提一口气，轻颖地飘落在下面的空地上！\n", me);

     me->move(__DIR__"shishi2");

      return 1;
}


