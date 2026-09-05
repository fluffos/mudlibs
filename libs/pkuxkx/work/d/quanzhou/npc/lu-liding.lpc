// wu-santong.c 武三通
// by shang 97/6

inherit NPC;

void create()
{
        set_name("陆立鼎", ({ "lu liding", "lu" }) );
	set("gender", "男性" );
        set("age", 35);
	set("long",
"他就是陆展元之弟陆立鼎。\n" "一身武功都是兄长陆展元所传，生性淡泊，\n" "一生席丰履厚，从不到江湖上行走。\n");
	set("attitude", "friendly");
        set("str", 22);
        set("dex", 24);
        set("con", 20);
        set("int", 20);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("dodge", 60);
        set_skill("blade", 65);
        set("jiali", 20);

        set("combat_exp", 30000);

        set("max_qi", 300);
        set("max_jing", 200);
        set("max_neili", 300);
        set("max_jingli", 200);
        set("qi", 300);
        set("jing", 200);
        set("neili", 300);
        set("jingli", 200);

        set("inquiry", ([
            "何沅君" : "是我嫂子。",
            "陆展元" : "正是在下兄长。",
       ]) );
	setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
