// wangtan
// Creator : Numa@Sj 00-6-3 17:12

inherit NPC;

void create()
{
        set_name("王潭", ({ "wang tan", "wang" }));
        set("nickname", "双笔开山");
        set("gender", "男性");
        set("age", 43);
        set("long", "一个矮矮胖胖的中年人，是个秃子，后脑拖着条小辫子，前脑如剥壳鸡蛋。。\n");
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 28);
        set("int", 17);
        set("con", 24);
        set("dex", 26);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 180000);
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("sword",100);
        set_skill("parry", 100);
        map_skill("force","yijinjing");
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry","weituo-zhang");
        map_skill("strike","weituo-zhang");
        prepare_skill("strike","weituo-zhang");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();

}
