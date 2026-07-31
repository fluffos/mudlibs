// modified by vikee

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林月如", ({ "lin yueru", "lin", "yueru" }));
        set("title","蜀山剑派圣姑弟子");
        set("long", 
"刁蛮少女贵千金，比武招亲动芳心。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2200);
        set("max_kee", 2200);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 3000);
        set("max_force", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        setup();
        create_family("蜀山剑派", 5, "未入门弟子");
       carry_object("/clone/misc/cloth")->wear();
carry_object("/d/obj/weapon/whip/snakewhip")->wield();
}
void attempt_apprentice(object me)
{
me =this_player();
/* if ( !((string)me->query("gender")=="女性"))
		{
        command("shake");
        command("say 我只收女徒，这位" +
 RANK_D->query_respect(me) + "还是另请高就吧。\n");
           return ;
} */
if (me->query("nyj/shushan") != "done")
{
command("say 我现在还在担心着灵儿妹子……");
return;
}
command("pat "+me->query("id"));
command("say 既然" + RANK_D->query_respect(me) +"心向蜀山，那我只好收你为徒。\n");
command("recruit " + me->query("id") );
        return ;
}



