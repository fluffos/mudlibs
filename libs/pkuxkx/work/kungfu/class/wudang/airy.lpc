#include <ansi.h>
#include <title.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void create()
{
        set_name("雾中花水中月", ({ "airy" }));
//        set("nickname", HIC"忠心耿耿"NOR);
        set("long",
                "唉，甭提了。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 15);
        set("combat_exp", 100000);
        set("score", 20000);
      create_family("天神派", 1, "开山祖师");
        setup();
//        carry_object("/clone/weapon/xiangmochu")->wield();
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
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}
void unconcious()
{
object ob;
}
void die()

{
        object ob;

}
