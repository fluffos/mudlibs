// /d/welcome/welcome.c
// 海洋II
// 星星(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "世界之树");
  set ("long", @LONG
这里是古村的正中心，一个很宽阔的广场，上面铺着青石地面。中
央一棵大树(tree)盘根错节，已经看不出它究竟有着多大的树龄了，它
就是传说中的世界之树——传说就是它带来了整个世界的绿色，是自然
之祖。树下站着一个老者，正耐心地辅导着新手。
==== 如果你需要帮助请输入指令 ask lao about here ====
==== 如果你需要修改先天属性   help cgift ====
LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"dangpu",	
"north" : __DIR__"qianzhuang",	
"west" : __DIR__"ck",	
"east" : __DIR__"new1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"jing" : 1,
 //"/clone/gift/newbieliwu" : 1,
]));
  set("outdoors","welcome");
//  set("sleep_room", 1);
  set("roomif","$botten#新手任务|完成任务|新手帮助|出村:ask lao about job|ask lao about ok|ask lao about here|ask lao about 出村$#");
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);
set("chatroom",1);
  setup();
  replace_program(ROOM);
	"/clone/board/newbie_b"->foo();
}
void init()
{
	object me;
me=this_player();
if( me->query_temp("netdead")) 
"/cmds/usr/quitgame"->main(me);
	return;
}
         