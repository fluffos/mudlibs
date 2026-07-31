// woodcutter.c

inherit NPC;

void create()
{
        set_name("看场打手",({"dashou"}));

	set("gender", "男性" );
	set("age", 26);
       set("title","神户妓馆");
        set("long","风雅阁雇佣的地痞，以维护楼内治安。\n");
        set("combat_exp", 20000);
	set("str", 30);
	set_temp("apply/attack",15);
	set_temp("apply/defense",15);
	set_temp("apply/damage",20);
        set_skill("unarmed",50);
        set_skill("dodge",50);
       set_skill("parry",80);
	setup();
   carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/weapon/gangjian")->wield();

}
