// xu.c 徐达
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("徐达", ({ "xu da","xu","da" }) );
	set("title", "明教洪水旗弟子");
        create_family("明教",38,"弟子");
	set("gender", "男性");
	set("age",36);
	set("long", "他是后来明朝的开国大功臣。\n");
       	set("str", 24);
	set("int", 27);
	set("con", 23);
	set("dex", 21);
        set("per", 20);
	set("shen_type",1);
	set("combat_exp", 180000);
        set("unique", 1);

	set_skill("cuff",60);
	set_skill("force",60);
	set_skill("literate",130);
	set_skill("dodge",60);
	set_skill("parry",60);	
        set_skill("taizu-quan",60);
        map_skill("parry","taizu-quan");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan"); 
	set("max_qi",600);
	set("max_jing",400);
	set("neili",400);
	set("max_neili",400);
	set("jiali",20);
	set("eff_jingli",200);
	setup();
	carry_object("/d/mingjiao/obj/black-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say 呵呵，我武功低微，可不敢收徒啊。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}
