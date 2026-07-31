// By Xuanyuan 11/18/2001

#include <ansi.h>
inherit NPC;
int auto_perform();

void create()
{
	set_name("无崖子", ({"wuya zi", "wuya", "lj_npc"}));
	set("gender", "男性");
	set("age", 90);
	set("long", 
		"lj_npc。\n");
 	
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("neili", 12000);
	set("eff_neili", 12000);
	set("max_neili", 12000);
	set("jingli", 9000);
	set("max_jingli", 9000);
	set("eff_jingli", 9000);
	set("jiali", 300);
	set("jiajin",1);
	
	set("combat_exp", 3600000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
              (: auto_perform :),
        }) );

	create_family("灵鹫宫", 1, "弟子");

	set_skill("force", 400);		
	set_skill("beiming-shengong", 400);		
	set_skill("bahuang-gong", 400);		
	set_skill("strike", 400);
	set_skill("hand", 400);
	set_skill("zhemei-shou", 400);	
	set_skill("ruyi-dao", 400);	
	set_skill("dodge", 400);		
	set_skill("lingbo-weibu", 400);		
	set_skill("liuyang-zhang", 400);		
	set_skill("parry", 400);		
	set_skill("blade", 400);			
	set_skill("tianyu-qijian", 400);
	set_skill("sword", 400);
	set_skill("music", 400);

	map_skill("force", "beiming-shengong");
	map_skill("strike", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "lingbo-weibu");
	map_skill("parry", "liuyang-zhang");
	map_skill("blade", "ruyi-dao");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("strike", "liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");
	
	setup();
	
    carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/changjian");
	carry_object("/clone/weapon/gangdao");
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }
		if ( !me->query_temp("shield") ) {
                return exert_function("shield");
			}
		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.san");
					 if ( weapon->query("skill_type") == "blade" )
								return perform_action("blade.lianhuan");
		  }
		if( !me->query_temp("lingjiu/baihong") )
			return perform_action("strike.baihong");
//		if( objectp(opp->query_temp("weapon")) ) 
//			return perform_action("hand.zhemei");
		else return perform_action("hand.hanmei");
}