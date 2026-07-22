// jing.h
// create by host jan,8 1998

void attempt_apprentice(object ob)
{
     object me;
     me = this_player();

     if ((string)ob->query("gender") != "女性" )
      {
        command("say 我怎么能够收男子为徒呢？");
       return;
      }
     if ((int)ob->query("shen") < 0)
        {
        command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                 "是否还做得不够？");
                return ;
        }
    if( (string)me->query("class")=="bonze" )
       {
             command("nod");
             command("recruit " + ob->query("id"));
       }
     
      else {

                command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去静心那里受戒。\n");
            }

}
