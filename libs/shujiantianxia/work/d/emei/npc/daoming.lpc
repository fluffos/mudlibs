// daoming.c 道明小师傅
// Made by jackie

inherit NPC;
void create()
{
        set_name("道明小师傅", ({ "daoming shifu", "daoming", "shifu" }));
	set("long","这是个年龄不大的小师父。他见有人来到，轻轻点头笑了笑。\n");
        set("gender", "男性");
        set("age", 30);
	set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 100000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",800);
        set("max_jing",800);
        set("neili",600);
        set("max_neili",600);
	set("jiali",0);
	set("score", 7000);


        set_skill("sixiang-zhang", 60);
	set_skill("strike", 60);
	set_skill("parry",60);
	set_skill("linji-zhuang", 60);
        set_skill("dodge", 60);
	set_skill("force",60);
	set_skill("ding-dodge", 60);


	map_skill("force", "linji-zhuang");
	map_skill("dodge", "ding-dodge");
	map_skill("parry", "sixiang-zhang");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("/d/emei/obj/cloth2")->wear();
}

