//Cracked by Roath
#include <ansi.h>

inherit NPC;

string *names = ({
  "仙童",
  "仙将",
  "仙官",
  "仙吏",
});

string *ids =   ({
   "xian tong",
   "xian jiang",
   "xian guan",
   "xian li",
});

void create()
{

  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "男性" );
  set("age", 33);
  set("long", "兜率宫太上老君的下属，负责炼丹烧火，跑前跑后。\n");
  set("class", "xian");
  set("combat_exp", 25000);
  set("daoxing", 50000);

  set("attitude", "peaceful");


  set("max_qi", 500);
  set("max_jing", 500);
  set("mana", 700);
  set("max_mana", 700);
  set("mana_factor", 20);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 5);



  setup();
carry_object(__DIR__"xianpao")->wear();
}


