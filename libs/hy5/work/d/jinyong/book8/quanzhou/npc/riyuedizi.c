//tonbaiwei.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("日月神教弟子", ({ "riyue dizi","dizi"}) );
	set("gender", "男性" );
	set("age", 30);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);

	set("max_qi", 50000);
	set("max_jing",50000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 200);
	set("combat_exp", 3000000);
	set("score", 30000);

	set_skill("sword", 300);
	set_skill("parry", 300);
	set_skill("literate",100);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("whip", 300);
	set_skill("force", 300);
	set_skill("staff", 300);
	set_skill("strike",300);
	set_skill("blade", 300);
	set_skill("changquan", 300);
	set_skill("tmjian", 300);
	set_skill("tmzhang", 300);
	set_skill("tmdao", 300);
	set_skill("pmshenfa", 300);
	set_skill("tmdafa", 300);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
 	set_skill("tmquan", 280);
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
	prepare_skill("cuff","tmquan");
	
	prepare_skill("strike","tmzhang");
	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
		(: perform_action, "sword.diansha" :),
		(: perform_action, "sword.xuan" :),
		(: perform_action, "sword.tmbiao" :),
		(: perform_action, "sword.jianshen" :),
		(: perform_action, "sword.moshen" :),
		(: perform_action, "blade.moxiao" :),
		(: perform_action, "blade.tiandirenmo" :),
		(: perform_action, "blade.xuan" :),                	
		(: perform_action, "blade.yueshen" :),                	
		(: perform_action, "strike.huashen" :),                
		(: perform_action, "strike.zhen" :),                
		(: perform_action, "strike.tmduan" :),                
		(: perform_action, "cuff.tianmo" :),                
		(: perform_action, "cuff.dimo" :),                
		(: perform_action, "cuff.renmo" :),

        }) );

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}