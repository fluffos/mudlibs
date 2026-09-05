int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");

        if (obj->query("id") == "tuijian xin5"
        && ob->query_temp("have_letter") )
        {
                ob->set_temp("apprentice_ok",1);
                command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？")
;
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
        }

        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
                                                        return;
}


void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam  = me->query("family");

        string name, new_name;

        name = ob->query("name");
        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派"
)
        {
                 command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return;
        }
        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少
林派")
        {
                command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在
寺内学艺。");
                return;
        }
        if ( ob_fam["generation"] == 0 )
        {
                command("say 阿弥陀佛！贫僧就收下你做我的弟子了。");
                command("recruit " + ob->query("id"));
                return;
        }

        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !")
;
                return;
        }

        if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..0] ==
 "玄")
        {
                command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来
了，哈哈哈 !");
                command("recruit " + ob->query("id"));
                return;
        }

        if ((int)ob->query_skill("buddhism", 1) < 120) {
                command("say 我少林派乃出家人，最重视修行。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在禅宗心法上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，?妊ё鋈恕?);
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_con() < 35) {
                command("say 学习日月神鞭要有强壮的体魄。");
                command("say " + RANK_D->query_respect(ob) + "的根骨还大有潜力可
挖，还是请回吧。");
                return;
        }
        if ( ob_fam["generation"] == 37 )
        {
                if ( ob->query_temp("apprentice_ok") )
                {
                        ob->delete_temp("have_letter");
                        ob->delete_temp("apprentice_ok");

                        command("say 是" + ob_fam["master_name"] + "叫你来找我的
吧，哈哈哈 !");
                        command("say 贫僧又得一可塑之才，真是可喜可贺 !");

                        new_name = "玄" + name[1..1];
                        ob->set("name", new_name+"大师");
                        if (ob->query("have_apprentice_du")!=1)
			ob->set("combat_exp", ob->query("combat_exp") + 100000);
                        ob->set("have_apprentice_du",1); 

                        command("say 从今以后你的法名叫做" + new_name + "，恭喜?闳偕倭峙尚直驳茏?!");

                        command("chat 哈哈哈哈！！！！");
                        command("chat 贫僧又觅得一个可塑之才，真是可喜可贺。");
                        command("recruit " + ob->query("id"));
                }
                else
                {
                        command("say " + RANK_D->query_respect(ob) + "，你没有推
荐信，不能越级拜师。");
                        return;
                }

        }

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	if( ob->query_skill("buddhism", 1) >= 150)
	{
        	ob->set("title",HIR "少林" NOR + CYN "圣僧" NOR);
		return;
	}
       	ob->set("title",HIR "少林" NOR + CYN "神僧" NOR);
        return;
}

void re_rank(object student)
{
	if( student->query_skill("buddhism", 1) >= 150)
	{
        	student->set("title",HIR "少林" NOR + CYN "圣僧" NOR);
		return;
	}
       	student->set("title",HIR "少林" NOR + CYN "神僧" NOR);
        return;
}
