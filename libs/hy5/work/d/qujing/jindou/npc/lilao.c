// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("ÀîÀÏ¾ý", ({"li laojun", "li", "laojun"}));
  set("gender", "ÄÐÐÔ");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("combat_exp", 10000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);

  set("force_factor",125);
  setup();
  initlvl((1430+random(1430)),18);
  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jindou") == "done")
    return;
  if (! who->query_temp("obstacle/jindou_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jindou","done");
  who->add("combat_exp",i+25000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"½ð¶µÉ½´óÕ½¶À½ÇÙî£¬ÌæÀÏ·òÊÕ»ØÇàÅ££¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(i+25000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+"Ê®µãÃÅÅÉ¹±Ï× ¶þµã³É³¤ÉÏÏÞ£¡£¡\n");
  who->save();
}

ÿ
