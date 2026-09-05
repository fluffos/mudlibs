#include <ansi.h>
// song.c 宋远桥
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask2();
string ask3();
void heal();
void create()
{
        set_name("宋远桥", ({ "song yuanqiao", "song" }));
        set("nickname", RED "武当首侠" NOR);
        set("long",
                "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
                "身穿一件干干净净的灰色道袍。\n"
                "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.zhen" :),
        }) );
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
          set("combat_exp", 600000);
        set("score", 60000);
        set_skill("force", 160);
        set_skill("yinyun-ziqi", 160);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 120);
        set_skill("cuff", 150);
        set_skill("taiji-quan", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
//      set_skill("taiji-jian", 60);
        set_skill("literate", 100);
        set_skill("taoism",150);
        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-quan");
//      map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");
        create_family("武当派", 2, "弟子");
        set("inquiry", ([
                "秘籍" : (: ask_me :),
		"下山" : (: ask3 :),
		"宋青书" : (: ask2 :),
        ]));
        set("book_count", 1);
        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜谷虚师侄。");
                return;
        }
        if ((int)ob->query("shen") < 5000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
                if ((string)ob->query("gender")!="女性")
                        ob->set("title" ,RED "武当派" NOR + GRN "道长" NOR);
                else
                        ob->set("title" ,RED "武当派" NOR + GRN "女道长" NOR);
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";
        add("book_count", -1);
        ob = new(__DIR__"force_book");
        ob->move(this_player());
        return "好吧，这本「太极十三式」你拿回去好好钻研。";
}
void init()
{
        object ob;
        mapping fam;
        ::init();
        ob = this_player();
        if ( (int)ob->query("shen") <0 && ((fam = ob->query("family")) && fam["master_id"] == "song yuanqiao"))
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
                command("enforce 50");
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
string ask3()
{	if ((int)this_player()->query_temp("下山"))
	return "趁着天色还早，快些上路吧。\n";
	this_player()->set_temp("下山",1);
	command ("nod");
	return "好吧，但是切记下山后不可为非做歹。\n";
}
string ask2()
{	object me=this_player();
	command ("sigh");
	return "青书这个大逆不道的畜生，竟然害死七弟，我绝不会放过他。\n";
}
int accept_object(object me,object ob)
{	if (!present(ob,me))
	return notify_fail("你没有这件东西。");
        if ((string)ob->query("id")=="pei jian")
	{   	command("sigh");
		command("say 多谢这位" + RANK_D->query_respect(this_player()) +
			"替武当清除了这个败类。\n");
		this_player()->add("shen",5000);
         call_out("destroy",1,ob);
	}
if ((string)ob->query("id")!="pei jian")
{
    command("faint");
    command("say 贫道不认识此物，施主自便吧！\n");
      return 0;
}
    return 1;
}
	
void destroy(object ob)
{
     destruct(ob);
     return;
}
