#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "斜巷");
  set ("long", 
"       这里好象已是路的尽头，下方有一条窄窄的斜巷，里面黑黑的望
不到底，不知能通到何处。巷口挂着一个"YEL"木牌"NOR"，写着“入禁地者
死”五个字。
"NOR);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yongdao5",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/bianfu" : 1,
  __DIR__"npc/mahuang" : 1,    
]));
        set("TER","洞窟");
  set("item_desc", ([ /* sizeof() == 1 */
        "门" : "一道暗门，似乎可以推推（push）（tui）看。\n",
        "暗门" : "一道暗门，似乎可以推推（push）（tui）看。\n",
        "door" : "一道暗门，似乎可以推推（push）（tui）看。\n",
        "木牌" : "一道暗门，似乎可以推推（push）（tui）看。\n",
        "牌" : "一道暗门，似乎可以推推（push）（tui）看。\n",
])
);      
  setup();
}

void init()
{
    add_action("do_push", "push");
    add_action("do_push", "tui");
}
    
int do_push(string arg)
{
    object me=this_player();

    if (arg != "door" && arg != "门" && arg != "暗门")
                return notify_fail("你东张西望看了半天，没找到什么可推的。\n");
    if (present("mahuang guai", this_object()))
        return notify_fail("没看见门口守着人？\n");
    if (present("bianfu jing", this_object()))
        return notify_fail("没看见门口守着人？\n");
    tell_object(me, "你伸手一推墙上的暗门。\n");
    tell_object(me, "突然脚下一陷。\n");
        message_vision("$N脚下一陷，落了下去。\n", me);
        me->move(__DIR__"baihu");
        return 1;
}

