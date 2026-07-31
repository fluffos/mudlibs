//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
	set_name("¹ÛÒôÆÐÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
	set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ðÉí¡£Ã¼ÈçÐ¡ÔÂ£¬ÑÛËÆË«ÐÇ¡£À¼ÐÄÐÀ×ÏÖñ£¬
Þ¥ÐÔ°®µÃÌÙ¡£Ëý¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
	set("gender", "Å®ÐÔ");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "Æ¶É®");
	set("rank_info/respect", "ÆÐÈøÄïÄï");
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
	set("combat_exp", 10000000);



	setup();
	initlvl((1260+random(1260)),0);
	carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
	carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  
  int i;

  if(!who) return;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/huoyun") == "done")
    return;
  if (! who->query_temp("obstacle/hong_killed"))
    return;
  if (who->query("obstacle/wuji") != "done")
    return;  

  	i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/huoyun","done");
  who->add("combat_exp",i+18000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"¿ÝËÉ½§»ðÔÆ¶´.ÊÕ·þºìº¢¶ù");
  message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÊ®ËÄ¹Ø£¡\n"NOR,users());
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(i+18000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+"Ê®µãÃÅÅÉ¹±Ï× ¶þµã³É³¤ÉÏÏÞ£¡£¡\n");
  who->save();
}
