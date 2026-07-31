//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("½ÒÚÐ", ({ "jie di"}));
   set("title", "¹ÛÒôÊÌÕß");
   set("long", @LONG
¹ÛÒôÆÐÈøµÄÊÌÕß¡£
LONG);
   set("gender", "ÄÐÐÔ");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "Æ¶É®");
   set("class", "bonze");
   set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_qi", 5000);
   set("max_jing", 5000);
   set("max_jing", 5000);
   set("neili", 4000);
   set("max_neili", 2000);
   set("force_factor", 145);
   set("max_neili", 3000);
   set("neili", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
  

   setup();
   initlvl((500+random(500)),1);
   carry_object("/d/qujing/nanhai/obj/sengpao")->wear();
   //carry_object("/d/qujing/nanhai/obj/budd_staff")->wield();

}

void announce_success (object who)
{
  int i;
  object horse=new("/d/qujing/yingjian/obj/horse");
  object here;
  object me = this_object();
  here=environment(who);

  if (who->query("combat_exp",1) < 1000000)
    return;
  if (who->query("obstacle/yj") == "done")
    return;
  if (! who->query_temp("obstacle/long_killed"))
    return;
  if (who->query("obstacle/sc") != "done")
    return;  
    
  i = random(900);
  message_vision (HIY"Ò»Æ¬ÏéÔÆ¹ýºó£¬½ÒÚÐ³öÏÖÔÚÄãÃæÇ°£¡\n",who);
  message_vision (HIY"\nÖ»Ìý½ÒÚÐÅ­³âÒ»Éù°½ÈòÁúÍõÓñÁúÈýÌ«×Ó»¹²»°Ý¹ýÈ¡¾­ÈË£¡\n",who);
  message_vision (HIY"\nºöÈ»°×ÁúÆËµ¹ÔÚµØ£¬±ä³ÉÁËÒ»Æ¥°×Âí¡£\n",who);
  horse->move(here);
  who->add("obstacle/number",1);
  who->set("obstacle/yj","done");
  who->add("combat_exp",i+8000);
  who->add("potential",i*8);
  who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"Ó¥³î½§½µ·þ°×ÁúÂí£¡");
message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÈý¹Ø£¡\n"NOR,users());
        tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(i+8000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+
               "Ê®µãÃÅÅÉ¹±Ï× ¶þµã³É³¤ÉÏÏÞ£¡\n");

	  command("wave");
	  who->save();
}
