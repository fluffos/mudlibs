// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "朱紫国的国王，头戴朱金冠，手执紫金杖。\n");
  set("title", "朱紫国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set_level(10);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("force_factor",120);

  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
        "name":   "朕乃朱紫国国王也，近来身体不适，久医难愈。",
        "王后":   "朕之后，唯金圣宫后已别三年矣。",
        "金圣宫": "金圣宫不在已三年矣。",
      ]));

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}
