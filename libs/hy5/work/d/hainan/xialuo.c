// Room: /d/hainan/xialuo 
#include <ansi.h>
inherit ROOM; 
 
void create() 
{ 
  set ("short", "下落中");
  set ("long", @LONG
四边白雾一片,呼啸而生的罡风吹得人眼睛都睁不开来.眼前的景物
飞快的掠过,你只能感觉到自己在快速的下降中.
LONG);

  setup();
}
int init()
{
    object me;
    me=this_player();
    call_out("greeting",1,me);
}
void greeting(object me)
{ 
       tell_object(me,RED+"只听到'通'的一声巨震,你掉落海中!\n"+NOR);
me->unconcious();
     if (me->query("gender")=="男性")
	 me->move(__DIR__"xuanya.c");
     else 
      me->die();

}
