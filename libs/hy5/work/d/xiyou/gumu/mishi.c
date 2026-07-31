#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIW"宝库入口"NOR);
  set ("long", @LONG


这里一片昏暗。你什么也看不清，你感觉脚下似乎有什么东西
定睛细看原来是一堆骷髅，好像是盗墓者的骸骨，突然你的头好像
撞在石头(stone)上了。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fox" : 4,
]));

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"bianhou",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
一块圆形的石头
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
  if(arg=="stone")
    return notify_fail("你看透了么？\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="left")
    {
      message_vision(HIR "一阵雨点般的石头雨砸了下来！\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "在古墓密室被活活砸死了！\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N心中一惊，急忙躲避，但还是被石头砸到！\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N慢慢旋转着石头，“喀嗒”一声，你眼前的墙壁突然裂开，$N就势钻了进去！\n", me);
      me->move(__DIR__"baoku");
      return 1;
    }
}

