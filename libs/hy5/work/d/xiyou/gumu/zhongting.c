#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIC"古墓中堂"NOR);
  set ("long", @LONG


这是入墓的第二间石室，整个房间显得很空旷，一张
石桌，几个石椅，抬头能看到一幅牌匾(bian)出此之
外别无一物。


LONG);


  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"houting",
  "west" : __DIR__"armorroom",
  "east" : __DIR__"weaponroom",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "
          轩辕古墓  威镇三界
",
]));

        //call_other("/obj/board/gumu_ss", "???"); 
  setup();
}
void init()
{
  add_action("do_jump", "jump");
}
int do_jump(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要跳到哪里？\n");
  if(arg=="bianhou")
    return notify_fail("看好了在跳！\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="paibian")
    {
      message_vision(HIY "$N使劲一跳，结果撞在天花板上！\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "在古墓中闲的无聊自己撞墙死了！\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(YEL "$N觉的眼前一片模糊，金星乱冒！\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N气运丹田，轻轻一跳,平稳的落在牌匾之后！\n", me);
      me->move(__DIR__"bianhou");
      return 1;
    }
}

