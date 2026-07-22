// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// Room: /d/qujing/wudidong/inner-tang.c
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

大殿里无数小妖来回奔走，正在准备大开筵席。一个女子正中高坐，
云髻低垂，金钗半溜，正笑吟吟地指挥着众小妖，全不顾自己香汗淋
漓。你往人群中一混，一时倒也无人发觉。这个地方也是传授人肉
包子做法的地方。你只要来(hear)，就可以了。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tang-gate",
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
  	if( !query("jiangjing") || (string)me->query("family/family_name")!="陷空山无底洞" )
     		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
      	if( me->query("kee")<30 || me->query("sen")<30 )
      		return notify_fail("你现在太累了。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的师门贡献不够。\n");
	tell_object(me,"你在旁边听着，听着。不禁想起了人肉包子的美味。\n");
  	me->start_busy(5);
	me->improve_skill("huntian-qigong",1+random(me->query_spi()+me->query_int())/2);
	me->improve_skill("yaofa",1+random(me->query_spi()+me->query_int())/2);
	me->add("faith",-10);
	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
  	return 1;
}
