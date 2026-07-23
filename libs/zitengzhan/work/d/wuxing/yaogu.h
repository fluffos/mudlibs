// yaogu.h

inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  int north=(POS/10+9)%10*10+POS%10,south=(POS/10+1)%10*10+POS%10,
      east=POS/10*10+(POS%10+1)%10,west=POS/10*10+(POS%10+9)%10;
  set ("short", "万劫谷");
  set ("long", @LONG

这里就是妖谷，聚集着很多五行妖。他们都化身为常
物修炼，若是你不去打搅它们，它们也不会害你。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yaogu"+north,
  "south" : __DIR__"yaogu"+south,
  "east" : __DIR__"yaogu"+east,
  "west" : __DIR__"yaogu"+west,
]));
  set("objects", 
	  ([ //sizeof() == 1
	  "/d/shenqi/yao/yaocai" : random(2),
	          ]));
  set("outdoors",1);
  set("alternative_die",1);
  setup();
}

void init() {
  add_action("do_back","back");
}

int do_back()
{
   object me=this_player();
   if(me->is_fighting()) return notify_fail("你现在正忙着呢...。\n");
   if(me->is_busy()) return notify_fail("你现在正忙着呢...。\n");
   me->move("/d/wuxing/shentai");
   message_vision("\n");
   message_vision(HIG"$N念动符文，遁回了封神台\n"NOR,me);
   message_vision("\n");
   return 1;
}

void alternative_die(object who)
{
   object yaoguai;
   int lostexp;
   if (!userp(who)) {
    set("alternative_die",0);
    who->die();
    set("alternative_die",1);
       return;
   }
   if ((!(yaoguai=who->query_temp("wuxingyao/ob")))|| who->query_temp("last_damage_from")!=yaoguai)
   {
	   set("alternative_die",0);
	   who->die();
	   set("alternative_die",1);
	   return;
   } else
   {
   if (who->query_temp("wuxingyao/ob")) destruct(who->query_temp("wuxingyao/ob"));
   message_vision(HIR"就在$N三魂七魄尽散之际，清福神浮现于空，救起了$N。\n"NOR,who);
   who->move("/d/wuxing/shentai");
   who->clear_condition();
   who->set("eff_kee",who->query("max_kee"));
   who->set("eff_sen",who->query("max_sen"));
   who->set("kee",who->query("max_kee"));
   who->set("sen",who->query("max_sen"));
   who->remove_all_killer();
   who->start_busy(2);
//   message_vision(HIY"$N随神秘老人来到木屋旁，身上的伤也全好了。\n"NOR,who);
//   message_vision(HIY"神秘老人对$N说道：你虽未死，但亦应该受到惩罚。\n"NOR,who);
//   message_vision(HIY"神秘老人手再一挥，$N顿时觉得身上少了点什么。\n"NOR,who);
   if (who->query("combat_exp")) {
         lostexp=who->query("combat_exp")/10;
         if (lostexp>20000) lostexp=20000;
         who->add("combat_exp",-lostexp);
   }
   who->add("wuxing/dead",1);
   if (who->query("wuxing/dead")>4) {
//         tell_object(who,"你已经累计死亡达到5次，级别自动减一。同时死亡次数重新计算。\n");
         if (who->query("wuxing/level")>1) who->add("wuxing/level",-1);
         who->set("wuxing/dead",0);
   }
   return;
   }
}


/* void greeting(object me,object env) {
  if (!me || environment(me)!=env) return;
  tell_object(me,MAG"百花丛中出现一袭倩影，你不由停住脚步，想看个仔细。\n"NOR);
  
  // mon
  if(MISC_D->random_capture(me,200,0)) return;

  call_out("greeting1",2,me,env);
}

void greeting1(object me,object env) {
  object xian;

  if (!me || environment(me)!=env) return;
 tell_object(me,MAG"你的眼前一亮，一位气度不凡的仙女轻移莲步，正向你款款走来。\n\n"NOR);

  xian=new(__DIR__"npc/huaxian");
  xian->move(env);
  xian->set("target",me);
} */
