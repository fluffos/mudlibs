void attempt_apprentice(object ob)
{
       object me  = this_object();
       mapping ob_fam = ob->query("family");
       mapping my_fam = me->query("family");        
       string name, new_name;

	   if (!ob_fam || ob_fam["family_name"] != "天龙寺"){
                command("say "+RANK_D->query_respect(ob)+"与本寺素无来往，不知此话从何谈起？");
                return;
                }

       if (!ob->query("tls")){
                command("say "+RANK_D->query_respect(ob)+"不是本寺出家弟子，我不能收你! ");
                return;
                }

	    if (ob_fam["generation"] <= my_fam["generation"] ){
                command("say "+RANK_D->query_respect(ob)+"，贫僧哪里敢当！");
                return;
                }
        if (ob_fam["generation"] == (my_fam["generation"] + 1)){
                command("say "+ob_fam["master_name"]+"最近禅功繁忙，你就过来跟着我学习吧。");
                command("recruit " + ob->query("id"));
				return;
                }    
       if((int)ob->query_skill("buddhism",1)<100){
          command("say 学武只是为了强身健体，而佛学才是我天龙的主要修行功课。");
          command("say 依我看"+RANK_D->query_respect(ob)+"禅宗方面的修为似乎还不够吧？");
          return;
          }
       if((int)ob->query_skill("qiantian-yiyang",1)<100){
          command("say 我天龙武学讲究内外兼修，依我看"+RANK_D->query_respect(ob)+"似乎还应在内功方面多下点功夫。");
          return;
          }
       if((int)ob->query("shen") > 100 || (int)ob->query("shen")+100 <0 ){
          command("say 我天龙寺乃清修之地，依我看"+RANK_D->query_respect(ob)+"似乎红尘未了,不宜继续修行。");
          return;
          }
       if(ob->query("tls")&&(string)ob->query("class") == "bonze" ){
          command("nod");
          command("say 阿弥陀佛，善哉！善哉！");        
          message_vision("$N双手合十，恭恭敬敬地跪了下来。\n",ob);
          name = ob->query("name");
          new_name = "了" + name[2..3];
          command("say 你这么刻苦用功，我就收下你吧。从今以后你的法名叫做"+new_name+"。");       
          ob->set("name", new_name);
          ob->set("shen", 0);
          command("recruit " + ob->query("id"));
          } 
 
 /*      else{
          command("smile");
          command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
          command("recruit " + ob->query("id") );
          }        
 */
}
 