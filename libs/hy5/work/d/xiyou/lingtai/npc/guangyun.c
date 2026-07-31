
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("¹ãóÞ×Ó", ({"guang yunzi", "guang"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 43);
        set("long", "·½´çÉ½ÈýÐÇ¶´µÚ¶þ´úµÜ×ÓÖÐµÄ½Ü³öÈËÎï£®\n");
        set("combat_exp", 250000);
	set("daoxing", 400000);

        set("attitude", "friendly");
        create_family("·½´çÉ½ÈýÐÇ¶´", 2, "Ê×Í½");
	set("int", 25);
	set("class", "taoist");

        set("eff_dx", 90000);
        set("nkgain", 300);

        set_skill("unarmed", 80);
     
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 40);
        set("mana", 450);
        set("max_mana", 300);
	set("mana_factor", 20);
        setup();
	carry_object("/d/xiyou/lingtai/obj/daoguan")->wear();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp")+(int)ob->query("daoxing") < 30000)) {
	command("say " + RANK_D->query_respect(ob) +
"ÊÇ·ñ»¹Ó¦ÔÚµÀÐÐ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âð£¡");
	return;
	}
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

ÿ
