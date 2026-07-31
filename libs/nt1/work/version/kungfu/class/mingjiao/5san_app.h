// SN:M9@IV?Hef>UZFKi6
// 五散人收徒条件

void attempt_apprentice(object ob)
{
        mapping fam = ob->query("family");
        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0) 
        {
                command("say " + RANK_D->query_respect(ob) +
                        "有所不知，我平生最恨奸诈之人，你正气太低，我不能让你进入明教半步。");
                return;
        }
                        
        if (! fam || fam["family_name"] != "明教")
        {
                command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return;
        }

        if ((int)ob->query_skill("shenghuo-shengong", 1) < 70) 
        {
                command("say 要学更为高深的武功，必须有高深的内功修为。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该在圣火神功上多下点功夫？");
                return;
        }        
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 多谢明尊敝佑，让我明教又得一良材，为康扶正义，把我明教发扬光大吧。");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title") + "属下教众");
}
