// ye.c

inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("叶二娘", ({ "ye erniang", "ye" }));
	set("gender", "女性");
	set("nickname", HIR"无恶不作"NOR);
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "一个中年女子，身穿淡青色长袍，左右脸颊上各有三条血痕。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 10000); 
	set("max_neili", 10000);
	set("max_qi", 10000);
	set("jiali", 100);

	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("force", 200);
	set_skill("blade", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sanyin-wugongzhao", 200);
	set_skill("chousui-zhang", 200);
	set_skill("huagong-dafa", 200);
	set_skill("kuangfeng-blade", 200);
	set_skill("shaolin-shenfa", 200);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("blade", "kuangfeng-blade");
	map_skill("parry", "kuangfeng-blade");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}                     