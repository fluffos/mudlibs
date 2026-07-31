//Cracked by bear
// Room: /d/nanhai/chanfang
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

这是普陀山门人弟子们练功打坐的地方。只见几个僧人正在
一边吆喝着舞拳弄脚，另外几个在练习兵器。屋角摆着几把
铁杖铁枪。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang",
]));
 set("no_clean_up", 1);
set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchan" : 1,
]));

  setup();
}

void init()
{
   add_action("do_hear","hear");
}

int do_hear()
{
	object me=this_player();
  	if( !query("jiangjing") || (string)me->query("family/family_name")!="南海普陀山" )
     		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
      	if( me->query("kee")<30 || me->query("sen")<30 )
      		return notify_fail("你现在太累了。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的师门贡献不够。\n");
	tell_object(me,"你在旁边听着，听着。禅心更加稳固了。\n");
  	me->start_busy(5);
	me->improve_skill("lotusforce",1+random(me->query_spi()+me->query_int())/2);
   	me->improve_skill("buddhism",1+random(me->query_spi()+me->query_int())/2);
	me->add("faith",-10);
	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
  	return 1;
}