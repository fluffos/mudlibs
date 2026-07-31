void init()
{
        object ob = this_player();
        if( ob->query_temp("done") )
          {
         command("say 抓住他，他毁了小少爷的五行车。");
         kill_ob(ob);
         return ;
         }
return;
}
