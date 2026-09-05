// Room: /shenlongjiao/shanquan.c
// kiden 06/08/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"濯垢泉"NOR);
        set("long", @LONG
一股热气腾腾的白雾将你团团围住，你已经来到了濯垢泉边。不知
何时，神龙岛发现了这汪温泉，洪教主便加入数十种灵药，放入泉中，
听说有疗百毒之奇效，也不知道是真是假。不少神龙弟子都在此沐浴，
你不妨也来试试看（bath）。
LONG
        );
  set("outdoors", "shenlongdao");
  set("resource/water", 1);

        set("exits", ([
                "south" : __DIR__"shanquan",        
        ]));
        setup();
}
void init()
{
add_action("do_bath","xizao"); 
add_action("do_bath","bath"); 
}

int do_bath()
{       
  string *msgs = ({
    "$N捧起泉水往身上慢慢地浇下来。\n",
    "$N用热泉水往自己身上一浇。\n",
    "$N舀起热热的泉水，往身上浇下来。\n",
    "$N躺在热泉水中，泡着自己的身体。\n",
    "$N坐进热气腾腾的泉水。\n",
    "$N泡在热泉水中，慢慢地坐浴。\n",
  });
  object me = this_player();

  if (me->is_busy())
    return notify_fail ("你不忙着洗澡呢吗？！\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1);
  if ((me->query("kar")+me->query_temp("spring/cure_times")) > 40)
  {
    if (! me->update_condition())
      return 1;
    message_vision ("$N红光满面地站了起来，走到泉边。\n",me);
    me->clear_condition();
    me->unconcious();
  }
  me->add_temp("spring/cure_times",1);
  return 1;
}
/***********************************
int valid_leave(object me, string dir)
{
  me->set_temp("spring/cure_times",0);
  return ::valid_leave(me, dir);
}
****************************************/
