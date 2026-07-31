// by snowcat 12/9/1997

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "天竺国国王，身披龙袍，神态庄严。\n");
  set_level(10);
  set("title", "天竺国");
  set("gender", "男性");
  set("age", 50);
  set("attitude", "peaceful");
  set("shen_type", 1);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);

  set("inquiry", ([
    "name" : "朕乃天竺一国之君也，寡人有一公主。",
    "here" : "天竺国也。",
    "天竺" : "天竺国也。",
    "天竺国" : "天竺国也。",
  ]));
  setup();
  set_temp("no_return",1);
  carry_object("/d/obj/cloth/longpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
}