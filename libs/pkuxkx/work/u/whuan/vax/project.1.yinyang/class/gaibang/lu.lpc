// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
       string ask_me();

void consider();

void create()
{
        set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("nickname", GRN "掌棒龙头" NOR);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
                "因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 120); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("jiaohua-xinfa", 120);
        set_skill("strike", 125); // 基本掌法
        set_skill("xianglong-zhang", 120); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 120); // 逍遥游
        set_skill("parry", 120); // 基本招架
        set_skill("staff", 115); // 基本棍杖
	set_skill("blade", 120);
	set_skill("liuhe-dao", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-dao");

        prepare_skill("strike", "xianglong-zhang");
        set("inquiry",
                ([
                        "棒法秘籍" : (: ask_me :),
                ]));
        set("book_count", 2);

        create_family("丐帮", 18, "九袋长老");
        setup();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
		command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<800){
           command("sigh");
           command("say 小兄弟请回吧!我是不会收一个对本帮不忠之人的.");
           return;}
        if (ob->query("dai")== 8 )
        {
        if ( (int)ob->query("int") >= 25 ) {
                command("say 我们丐帮的武艺一向以刚猛为主，" +
                RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
                return;
        }
        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "丐帮" NOR + YEL +"八袋" NOR + MAG "弟子" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "丐帮")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
  if (this_player()->query("combat_exp")<5000)
             return RANK_D->query_respect(this_player()) +
            "初来乍到，还不能给你棒法秘籍。";
         if (this_player()->query("score")< 100)
             return "你新来乍到，问那么多干什么.";
        if (query("book_count") < 1)
                return "你来晚了，帮主的「棒法秘籍不在此处。";
        add("book_count", -1);
        ob = new("/d/gaibang/obj/staff_book");
        ob->move(this_player());
        return "好吧，帮主的「棒法秘籍」就给你拿回去好好钻研。";
}
 
