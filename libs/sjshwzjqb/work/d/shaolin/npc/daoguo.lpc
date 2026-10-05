//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

       set_name("道果禅师", ({"daoguo chanshi","daoguo","chanshi",}));
        set("gender", "男性" );
        create_family("少林寺", 3, "弟子");
        set("title",HIG"少林寺禅师"NOR );
	set("age", 28);
set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 1700);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 1700);
        set("mana_factor", 20);
        set("combat_exp", 1000000);
        set("daoxing", 1000000);

        set_skill("banruo-zhang", 120);
        set_skill("yijinjing", 120);
        set_skill("chanzong", 120);
        set_skill("spells", 120);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("force", 120);
        set_skill("sword", 120);
        set_skill("shaolin-shenfa", 120);
        set_skill("shaolin-sword", 120);
        map_skill("unarmed", "banruo-zhang");
        map_skill("sword", "shaolin-sword");
        map_skill("parry", "shaolin-sword");
        map_skill("force", "yijinjing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

       if (((int)ob->query_skill("chanzong",1) < 60 )) 
        {
                command ("say 阿弥陀佛！施主的禅法修为不够，贫僧不能收你为徒呀。\n你还是去拜清法比丘为师吧。");
                return;
        }

        if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIG"嵩山少林寺大禅师"NOR);
}
