
// jia.c


inherit NPC;
inherit F_DEALER;

void create()
{
//  reload("dingxiang_yaopu_zhou");
  set_name("周大夫", ({"zhou daifu", "zhou", "daifu"}));
        set("title", "药铺掌柜");
        set("gender", "男性");
  set("shop_id",({"zhou dafu", "zhou", "dafu"}));
  set("age", 37);
  set("combat_exp", 30000);
   set("long","这是定襄城内最有名气的大夫，每天来找他看病的人很多。\n");
  set("age", 38);
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);

  setup();
  
}

void init()
{
  ::init();

}
int regenerate()
{
        set("called", 0);
        return 1;
}
