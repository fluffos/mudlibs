// weishi.h 升級到衛士, 拜師
int ask_me()
{
        string oldtitle;
        object ob, me;
        me = this_object();
        ob = this_player();
        if ((int)ob->query_skill("kurong-changong",1) < 49)
        {
                command("say 你想當衛士，再練幾年功吧。\n");
                return 1;
        }
        oldtitle = ob->query("title");
        if (strsrch(oldtitle, "大理鎮南王府家臣") >= 0)
        {
                ob->set_temp("fight_ok",1);
                command("say 好，既然如此想切磋，那就看你的本事如何了。\n");
                return 1;
        }
        else
        {
                command("say 只有家臣才能升衛士。\n");
                return 1;
        }
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                command("say 青出於藍勝於藍，不愧是大理段家的好弟子 ! 恭喜你了 !\n");
                command("say 你的已經可以勝任大理衛士 !\n");
                upgrade_title(ob, "大理鎮南王府衛士");
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                command("say 看來" + RANK_D->query_respect(ob) + 
                        "還得多加練習，方能在大理段家諸多弟子中出人頭地 !\n");
                return 1;
        }
        return 1;  
}
void upgrade_title(object ob,string arg)
{
        string title;
        title=arg+clear_title(ob->query("title"));
        ob->set("title",title);
}
string clear_title(string arg)
{
        if (strsrch(arg, "大理鎮南王府家臣") >= 0)
        {
                arg = replace_string(arg, "大理鎮南王府家臣","");
        }
        return arg;
}
void attempt_apprentice(object ob)
{
        if (ob->query("title") != "大理鎮南王府家奴")
        {
                command("shake "+this_player()->query("id"));
                command("say 我早已投身大理為臣，不再涉足江湖俗務，不能收徒了。\n");
                return;
        }
        if ((int)ob->query("shen") < 0  )
        {
                command("say 我大理段氏向來不與您這種黑道人物打交道，您請回吧！");
                return;
        }
        if ((int)ob->query("combat_exp") > 10000 || (int)ob->query("age") >17 )
        {
                command("say 鎮南王府收了大俠您，也讓你太屈尊了吧！");
                return;
        }
        command("say 很好，很好。既已入府，便當盡忠報主，這條性命也就不是自己的了。\n");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("gender") == "男性")
                ob->set("title","大理鎮南王府家丁");
        else
                ob->set("title","大理鎮南王府婢女");
}
