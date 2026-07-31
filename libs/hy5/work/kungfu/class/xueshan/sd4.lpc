#include <ansi.h>

inherit NPC;

void create()
{
        set_name("潇湘子", ({ "xiaoxiang zi", "zi", "xiaoxiang" }));
        set("title", "湘西名宿");
        set("long", "他身材高瘦，脸无血色，形若僵尸。脸上隐隐透著一股青气，手持一根哭丧棒。\n");
        set("gender", "男性");
        set("rank_info/respect", "道长");
        create_family("丐帮", 15, "弟子");
        set("age", 43);
        set("attitude","heroism");
        set("str", 36);
        set("dex", 30);
        set("con", 33);
        set("int", 32);
        set("shen", -7000);
        set("env/wimpy", 60);
        set_skill("parry", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("staff", 200);
        set_skill("huntian-qigong", 320);       
        set_skill("tianshan-zhang", 320);  
        set_skill("xiaoyaoyou", 320);
        set_skill("hand", 200);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("hand", "suohou-shou");
        set("combat_exp", 10000000);
        set("max_qi", 15500);
        set("max_jing", 15000);
        set("eff_jingli", 15000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 50);

set_skill("ruying-leg", 280);
		set_skill("zhanzhuang-gong", 280);
	set_skill("shaolin-cuff", 280);
	set_skill("shaolin-leg", 280);
	set_skill("yiwei-dujiang", 280);
	set_skill("boluomi-hand", 280);
	set_skill("jingang-strike", 280);
	set_skill("wuxiang-finger", 280);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 260);
	set_skill("yijinjing", 260);
	set_skill("force", 260);
	set_skill("yijinjing", 260);
	set_skill("dodge", 260);
	set_skill("shaolin-shenfa", 220);
	set_skill("cuff", 260);
	set_skill("hunyuan-yiqi", 220);
	set_skill("luohan-quan", 220);
	set_skill("jingang-quan", 220);
	set_skill("leg", 260);
	set_skill("zui-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("hand", 260);
	set_skill("fengyun-shou", 220);
	set_skill("qianye-shou", 220);
	set_skill("strike", 260);
	set_skill("sanhua-zhang", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("weituo-gun", 220);
	set_skill("banruo-zhang", 220);
	set_skill("finger", 260);
	set_skill("yizhi-chan", 220);
	set_skill("yizhi-chan", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("yizhi-chan", 220);
	set_skill("claw", 260);
	set_skill("qianye-shou", 220);
	set_skill("yingzhua-gong", 220);
	set_skill("longzhua-gong", 220);
	set_skill("staff", 260);
	set_skill("pudu-zhang", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("blade", 260);
	set_skill("cibei-dao", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("club", 260);
	set_skill("zui-gun", 220);
	set_skill("zui-gun", 220);
	set_skill("sword", 260);
	set_skill("damo-jian", 220);
	set_skill("whip", 260);
set_skill("hunyuan-yiqi", 260);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("leg", "nianhua-zhi");

	map_skill("strike", "banruo-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("staff", "wuchang-zhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("parry", "wuxiang-finger");
  map_skill("parry","wuxiang-finger");
  map_skill("unarmed","wuxiang-finger");
  map_skill("finger","wuxiang-finger");
  map_skill("hand","boluomi-hand");
  map_skill("strike","jingang-strike");
	//prepare_skill("finger", "wuxiang-finger");
	prepare_skill("hand", "boluomi-hand");
	prepare_skill("strike", "jingang-strike");

//set_skill("hellfire-whip", 280);
//set_skill("buddha-club", 280);
//set_skill("lunhui-zhang", 320);
set_skill("zhanzhuang-gong", 220);
set_skill("buddhism", 350);
	//map_skill("club", "buddha-club");
	//map_skill("whip", "hellfire-whip");
	map_skill("staff", "lunhui-zhang");
		map_skill("force", "zhanzhuang-gong");
		
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
       
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
(: perform_action, "staff.chaodu" :),
(: perform_action, "staff.diyu" :),
(: perform_action, "staff.pudu" :),
(: perform_action, "staff.sandu" :),
(: perform_action, "staff.xiangfu" :),
(: perform_action, "staff.xin" :),
						
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);

        set("inquiry", ([            
            "金轮法王" : "嘿嘿，我迟早会把那个老和尚的国师名号抢过来。",
            "马光佐" : "那是个莽夫，提他做什？",
            "尹克西" : "这人功夫不错，就是满身的金银太耀眼，不象个武林人士。",
            "尼摩星" : "西域来的，内功不错。就是，嘿嘿，心眼太小。",            
       ]) );
        setup();

        carry_object("/d/hj/npc/obj/gangzhang")->wield();
        carry_object("/d/hj/npc/obj/greenrobe")->wear();
}

void kill_ob(object me)
{     object ob=this_object();
      command("grin");
      command("say 杖下领死吧！");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      ::kill_ob(me);
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1054",1);
	::die();
}  