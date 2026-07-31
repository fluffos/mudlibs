// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("ÅþÀ¶ÆÅ", ({"pilan po", "po", "daogu"}));
  set("title", "µÀ¹Ã");
  set("gender", "Å®ÐÔ");
  set("age", 58);
  set("per", 26);
  set("rank_info/respect", "ÆÐÈø");
  set("combat_exp", 1000000);
  set("combat_exp", 1500000);

  set_skill("snowsword", 90);
  set_skill("sword", 90);
  set_skill("dragonfight", 90);
  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("spells", 90);
  set_skill("dragonstep", 90);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_jing", 9000);
  set("max_qi", 9000);
  set("max_jing", 9000);
  set("neili", 9000);
  set("max_neili", 9000);
  set("neili", 9000);
  set("max_neili", 9000);
  set("force_factor", 90);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/pansi") == "done")
    return;
  if (who->query_temp("obstacle/pansi_killed") < 15)
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/pansi","done");
  who->add("combat_exp",i+36000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"ÅÌË¿Áë¾¡³ýÖ©Öë¾«»Æ»¨¹Û½µ·þòÚò¼¾«£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(i+36000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+" Ê®µãÃÅÅÉ¹±Ï× ¶þµã³É³¤ÉÏÏÞ£¡£¡\n");
  who->save();
}
ÿ
