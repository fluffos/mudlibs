//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("东方英雄",({"star hero","hero","star"}));
  set("gender", "男性");
  set("title", "参水星官");
  set("age", 46);
  set ("long", @LONG
纪念日:
-------------------------------------------------------------------------
年龄33 : 道行 303.33.3, 最后一战用时33m, 然后和 green 结婚  :)
年龄46 : 终于修成不堕轮回, 成了老不死  :D
年龄53 : 不打算继续陷在险恶的江湖中, 整天学学游手好闲(如果还来的话)  :P
-------------------------------------------------------------------------
LONG);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1564041);
  set("daoxing", 1564041);
  set("qi", 1221);
  set("max_qi", 1221);
  set("jing", 1770);
  set("max_jing", 1770);
  set("neili", 5133);
  set("max_neili", 2567);
  set("mana", 6101);
  set("max_mana", 3051);
  set("force_factor", 140);
  set("mana_factor", 153);
  set("str", 25);
  set("per", 15);

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

setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"英雄棒"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"英雄战甲"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"战袍"NOR);
}

