//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("单身贵族",({"star liz","liz","star"}));
  set("gender", "女性");
  set("title", "尾火星官");
  set("age", 29);
  set("long", "    \n本人以为天地皆空，人生皆幻，\n世情嗜欲，悉伐性之斧斤；富贵功名，皆迷心之鸩毒。\n欲寻清幽之谷，依深穴之岩，垒石为门，拔茅为席，澄心净虑。\n吾愿足以！！！\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1224175);
  set("daoxing", 1224175);
  set("qi", 936);
  set("max_qi", 936);
  set("jing", 1895);
  set("max_jing", 1895);
  set("neili", 3107);
  set("max_neili", 1554);
  set("mana", 6779);
  set("max_mana", 3390);
  set("force_factor", 123);
  set("mana_factor", 170);
  set("str", 15);
  set("per", 13);
	set("combat_exp", 9500000);
	set("score", 400000);
	set_skill("art", 380);
	set_skill("goplaying", 380);
	set_skill("taxue-wuhen", 380);
	set_skill("luteplaying", 380);
        set_skill("literate", 300);
	set_skill("force", 250);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 280);
	set_skill("kunlun-shenfa", 380);
	set_skill("strike", 380);
	set_skill("kunlun-zhang", 380);
set_skill("mantian-huayu", 380);
set_skill("qixian-jian", 380);
	set_skill("chuanyun-tui", 380);
	set_skill("zhentian-quan", 380);
	set_skill("parry", 250);
	set_skill("sword", 300);
        set_skill("cuff", 250);
	set_skill("leg", 250);

        set_skill("finger", 280);
	set_skill("hand", 250);
set_skill("qidao", 380);
set_skill("music", 380);

	set_skill("liangyi-jian", 380);
	set_skill("throwing", 380);
	set_skill("taiji-shengong", 180);
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "qixian-jian");
	map_skill("parry", "art");
	map_skill("sword", "qixian-jian");
	//prepare_skill("strike", "kunlun-zhang");
	
	map_skill("finger", "qidao");
	map_skill("hand", "music");
	prepare_skill("finger", "qidao");
	prepare_skill("hand", "music");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "hand.gong" :),
                	(: perform_action, "hand.libie" :),
                 	(: perform_action, "hand.lv" :),
                (: perform_action, "finger.xb" :),                		
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
                (: perform_action, "strike.yixing" :),                		
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.ni" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.yin" :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

setup();

carry_object(__DIR__"loginload/skirt.c")->wear();
carry_object(__DIR__"loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"流水"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"清风"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"浮云"NOR);
}

