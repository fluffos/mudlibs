// heaven_soldier.c


#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"

void backattack();
void create()
{

	set_name(HIG"护法弟子"NOR, ({ "qz dizi", "qzguard" }) );
	set("long", "这是一位专门担任保护之责的弟子。\n");
	set("attitude", "friendly");


	set("max_neili", 10000);
	set("neili", 10000);
	set("max_jing", 5000);
	set("max_qi", 5000);
	set("str", 40);
	set("dex", 60);

	  set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "sword.sanqing" :),

        }));


        set_skill("force", 200);
        set_skill("xiantian-qigong", 350);    //先天气功
        set_skill("sword", 200);
set_skill("qixing-jian",220);
set_skill("qixing-shou",220);
set_skill("qixing-array",220);
        set_skill("quanzhen-jian",200);  //全真剑
        set_skill("dodge", 200);
        set_skill("jinyan-gong", 200);   //金雁功
        set_skill("parry", 200);
        set_skill("haotian-zhang", 220);    //昊天掌
        set_skill("literate",200);
        set_skill("strike",200);
        set_skill("taoism",220);
set_skill("hand", 220);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

create_family("全真教", 3, "弟子");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 150);
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);
	setup();

	//carry_object("/quest/weiguo/japan/obj/japanblade")->wield();
	//carry_object("/clone/cloth/male3-cloth")->wear();	
//initlvl(300,26);

}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "说道：随时谨听召唤！\n\n"
		+ name() + "闪了闪就消失不见了。\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();

        
        who->apply_condition("zdizi_busy",6);
        level=who->query("combat_exp");
        set("no_drop",1);
        set("no_get",1);
	set("double_attack", who->query("double_attack"));
	set("szj", who->query("szj"));

	set("str", (who->query("str") > 60 ? 60 : who->query("str")));
	set("int", (who->query("int") > 60 ? 60 : who->query("int")));
	set("con", (who->query("con") > 60 ? 60 : who->query("con")));
	set("dex", (who->query("dex") > 60 ? 60 : who->query("dex")));
	set("kar", (who->query("kar") > 60 ? 60 : who->query("kar")));
	set("combat_exp", (int)(who->query("combat_exp",1)*3/4));
	set("max_neili", who->query("max_neili",1));
	set("neili", query("max_neili"));
	set("max_qi", who->query("max_qi",1));
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("max_jing", who->query("max_jing",1));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("fooz", (query("str") + 10) * 10);
	set("water", (query("str") + 10) * 10);
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			fight_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->fight_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->fight_ob(enemy[i]);
                        enemy[i]->fight_ob(owner);
                }
        }

	}

}

void unconcious()
{
        die();
}

void die()
{
        object ob;
        message_vision("$N逃离了出去！\n", this_object());

        destruct(this_object());
}