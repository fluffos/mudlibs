//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// guanyin.c ¹ÛÒôÆĞÈø
// By Dream Dec. 19, 1996
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("¹ÛÒôÆĞÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
   set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ğÉí¡£Ã¼ÈçĞ¡ÔÂ£¬ÑÛËÆË«ĞÇ¡£À¼ĞÄĞÀ×ÏÖñ£¬
Ş¥ĞÔ°®µÃÌÙ¡£Ëı¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
   set("gender", "Å®ĞÔ");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "Æ¶É®");
   set("rank_info/respect", "ÆĞÈøÄïÄï");
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
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
 

   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("ÄÏº£ÆÕÍÓÉ½", 1, "ÆĞÈø");

   setup();
   carry_object("/d/qujing/nanhai/obj/jiasha")->wear();

}
void announce_success (object who)
{
  int i;
  object me = this_object();

  if (who->query("combat_exp") < 10000)
    return;
  if( ! who->query_temp("fired") )
     return;
   if(who->query("obstacle/hf")  == "done")
    return; 
  if (! who->query_temp("obstacle/heixiong_killed"))
    return;
  if (who->query("obstacle/yj") != "done")
    return;  
    
  i = random(900);
  who->add("obstacle/number",1);
  who->set("obstacle/hf","done");
   who->add("combat_exp",i+9000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"ºÚ·çÉ½ÊÕ½µºÚĞÜ¹Ö£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+who->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚËÄ¹Ø£¡\n"NOR,users());
        tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(i+9000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+
               "Ê®µãÃÅÅÉ¹±Ï× ¶şµã³É³¤ÉÏÏŞ£¡\n");

	  command("wave");
	  who->save();
}

void die(object me)
{
        destruct(me);
}

