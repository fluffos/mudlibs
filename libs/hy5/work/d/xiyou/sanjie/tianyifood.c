// sanjie tianyifood.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

厨房里热气腾腾，有一个胖道士正在煮着一天的饭食，如果
你饿了，可以在这里搞点吃的东西填填肚子。那个胖子好象
正在煮狗肉耶？！
LONG);

  set("exits", ([
  "south" : __DIR__"tianyilang4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bowl" : "锅里是刚刚做的狗肉，你要饿了也可以拿些去吃。",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoyuanzi" : 1,
  "/d/xiyou/sanjie/obj/shuibei" :1,
]));
  set("clean_up", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("gou rou", this_player())))
            return notify_fail("吃完狗肉再走嘛！如果给师傅知道了可不得了。\n");
	if((present("shui bei", this_player())))
	    return notify_fail("你不能把水杯也带走！你拿走了别人拿什么喝水。\n");
    return ::valid_leave();
}

