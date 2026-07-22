
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","古赤壁战场");
  set ("long", @LONG
赤壁古称蒲圻，缘起于三国东吴黄武二年设置蒲圻县。东汉建安十
三年，孙权、刘备联手抗曹，在当地赤壁镇筹划了震古铄今、驰名中外
的“赤壁大战”，一举开创了鼎足三分的局面，对中国历史产生了重大
影响。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing1",
          ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

void init()
{
   add_action("do_linghui","linghui");
 
}

int do_linghui(string arg)
{
   object ob;
   string time,oldtime,msg;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_fu_action7"))
    return 0;
   if(ob->query("execute_quest/yijianshu_fail"))
   return notify_fail("你什么也领会不出来！\n");
   if(!arg||arg!="弈剑术")
   return notify_fail("你要领会什么？\n");
   if(time()-ob->query_temp("bai_fu_action7_busy")<120)
   return notify_fail("你气血翻滚，无法继续领会！\n");
   time=NATURE_D->game_time();
   
   if(ob->query_temp("bai_fu_action8")){
      oldtime=ob->query_temp("bai_fu_action8");
      if(time[sizeof(time)-8..sizeof(time)]!=
         oldtime[sizeof(oldtime)-8..sizeof(oldtime)]
        ){
          msg="望着古战场的遗址，你回想与傅采林的一战。你感受到傅采林创出弈剑术\n"+
              "的本意。没有足够的力量，你将被剥夺享受生命神迹的权利。\n";          
          tell_object(ob,msg);
          ob->set("execute_quest/yijianshu_fail",1);
          return 1;
      }
      msg="你隐约感受到生命就想藏在泥土里的种子和根茎，绽放在外的花叶纵有荣枯，\n"+
          "地下的生机却永远长存。\n";
      ob->delete_temp("bai_fu_action7");
      ob->delete_temp("bai_fu_action8");
      ob->delete_temp("bai_fu_action7_busy");
      ob->set("execute_quest/yijianshu",1);
      tell_object(ob,msg);
      return 1;
  }
  msg="望着古战场的遗址，你回想与傅采林的一战。你感受到傅采林创出弈剑术\n"+
              "的本意。没有足够的力量，你将被剥夺享受生命神迹的权利。\n";
  tell_object(ob,msg);
  ob->set_temp("bai_fu_action8",time);
  ob->set_temp("bai_fu_action7_busy",time());
  return 1;
}