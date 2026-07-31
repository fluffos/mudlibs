//sgzl
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("天蓬元帅",({"tianpeng yuanshuai","yuanshuai","tianpeng"}));
  set("gender", "男性");
  set("title", "天河");
  set("age", 35);
  set("long", "    \n一位威风凛凛的大帅，负责巡查天河。\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1200000);
  set("daoxing", 1000000);
  set("qi", 1600);
  set("max_qi", 1600);
  set("jing", 2200);
  set("max_jing", 2200);
  set("neili", 1500);
  set("max_neili", 1500);
  set("mana", 2500);
  set("max_mana", 2500);
  set("force_factor", 40);
  set("mana_factor", 40);
  set("str", 25);
  set("per", 13);


	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
  set("inquiry", ([
  "name"   : "天蓬元帅",
  "here"   : "天河",
]));


setup();

carry_object(__DIR__"obj/jiuchipa")->wield();
carry_object(__DIR__"obj/jinjia")->wear();

}

int accept_fight(object me)
{
  message_vision("天蓬元帅对$N把眼一瞪，喝道：呔，大胆，还不退下！\n", me);
  return 0;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

int heal_up()
{

  if( environment() && !is_fighting() ) 
    {
    call_out("leave", 1);
    return 1;
    }
    return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "吐了口唾沫，骂道：下次别叫老子碰到！
天蓬元帅走了出去。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}


