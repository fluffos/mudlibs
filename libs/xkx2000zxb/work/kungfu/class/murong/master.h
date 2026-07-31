//Cracked by Kafei
// arthurgu 1999.9

void attempt_apprentice(object ob)
{
        mapping fam;
       string gsmr;

      command("smile"+ob->query("id"));
        if (ob->query("class")=="bonze") {
         if (ob->query("gender")=="女性")
                          command ("say
燕子坞不收留出家人，师太请回吧。");
                else
                          command ("say
燕子坞不收留出家人，大师请回吧。");
                return;
                                          }
 
        if( ob->query("family/family_name") ==
"丐帮"&&ob->query("rank")>1) {
                command ("say
阁下是丐帮高手，燕子坞不敢收留。");
           return;
                              }
        if (ob->query("family/family_name")!="姑苏慕容"
                && ob->query("combat_exp") >= 100000 ) 
         {
                switch (ob->query("family/family_name")) 
             {
                case "武当派" :
                        command("say
道长请回吧，燕子坞不敢让您屈尊。");
                        break;
               case "全真教" :
                        command("say
燕子坞不信奉道教，这位道兄还是另请高明吧。");
                        break;
                case "星宿派" :
                        command("say
我家公子最很丁老贼，你快滚！");
                        break;
                case "白驼山" :
                        command("say
我家公子最痛很白驼弟子,你走吧！");
                        break;
                case "华山派" :
                        command("say
华山乃是名门正派，燕子坞不敢让您屈尊。");
                        break;
                case "血刀门" :
                        command("say
燕子坞不收血刀门的淫贼,还不快滚！");
                        break;
                default :
                        command("say
对不起，我不能收你，你还是另请高明吧。");
                }                
        return;
          }

        if (ob->query("family/family_name")!="姑苏慕容") {
        if (ob->query("gender")=="女性") gsmr="使女";
        else  gsmr = "男丁";
        command("say 好吧，我就收下你做个" + gsmr + "吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","姑苏慕容 燕子坞"+gsmr);
        ob->set("mr/rank", 1);
	  return;
   
                                                           }
   }
   

