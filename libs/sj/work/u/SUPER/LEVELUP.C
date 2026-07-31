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
  if (me->query("combat_exp") >= me->query("level")*2000 + (me->query("level")-1)*3000);
 else return notify_fail("你的经验值还没到升级的时候呢！\n");
 if (me->query("money") < me->query("level")*2000)
 return notify_fail("你带的钱不够！\n");
 
 me->add("level",1);
 me->add("qianli",5);
 me->add("max_qi",random(5));
 me->add("max_jing",random(3));
me->add("money",-(me->query("level")*2000));
 write("你升级了！\n",me);
;
 return 1;
}
