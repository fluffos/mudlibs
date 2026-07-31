// gaibang npc code

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。\n");
	set("attitude", "peaceful");
	set("str", 22);
	set("int", 30);
	set("con", 24);
	set("dex", 22);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 530);
	set("max_jing", 530);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 45);
	
	set("combat_exp", 550000);
	
	set_skill("force", 150); 
	set_skill("jiaohua-neigong", 150); 
	set_skill("unarmed", 140); 
	set_skill("changquan", 140); 
	set_skill("dodge", 140); 
	set_skill("feiyan-zoubi", 140); 
	set_skill("parry", 140); 
	set_skill("begging", 100); 
	set_skill("stealing", 30); 
	set_skill("checking", 80); 
	
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( !permit_recruit(ob) ) return;

	if( ob->query("int") < 25 )
	{
		command("say 你的... 那个有点不聪明吧？");
	}

	command("say 唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿。");
	command("say 大家都要为长远着想啊！");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
