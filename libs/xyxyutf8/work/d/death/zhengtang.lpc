// wri by bear
inherit ROOM;
#include <ansi.h>

int do_hear();

void create ()
{
  set ("short", "阎罗宝殿");
  set ("long", @LONG

这里便是名闻天下，令人提起心惊胆寒的阎罗地府。人死后都会
在这里受到应有的处置。正前一张大桌，后面坐着阎罗王，旁边
立着崔判官。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"new-walk5",
  "north": __DIR__"walk1",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
//  __DIR__"npc/panguan" : 1,
]));
  setup();
  call_other("/obj/board/shengsi_b", "???");
}  

void init()
{
   add_action("do_hear","hear");
}

int do_hear()
{
	object me=this_player();
  	if( !query("jiangjing") || (string)me->query("family/family_name")!="阎罗地府" )
     		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
      	if( me->query("kee")<30 || me->query("sen")<30 )
      		return notify_fail("你现在太累了。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的师门贡献不够。\n");
	tell_object(me,"你听着听着似乎若有所悟。\n");
  	me->start_busy(5);
   	me->improve_skill("tonsillit",1+random(me->query_spi()+me->query_int())/2);
   	me->improve_skill("gouhunshu",1+random(me->query_spi()+me->query_int())/2);
	me->add("faith",-10);
	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
  	return 1;
}





