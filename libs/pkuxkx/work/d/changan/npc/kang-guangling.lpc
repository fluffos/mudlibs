// huoji. 药铺伙计
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("康广陵", ({ "kang guangling", "kang" }));
	set("str", 35);
	set("title", GRN"函谷八友 "CYN"琴颠"NOR);
	set("gender", "男性");
	set("age", 35);
	set("long", "他是函谷八友的老大琴颠康广陵。\n");
  set("qi", 1500);
  set("max_qi", 1500);
  set("jing", 1200);
  set("max_jing", 1200);
  set("neili", 800);
  set("max_neili", 800);
  set("jiali", 50);

  set("combat_exp", 80000);
  set("score", 1000);
    
  set_skill("literate",200);
  set_skill("force", 80);
  set_skill("dodge", 80);
  set_skill("parry", 70);
  set_skill("hand",70);
  set_skill("strike", 80);
  set_skill("sword",60);

  set_skill("changhen-jian",70);
  set_skill("zhemei-shou",60);
  set_skill("liuyang-zhang",70);
  set_skill("yueying-wubu",60);
  set_skill("bahuang-gong", 70);

  map_skill("force", "bahuang-gong");
  map_skill("strike","liuyang-zhang");
  map_skill("dodge", "yueying-wubu");
  map_skill("hand", "zhemei-shou");
  map_skill("parry", "liuyang-zhang");
  map_skill("sword", "changhen-jian");

  prepare_skill("strike","liuyang-zhang");
  prepare_skill("hand","zhemei-shou");

	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/changan/obj/guqin",
	  "/d/changan/obj/pipa",
	  "/d/changan/obj/zheng",
	  "/d/changan/obj/shaw",
	  "/d/changan/obj/flute",
	  "/d/changan/obj/drum",
	  "/d/changan/obj/cymbals",
	}));

	set("shen_type",1);
	set("score",200);
	setup();
  carry_object("/d/lingjiu/obj/changpao")->wear();
  carry_object("/clone/weapon/jian")->wield();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}