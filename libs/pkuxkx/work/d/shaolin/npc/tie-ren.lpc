// tie-ren.c
// iszt@pkuxkx, 2007-02-01

inherit NPC;

void create()
{
        set_name("铁人", ({ "tie ren", "ren", "iron man", "iron" }) );
        set("gender", "男性" );
        set_weight(60000000);
        set("age", 30);
        set("long", "一个沉重的铁人，里面装着机关可以活动，显是非常结实。\n");
        set("attitude", "peaceful");
	set("no_get", 1);

        set("str", 30);
        set("con", 25);
        set("dex", 15);
        set("int", 20);

        set("max_qi", 14000);
        set("eff_qi", 14000);
        set("qi", 14000);
        set("max_jing", 8000);
        set("jing", 8000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("shen_type", 0);

        set("combat_exp", 50000000);

        set_skill("force", 800); 
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("strike", 800);
        set_skill("club", 800);
        set_skill("literate", 800);
        set_skill("buddhism", 800);
        set_skill("hunyuan-yiqi", 800);
        set_skill("shaolin-shenfa", 800);
        set_skill("banruo-zhang", 800);
        set_skill("weituo-gun", 800);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "weituo-gun");
        map_skill("strike", "banruo-zhang");
        map_skill("club", "weituo-gun");

        prepare_skill("strike", "banruo-zhang");

        set("shen_type",1);set("score",1000);setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
}

