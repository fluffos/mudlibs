// /u/beyond/mr/npc/jiading.c 家丁
// this is made by beyond
// update 1997.6.23
inherit NPC;
void create()
{
        set_name("家丁", ({ "jia ding", "ding" }));
        set("gender", "男性");
        set("age", 24);
	set("str", 24);
        set("int", 23);
        set("con", 23);
        set("dex", 22);
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",750);
        set("max_jing",500);
        set("neili",550);
        set("max_neili",550);
	set("jiali",0);
	set("score", 6000);
set("title","护院");
        set_skill("cuff", 55);
	set_skill("parry",55);
	set_skill("yanling-shenfa",55);
        set_skill("dodge",55);
	set_skill("force",55);
	set_skill("shenyuan-gong",55);
        set_skill("sword",55);
create_family("姑苏慕容",4,"弟子");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
	add_money("silver", 30);
}
