//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

string *names = ({
  "[32möèÓã[m",
  "[31möùÓã[m",
  "[36m´óòş[m",
  "[33m¾¨Óã[m",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"fish"}));
  set("gender", "ÄĞĞÔ");
  set("age", 30*i);
  set("attitude", "aggressive");
  set("combat_exp", 20000*i);
  set("per", 10);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("staff", 10*i);
  set_skill("club", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_jing",100*i);
  set("max_qi",100*i);
  set("max_jing",100*i);
  set("neili",100*i);
  set("max_neili",100*i);
  set("max_neili",100*i);
  set("force_factor",10*i);
  setup();
}

