//Cracked by Kafei
// /d/bwdh/sjsz/npc/master.c

#include <ansi.h>


inherit NPC;

int auto_perform();

void create()
{
		  set_name("武林盟主", ({ "master" }));
		  set("long","他就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n");

		  set("gender", "男性");
		  set("age", 50);
		  set("attitude", "peaceful");
		  set("shen_type", 1);
		  set("str", 130);
		  set("int", 130);
		  set("con", 130);
		  set("dex", 130);

		  set("max_qi", 53000);
		  set("max_jing", 51800);
		  set("neili", 104000);
		  set("max_neili", 104000);
		  set("jiali", 100);
		  set("combat_exp", 8000000);

		  set_temp("apply/armor", 300);
		  set_temp("apply/damage", 110);

		  set_skill("force", 300);
		  set_skill("dodge", 300);
		  set_skill("parry", 300);
		  set_skill("sword", 300);
		  set_skill("strike", 300);
		  set_skill("zixia-shengong", 300);
		  set_skill("huashan-shenfa", 300);
		  set_skill("hunyuan-zhang", 300);

		  set_skill("luoyan-jian", 300);
		  set_skill("hengshan-jian", 300);
		  set_skill("songshan-jian", 300);
		  set_skill("shiba-pan", 300);
		  set_skill("duanjia-sword", 300);

		  set_skill("taiji-jian", 300);
		  set_skill("huashan-sword", 300);
		  set_skill("damo-jian", 300);
		  set_skill("huifeng-jian", 300);
		  set_skill("duanjia-sword", 300);
		  set_skill("pixie-jian", 300);
		  set_skill("liuhe-dao", 300);
		  set_skill("taiji-shengong", 300);
		  set_skill("kuihua-xinfa", 300);
		  set_skill("hunyuan-yiqi", 300);
		  set_skill("linji-zhuang", 300);
		  set_skill("kurong-changong", 300);

		  map_skill("force", "zixia-shengong");
		  map_skill("dodge", "huashan-shenfa");
		  map_skill("parry", "huashan-sword");
		  map_skill("sword", "huashan-sword");
		  map_skill("strike", "hunyuan-zhang");

		  prepare_skill("strike", "hunyuan-zhang");



		  set("chat_chance_combat", 80);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );

		  set("inquiry", ([
						"五岳剑派" : "五岳剑派由泰山派、衡山派、华山派、恒山派、嵩山派合并而成。",
                  "嵩山派" : "自从合并五岳剑派后，就没有嵩山派了。",
                  "邪派" : "天下邪派有星宿派，白驼山，雪山派和血刀门。",
                  "正派" : "天下名门正派有少林派，武当派，华山派，大理段家和峨嵋派。",
                  "名门正派" : "天下名门正派有少林派，武当派，华山派，大理段家和峨嵋派。",
        ]));


		  setup();

		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"qinggang-jian")->wield();
		  carry_object("/clone/misc/cloth")->wear();
}

void init()
{
		  object ob = this_player();
		  object me = this_object();

		  ::init();

		  if( !living(me) ) return;

		  if( interactive(ob) && ob->query("sjsz/fighting") ) {
					  message_vision(HIR"\n$N对$n喝道：" + RANK_D->query_rude(ob) + "居然敢擅闯本山庄，实在是死有余辜。\n"NOR, me, ob);
					  kill_ob(ob);
					  return;
		  }
}


int accept_fight(object ob)
{
		  object me = this_object();

		  int my_max_qi = (int)me->query("max_qi");

		  if ( (int)me->query("qi")*100 / my_max_qi <= 80 ) {
					 return 0;
		  }

		  command("sneer");
		  message_vision("$N喝道：" + RANK_D->query_rude(ob) + "！你也配和我交手？\n", me);
		  return 1;
}

int auto_perform()
{
		  object me = this_object();
		  object ob = me->select_opponent();
		  object w, w1, w2;
		  string skill, action, spforce;
		  int n;


		  if ( !me->is_fighting() ) {
					 if ( (int)me->query("eff_qi") < (int)me->query("max_qi") )
								exert_function("heal");
					 me->set("jiali", 100);

					 return 1;
		  }


		  if( !objectp(w2 = present("xiuhua zhen", me))
		  && query("amount") ) {
					 add("amount", -1);
					 w2 = new(__DIR__"xiuhua");
					 w2->move(me);
                  command("wield xiuhua zhen");
		  }
		  if( !objectp(w2 = present("qinggang jian", me))
		  ) {

		 w2 = new(__DIR__"xiuhua");
		 w2->move(me);
                  command("wield xiuhua zhen");
		  }

		  if( !objectp(w2 = present("xiuhua zhen", me))
		  ) {

		 w2 = new(__DIR__"xiuhua");
		 w2->move(me);
                  command("wield xiuhua zhen");
		  }

		  w1 = present("qinggang jian", me);
		  if( objectp(w1) && objectp(w2) ) n = random(10);
		  else if( objectp(w1) && !objectp(w2) ) n = random(9);
		  else if( !objectp(w1) && objectp(w2) ) n = 5;
		  else {
					 me->set_skill("zixia-shengong", 340);
                me->map_skill("force", "zixia-shengong");
                me->reset_action();
                return perform_action("strike.wuji");
        }                

		  switch(n) {
		  case 0:
                skill = "taiji-jian";
                action = "sword.lian";
					 spforce = "taiji-shengong";
                break;
        case 1:
                skill = "huashan-sword";
                action = "sword.jianzhang";
                spforce = "zixia-shengong";
					 break;
        case 2:
                skill = "damo-jian";
                action = "sword.sanjue";
                spforce = "hunyuan-yiqi";
                break;
        case 3:
                skill = "huifeng-jian";
                action = "sword.mie";
                spforce = "linji-zhuang";
                break;
        case 4:
                skill = "duanjia-sword";
                action = "sword.fenglei";
                spforce = "kurong-changong";
                break;
        case 5:
					 skill = "pixie-jian";
					 action = "sword.sanlianci";
                spforce = "kuihua-xinfa";
					 break;
        case 6:
                skill = "luoyan-jian";
                action = "sword.yunwu";
                spforce = "kurong-changong";
                break;
        case 7:
                skill = "shiba-pan";
                action = "sword.ruhe";
                spforce = "kurong-changong";
                break;
        case 8:
                skill = "songshan-jian";
                action = "sword.xuli";
                spforce = "kurong-changong";
                break;
        case 9:
                skill = "songshan-jian";
                action = "sword.shenfeng";
                spforce = "kurong-changong";
                break;
        }

		  if( objectp(w = me->query_temp("weapon")) ) {
					 if( w == w1 && n < 5 ) {
                        message_vision(HIR"\n突然间$N嘿嘿冷笑几声。\n随即手中" + w->name() + "似曲似直，便如一件活物一般，顿时招式大变！！！\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
								w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\n突然间$N剑法一变，手中" + w2->name() + "忽伸忽缩，招式诡奇绝伦。\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
								message_vision(w->query("unwield_msg"), me, w);
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N似乎有意放慢了进攻，然。。。\n"NOR, me);
					 }
		  } else {
					 if( n < 5 ) {
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N似乎有意放慢了进攻，然。。。\n"NOR, me);
					 } else {
								w2->wield();
								message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\n突然间$N剑法一变，手中" + w2->name() + "忽伸忽缩，招式诡奇绝伦。\n"NOR, me);
					 }
		  }

		  me->map_skill("sword", skill);
		  me->map_skill("parry", skill);
		  me->map_skill("force", spforce);
		  me->reset_action();
		  return perform_action(action);
}
