 int recognize_apprentice(object ob)
 {
     if (ob->query("party/party_name")!= "权力帮")
     {
     message_vision("$N摇了摇头。\n",this_object());
     command("say "+ob->query("id")+"不是权力帮的我不教。\n");
     return 0;
     }
        if(ob->query("party/tasks") < this_object()->query("accept"))
          {
          command("say 你在权利帮级别还不够,去问问柳军师吧!\n");
          return 0;
          }
           if(ob->query("shen") > 0)
             {
               command("say 你怎么成了正派人士，快些走开，不然我杀了你!\n");
               return 0;
          }
     return 1;
 }
      
