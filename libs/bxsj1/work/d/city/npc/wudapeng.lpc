// wudapeng.c

inherit NPC;

void create()
{
	set_name("吴大鹏", ({ "wu dapeng","wu","dapeng"}) );
        set("long","他是一个老头子，一部白胡须直垂至胸，但面皮红润泛光，没有半点皱纹。\n");
        set("nickname", "摩云手");
        set("gender", "男性");
        set("age", 54);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 28);
        set("int", 18);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("combat_exp", 150000);
//	set_temp("apply/attack", 60);
//        set_temp("apply/defense", 40);
        set_skill("force", 100);
 set_skill("yijin-jing", 100);
        set_skill("dodge", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("strike", 100);
        set_skill("weituo-zhang", 100);
        set_skill("parry", 100);
map_skill("force","yijin-jing");
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry","weituo-zhang");
        map_skill("strike","weituo-zhang");
        prepare_skill("strike","weituo-zhang");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();

}
