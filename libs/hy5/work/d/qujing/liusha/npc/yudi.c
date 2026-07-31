//Cracked by Roath
 
inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("Ä¾²æÐÐÕß", ({ "mucha xingzhe", "mucha", "xingzhe" }));
   set("long","¹ÛÒôÆÐÈø×ùÏÂÍ½µÜ¡£");
   set("gender", "ÄÐÐÔ");
   set("age", 35);
   set("attitude", "peaceful");
   set("max_qi", 5000);
   set("max_jing", 5000);
   set("max_jing", 5000);
   set("neili", 4000);
   set("max_neili", 2000);
   set("force_factor", 145);
   set("max_neili", 3000);
   set("neili", 6000);
   set("mana_factor", 150);
   set("combat_exp", 20000000);
   set("combat_exp",150000000);
   set_skill("literate", 150);


   setup();
   initlvl((300+random(220)),0);
   carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
   carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void init()
{
  object ob = this_object();
  object me = this_player();
  int i;
  if( ! me->query_temp("sha_killed") 
    ||! me->query("obstacle/huangfeng")
    || me->query("combat_exp") < 10000
    || me->query("obstacle/liusha") == "done")
    return;
  i = random(500);
  me->add("obstacle/number",1);
  me->set("obstacle/liusha","done");
      me->add("combat_exp",i+12000);
        me->add("potential",i*8);
  me->add("mpgx",10);me->add("expmax",2);
  command("chat "+me->name()+"Á÷É³ºÓ½µ·þ¾íÁ±´ó½«£¡");
message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+me->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÆß¹Ø£¡\n"NOR,users());
  tell_object (me,"ÄãÓ®µÃÁË"+chinese_number(i+12000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+
               "Ê®µãÃÅÅÉ¹±Ï× ¶þµã³É³¤ÉÏÏÞ£¡\n");
  me->save();
  destruct(ob); 
     return;
}
