#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIC"石室"NOR);
     set("long", @LONG
此地供各弟子打坐静修之用。地上仅有几个蒲团，几个古墓弟子正在闭目
领悟。正面的石墙( qiang)上刻着不少文字, 仔细一看，原来都抄录着四书五
经等古籍，用来给古墓弟子提高修养。
LONG
        );

      set("exits", ([
            "west" : __DIR__"gmqs",
            "south" : __DIR__"yaofang",
            "north" : __DIR__"lgf",
      ]));

      set("item_desc", ([
            "qiang" : "墙上写满了各种古籍文字。\n",
      ]));

      create_door("west", "石门", "east", DOOR_CLOSED);

      setup();
}

void init()
{ 
            add_action("do_du","read");
}

int do_du(string arg)
{
          mapping fam;
          object me;
          me = this_player();                     
          if ( !living(me) ) return 0;
          if (me->is_busy() || me->is_fighting())
           return notify_fail("你正忙着哪！\n");
          if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
           return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
          if (arg =="qiang"){                 
          if ((int)me->query("jing") < 20 )
           return notify_fail("你觉得好累,好想睡觉。\n");
          if ( me->query_skill("literate",1) >300)
           return notify_fail("你已经完全读懂了墙上的文字。\n");
          if (me->query("potential", 1) < 1)
           return notify_fail("你的潜能没了，不能再继续修习了。\n");
          me->add("potential", -1);
          me->receive_damage("jing", 5 + random(10));
          me->improve_skill("literate",me->query_int());
          write("你对着石壁，仿佛有所领悟。\n");
          return 1;
          }
       return notify_fail("你要读什么？\n");
}

