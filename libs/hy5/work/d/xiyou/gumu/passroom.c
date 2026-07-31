#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIB"九宫密室"NOR);
  set ("long", @LONG

一间斗室，两盏长明青灯，忽明忽暗的闪烁。一种说不出的诡异
正中间一张玉石桌上横三竖三摆放着九个非金非木的棋子(qizi)
每个棋子下都有一道深沟，三行三列共九条，交叉如一张小棋盘
四周落着一层厚厚的尘土，看来是很久没有人触碰过这些棋子了

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"yongdao1",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "qizi" : "
每个棋子上刻有一个数字，从一至九，排列整齐。
",
]));

  setup();
}
void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要挪动什么？\n");
  if(arg=="qizi")
    return notify_fail("请按九宫之法移动棋子\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="294753618")
    {
      message_vision(HIR "只见四周墙壁小孔中喷射出火焰，直向$N扑来！\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "被烧成了飞灰。\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N心中一惊，急忙躲避，但还是被火焰燎到！\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N按照九宫之法将棋子一一摆好，一道暗门突起，$N大喜，低头钻了进去。\n", me);
      me->move(__DIR__"yaoguang");
      return 1;
    }
}

