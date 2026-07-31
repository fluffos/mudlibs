int accept_object(object ob, object obj)
{
        if (obj->query("id")!="gongji biao") {
                command("say 对不起，这东西我不要。");
                return 0;
        }
        if (obj->query("applicant")!=ob->query("id")) {
                command("say 这本功绩表你是从那里偷来的？");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name") != "大理段家" && !ob->query("dali/employee")) {
                command("say "+RANK_D->query_respect(ob)+"和本派并无关系，给我此物何意？");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query_temp("dali/uprank")!=1) {
                command("hmm "+getuid(ob));
                command("say 这本功绩表你是从那里偷来的？");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name")=="大理段家" && ob->query("combat_exp")< 10000000) {
                command("say "+RANK_D->query_respect(ob)+"你经验太底如何能统领三军。");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        ob->set_temp("arrest_yanqing",1);
        command("thumb");
		command("sigh");
		command("say 想我大理国一直国泰民安,可没想到我段家竟出了延庆这样的叛徒，若你能将他杀掉定会加官进爵！");
        remove_call_out("destroying");
        call_out("destroying", 1, obj);
        return 1;
        }
        
        
       
void destroying(object obj)
{
        destruct(obj);
        return;
}

