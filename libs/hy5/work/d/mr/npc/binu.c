// /u/beyond/mr/npc/binu.c 婢女
// this is made by beyond
// update 1997.6.23
inherit NPC;
void create()
{
        set_name("婢女", ({ "bi nu", "bu" }));
        set("gender", "女性");
        set("age", 24);
	set("str", 18);
        set("int", 20);
        set("con", 20);
        set("per", 25);
        set("dex", 20);
        set("combat_exp", 10000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",600);
        set("max_jing",600);
        set("neili",450);
        set("max_neili",450);
	set("jiali",0);
	set("score", 5500);
set("title","侍女");
        set_skill("cuff", 35);
	set_skill("parry",35);
	set_skill("yanling-shenfa",35);
        set_skill("dodge", 35);
	set_skill("force",35);
	set_skill("shenyuan-gong",35);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
create_family("姑苏慕容",4,"弟子");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
	add_money("silver", 10);
}