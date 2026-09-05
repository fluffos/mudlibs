init()
{
        object me;
       me=this_player();
        ::init();
   if(me->query_mark("yuan")==0){
      remove_call_out("do_killing");
       call_out("do_killing",0,me);
           }
}
void do_killing(object me)
{
command("look "+me->query("id"));
me->set("yuan",random(10));

if(me->query("yuan")>9){
command("say "+ RANK_D->query_respect(me) +"福缘极佳，真乃有福之人！");
command("nod");
}
}



void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam  = me->query("family");

        string name, new_name;

        name = ob->query("name");
     if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
        {
              command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return;
        }
        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派")
        {
                command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
                return;
        }
        if ( (int)ob->query("yuan")>9){
                 command("say " + RANK_D->query_respect(ob) + "福缘如此之佳，老僧正求之不得呢！");
                 command("haha");
                 command("chat 今日老僧又觅得一有福之人！哈哈哈哈！");
                 command("recruit "+ ob->query("id"));
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
                command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
                return;
        }
        
         if ((int)ob->query("yuan")<3){
           command("say 我佛不度无缘人，罢了罢了");
        command("say " +ob->query("yuan"));
           command("sigh");
           return;
              }

        if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..0] == "玄")
        {
                command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
                command("recruit " + ob->query("id"));
                return;
        }

        if ((int)ob->query_skill("buddhism", 1) < 100) {
                command("say 我少林派乃出家人，最重视修行。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在禅宗心法上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
       
        if ( ob_fam["generation"] == 37 )
        {
                          
                        command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈 !");
                        command("say 贫僧又得一可塑之才，真是可喜可贺 !");

                        new_name = "玄" + name[1..1];
                        ob->set("name", new_name+"大师");
                        if (ob->query("have_appentice_du")!=1)
                        ob->set("combat_exp", ob->query("combat_exp") + 100000);
                        ob->set("have_apprentice_du",1);

                        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派玄字辈弟子 !");

                        command("chat 哈哈哈哈！！！！");
                        command("chat 贫僧又觅得一个可塑之才，真是可喜可贺。");
                        command("recruit " + ob->query("id"));
              

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
