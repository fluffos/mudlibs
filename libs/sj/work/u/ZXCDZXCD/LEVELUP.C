inherit ROOM;
#include <ansi.h>
void create()
{
         set("short",HIY"高科技研究室"NOR);
         set("long",@LONG
正在建设中…………………………………………

LONG);
      set("exits",([
               "out":"/d/wizard/wizard_room",
                        ]));
    setup();
}
void init()
{
     add_action("do_levelup","levelup");
}
int do_levelup()
{
 object me=this_player();
  if (me->query("combat_exp") >= me->query("last_levelup") + me->query("level")*1000);
 else return notify_fail("你的经验值还没到升级的时候呢！\n");
 if (me->query("money") < me->query("level")*2000)
 return notify_fail("你带的钱不够！\n");
 
 me->add("level",1);
 me->add("qianli",5);
 me->add("max_qi",10);
 me->add("max_jing",10);
me->add("money",-(me->query("level")*2000));
 write("你升级了！\n",me);
 me->set("last_levelup",1000+me->query("level")*1000)
;
 return 1;
}
