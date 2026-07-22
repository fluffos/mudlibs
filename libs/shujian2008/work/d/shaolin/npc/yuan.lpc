// yuan.c 元广波

#include <ansi.h>

inherit NPC;

//int waiting(object me);
//int checking(object me);
//int do_chase(object me);
//int do_kill(object me, object dest);
//void 
string ask_me();

void create()
{
       set_name("元广波", ({ "yuan guangbo", "yuan" }) );
       set("title", "海砂帮帮主");
       set("gender", "男性" );
       set("shen_type", -1);
       set("age", 50);
       set("str", 30);
       set("con", 10);
       set("int", 10);
       set("dex", 30);
       set("long",
               "这是以毒盐横行江南的私盐大盗，一脸阴狠之色。\n" );
       set("combat_exp", 600000);
       set("attitude", "peaceful");
       set("chat_chance", 2);
       set("chat_msg", ({
           "元广波说道: 海砂帮是天下有名的大帮会，你听说过吗?\n",
         (: random_move :)
         }) );
       set("max_qi", 3000);
       set("max_jing", 400);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jiali", 150);
       set("shen_type", -1);
       set("env/wimpy", 60);
       set("score",10000);
       set_skill("force", 150); 
       set_skill("unarmed", 150);
       set_skill("huntian-qigong",150);
       set_skill("blade", 150);
       set_skill("cibei-dao",180);
       set_skill("dodge", 120);
       set_skill("ding-dodge", 120);
       set_skill("parry", 150);
       set_skill("cuff",150);
       set_skill("luohan-quan",150);
       map_skill("dodge", "ding-dodge");
       map_skill("blade","cibei-dao");
       map_skill("parry","cibei-dao");
       map_skill("cuff","luohan-quan");
       prepare_skill("cuff","luohan-quan");
       setup();
//       carry_object("/d/city/obj/blade")->wield(); 
       carry_object("/d/city/obj/cloth")->wear();
//       carry_object("/u/hunthu/npc/obj/qzling1");
 }
  void unconcious()
{
    object me,ob;
    me=this_player();
//    ob=load_object("/u/hunthu/npc/obj/qzling1");
  //        if (objectp(present(ob,this_object()) {
          if ((string)me->query_temp("promotion_target")=="海砂帮帮主元广波") {
             if (query_temp("last_damage_from") == me ){
             add_money("gold", 10);
            //message_vision("\n$N挣扎着吐出几个字：是......" + query("hire")[0..1] + "......。\n", this_object());
            ob=new("/u/hunthu/npc/obj/qzling");
             ob->move(this_object());   
               } else
            message_vision("\n$N邪恶地笑道：可惜你永远拿不到青竹令了...\n", this_object());
              destruct(ob); 
       }
       ::die();

//   ::unconcious();  
}
