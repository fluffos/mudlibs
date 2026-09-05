#include <ansi.h>
// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;
void consider();
void heal();

void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
       set("nickname", HIR "邋遢真人" NOR);
        set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("title",RED "武当派" NOR + GRN "开山" NOR+ RED "祖师" NOR);
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

          set("per", 80);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 15000000);
        set("score", 500000);

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("force", 10000);
        set_skill("taiji-shengong", 40000);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 450);
        set_skill("cuff", 450);
        set_skill("taiji-quan", 400);
        set_skill("claw",450);
            set_skill("taiji-zhao",400);
        set_skill("parry", 450);
        set_skill("sword", 450);
        set_skill("taiji-jian", 400);
	set_skill("blade", 450);
	set_skill("taiji-dao", 400);
        set_skill("taoism", 40000);
        set_skill("literate", 300);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
       map_skill("claw","taiji-zhao");
    map_skill("blade","taiji-dao");
        prepare_skill("cuff", "taiji-quan");
prepare_skill("claw","taiji-zhao");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

        setup();
        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜谷虚。"); 
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
		if ((int)ob->query("shen") < 50000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，?妊ё鋈恕?);
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_int() < 30) {
                command("say 我武当派武功全从道藏悟出。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性?词前氲阋猜砘⒉坏谩?);
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可
挖，还是请回吧。");
                return;
        }
        command("chat 哈哈哈哈！！！！");
        command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。")
;
        command("recruit " + ob->query("id"));
		if ((string)ob->query("gender")!="女性")
			ob->set("title" ,RED "武当派" NOR + GRN "真人" NOR);
		else
			ob->set("title" ,RED "武当派" NOR + GRN "女真人" NOR);
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield jian");
            command("perform sword.chan " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("perform cuff.zhen " +target->query("id"));
             break;
             }
}
void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <5000 && (string)ob->query("family/master_id") == "zhang sanfeng")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}
