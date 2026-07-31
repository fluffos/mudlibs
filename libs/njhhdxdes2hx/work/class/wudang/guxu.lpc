#include <ansi.h>
// guxu.c 谷虚

inherit NPC;
inherit F_MASTER;

string ask_me();
void heal();

void create()
{
        set_name("谷虚道长", ({ "guxu daozhang", "guxu" }));
        set("long",
                "他就是俞莲舟的弟子谷虚道长。\n"
                "他今年四十岁，主管武当派的俗事。\n");
       set("title",RED "武当派" NOR + GRN +"道长" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_gin", 800);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
        set("combat_exp", 60000);
        set("score", 8000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 60);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 40);
        set_skill("cuff", 60);
        set_skill("taiji-quan", 50);
	set_skill("move", 40);
//      set_skill("taiji-quan", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("taiji-jian", 40);
        set_skill("taoism", 60);
//      set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        set("inquiry",
                ([
                        "道德经" : (: ask_me :),
                ]));

        set("book_count", 1);

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/obj/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{

        if ( this_player()->query("class")=="bonze")
        {
                command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
                return;
        }
        if ( this_player()->query("class")=="eunach")
        {
                command("say 我派不收太监，" + RANK_D->query_respect(ob) + "请会吧。");
                return;
        }

	if ((string)ob->query("class") != "taoist")
	{
		command("say 我派只收道士，"+ RANK_D->query_respect(ob) + "是否愿意入我三清。");
		command("say 如果你决定了。请告诉我(decide)。");
	       	ob->set_temp("prepare/taoist", 1);
	        return;
	}
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的道德真经不在此处。";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好钻研。";
}

void init()
{

        object ob;
        mapping fam;

        add_action("do_decide", "decide");

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <=-100 && ((fam = ob->query("family")) && fam["master_id"] == "guxu daozhang"))
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		


int do_decide()
{

	object ob=this_player();
        if( !this_player()->query_temp("prepare/taoist") )
                return 0;
	
        this_player()->delete_temp("prepare/taoist");

        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return 0;
        }
   
	command("say 好吧，贫道就收下你了。");
	command("say 如今你已经是三清弟子，以后做事可要好好做人，否则我派无法留你。");
	command("recruit " + ob->query("id"));
	return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 30");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
        if (ob->query("age")<20)
        {
        	if((string)ob->query("gender")!="女性")
		{
                	ob->set("title",RED "武当派" NOR + GRN +"道童" NOR);
			return;
		}
        	else
		{
                	ob->set("title",RED "武当派" NOR + GRN +"小道姑" NOR);
			return;
		}
        }
        else 
	{
        	if((string)ob->query("gender")!="女性")
                {
			ob->set("title",RED "武当派" NOR + GRN +"道士" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "武当派" NOR + GRN +"道姑" NOR);
			return;
		}
        }
}

void re_rank(object student)
{
        if (student->query("age")<20)
        {
        	if((string)student->query("gender")!="女性")
		{
                	student->set("title",RED "武当派" NOR + GRN +"道童" NOR);
			return;
		}
        	else
		{
                	student->set("title",RED "武当派" NOR + GRN +"小道姑" NOR);
			return;
		}
        }
        else 
	{
        	if((string)student->query("gender")!="女性")
                {
			student->set("title",RED "武当派" NOR + GRN +"道士" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "武当派" NOR + GRN +"道姑" NOR);
			return;
		}
        }
}
