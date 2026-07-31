#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "村长家");
  set ("long", @LONG
这里是村长的家，屋内却是颇为朴素，墙边靠着几个农具，
墙角一张竹床，看着就让人想睡觉（输入指令 sleep）。与普
通村民家没什么区别。平常弟子们饿了可以到这里要 （输入
指令 yao）些食物。房中灶火正旺，一个大厨师正忙的满头大
汗。屋角放着一个大水缸。  
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chushi" : 1,
 
]));
//  set("outdoors","welcome");
  set("sleep_room", 1);
set("roomif","$botten#要食物|睡觉:yao|sleep$#");

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

void init()
{
	add_action("do_naqu","yao");
}


int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	//if(! arg)	return notify_fail("你要拿取什么？\n");
	if(me->query("combat_exp",1) > 80000 && !wizardp(me) && me->query("nbjob",1)!=3 )
{
message_vision("厨师笑道：$N你到外面自己去买吧。\n",me);
		return 1;
}
 if (present("mantou",me)) 
{
message_vision("厨师笑道：$N先把身上的吃完再来吧。\n",me);
return 1;
}


 if (present("water",me)) 
{
message_vision("厨师笑道：$N先把身上的喝完再来吧。\n",me);
return 1;
}
me->set("food",100);
me->set("water",100);
me->set_temp("nbjob4",1);
sth=new(__DIR__"obj/mantou");
sth->move(me);
sth=new(__DIR__"obj/water");
sth->move(me);
message_vision("厨师将一个馒头和一碗清水递到$N手中，笑道：你慢用。\n",me);
	return 1;
}