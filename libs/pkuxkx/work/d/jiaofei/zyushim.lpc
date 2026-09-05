// Room: /shenlongjiao/shanquan.c
// kiden 06/08/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"男澡堂子"NOR);
        set("long", @LONG
这里是男浴室，浴室中间是一个大大的浴池，里面是从地下引上来的泉水，
可以泡澡(bath),浴池的旁边放着很多用来搓澡的木床，跟搓澡工说一声就
可以搓澡了。
LONG
        );
  set("outdoors", "shenlongdao");
  set("resource/water", 1);
  set("objects", ([
		"/d/jiaofei/npc/cuozaogong" : 1,
	]));
        set("exits", ([
                "west" : __DIR__"zyushi",        
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
  return 1;
}