// 蒙古马贼 zine 2012

#include <ansi.h>
inherit NPC;
int exer();
void create()
{ 
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title","老太监");
		set("gender", "无性");
        set("bonus",1);
        set("age", random(30)+14);       
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_qi", 15000);
        set("eff_qi", 15000);
        set("qi", 15000);
        set("max_jing", 5000);
        set("jing", 5000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("combat_exp", 10000000);
	    set("busy",1);

        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("claw", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("pixie-jian", 400);
        set_skill("literate", 400);
        set_skill("kuihua-shengong", 400);
        set_skill("yingzhua-gong", 400);

        map_skill("claw", "yingzhua-gong");
        map_skill("sword", "pixie-jian");
        map_skill("force", "kuihua-shengong");
        map_skill("parry", "pixie-jian");
        map_skill("dodge", "pixie-jian");
        prepare_skill("claw", "yingzhua-gong");
	    set("jiali",300);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
        setup();
        carry_object(__DIR__"obj/tj-cloth")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();

}
int exer()
{
    if (!living(this_object()))
    return 1;
	command("perform dodge.feiying");
    command("exert recover");
	command("exert powerup");
	return 1;
}
void die()
{
	int n;
    object killer,ob=this_object();
    killer = get_damage_origin_object();
    if (!killer->query_temp("ming/shiweichu/task"))
    {
		message_vision(HIR+"事情败露，埋伏在宫里的同党接应走$N，远远遁去！\n"+NOR,ob);
		destruct(ob);
		return;
    }
	n=3+random(3);
	killer->delete_temp("ming/shiweichu/task");
	killer->add("ming/credit",n);
	tell_object(killer,"你的大明功勋增加了"+chinese_number(n)+"点。\n");
	message_vision(HIR+"事情败露，埋伏在宫里的同党接应走$N，远远遁去！\n"+NOR,ob);
    destruct(ob);
	return ;
}