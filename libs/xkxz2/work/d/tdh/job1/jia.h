// by dubei
#include <ansi.h>
 
          
mapping *wheres=({
       (["chinese":                "扬州",
       "weizhi" :              "/d/city/bqp",
       "diming" :              "兵器铺",]),  
        });
mapping *terminis=({
       (["area":                "武当",
       "termini" :              "三清殿",]), 
            });
mixed names = ({
      (["name":                "反清义士",
      "where" :              "/d/job/npc/xiaoxiao",]), 
             });
void kill_ob(object me)
{     
      command("hehe");
      me->remove_killer(this_object());
    

}
string ask_job()
{
            object ob, me;
            int exp;
            mapping weizhis, target, termini;
            ob=this_player();
            me=this_object();
//            target = quest[random(sizeof(quest))];
           target = names[random(sizeof(names))];
            weizhis = wheres[random(sizeof(wheres))];
            termini = terminis[random(sizeof(terminis))];

            if(!ob->query("tdh_pass"))
            return "我们天地会的好汉一向忠肝义胆，阁下想加入天地会也要做几件惊天动地的事情，以表决心。";
            exp=(int)ob->query("combat_exp",1); 
            if(exp<20000)
            return "天地会一向被官府的走狗们追杀，你还太嫩，还是不要给自己惹祸上身吧。";
            if (interactive(ob) && ob->query_temp("tdh_baohu")
                && (int)ob->query_condition("thdbh_task"))  
             return "你任务没完成跑来做什麽？";
 
//           return "交给你的任务还没完成，先等会吧。";
//           if (interactive(ob)&&
//           (int)applicant->query_condition("guanfu_task"))
 
//        ob->set_temp("mark/gkill1",1);
	ob->set_temp("tdhbh_target", target["name"]); // 江湖宵小
        ob->set_temp("tdhbh_paths", target["where"]); // u/dubei/job/npc/xiaoxiao
        ob->set_temp("tdhbh_diming", weizhis["diming"]);
        ob->set_temp("tdhbhs_rooms", weizhis["weizhi"]); // d/city/bqp
        ob->set_temp("tdhbhc_weizhi", weizhis["chinese"]); // 扬州
        ob->set_temp("tdhbhc_termini", termini["termini"]); // 三清殿
        ob->set_temp("tdhbha_termini", termini["area"]); // 武当
        new("/d/job/wenshu1")->move(me);
//      me->move(me->query_temp("start_rooms"));
//        new(ob->query_temp("tdhbh_paths")->move(ob->query_temp("tdhbhs_rooms"));
//        ob->apply_condition("tdhbh_task", me->set_temp("tdhbh_time", random(30)+30));
        return "好吧，请你把「"+ob->query_temp("tdhbh_target")+"」从
「"+ob->query_temp("tdhbhc_weizhi")+"」的「"+ob->query_temp("tdhbh_diming")+"」护
送到「"+ob->query_temp("tdhbha_termini")+"」的「"+ob->query_temp("tdhbhc_termini")+"」";
}

int accept_object(object who, object ob,object me)
{

// check if accept corpse from player

        if ( !who->query("tdh_pass")) 
              return 0;
        if ( ob->query("id") != "guanfu lingpai" ) 
                return 0;
        if ( !who->query_condition("tdhbh_task") ) {
                command("say 你非我帮中兄弟，拿这个东西给我干什麽？");
                return 0;
        }

        who->delete_temp("tdhbh_target"); // 江湖宵小
        who->delete_temp("tdhbh_paths"); // u/dubei/job/npc/xiaoxiao
        who->delete_temp("tdhbhs_rooms"); // d/city/bqp
        who->delete_temp("tdhbhc_weishi"); // 扬州
        who->delete_temp("tdhbhc_termini"); // 三清殿
        who->delete_temp("tdhbha_termini"); // 武当
        who->delete_temp("tdhbh_diming");
        who->delete_temp("tdhbh_time"); 
//        who->clear_condition("tdhbh_task");
        who->add("tdh_job",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,tdh_times;
        if (!who) return;
       
        tdh_times=(int)who->query_condition("tdhbh_task",1);
        command("thumb " + who->query("id"));
        command("say 我们帮中的兄弟将永远记住你的大恩。");
       
        if ((int)who->query("combat_exp")<500000){
                pot=10+random(who->query("max_pot")/4);
                exp=((1+random(3))*90+(int)(tdh_times/5)); 
                who->add("potential",pot);
                if (who->query("potential") > who->query("max_pot"))
                        who->set("potential", who->query("max_pot"));   
                who->add("combat_exp",exp);
                who->add("gb_job",1);
                who->add("shen",exp*10);
                who->clear_condition("gb_mission");
       tell_object(who,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       chinese_number(exp/2)+"点正神\n"+
                       "你为天地会做了"+who->query("tdh_job",1)+"次工作。\n"
                       NOR);
                return;
       }
            exp=(1+random(4))*105+(int)(tdh_times/5);
          pot=10+random(who->query("max_pot")/5*2);
         who->add("potential",pot);
         if (who->query("potential") > who->query("max_pot"))
             who->set("potential", who->query("max_pot"));   
        who->add("combat_exp",exp);
        who->add("gb_job",2);
        who->add("shen",exp/2); 
       tell_object(who,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                        chinese_number(exp/2)+"点正神\n"+ 
                        "你为天地会做了"+who->query("tdh_job",1)+"次工作。\n"      
            NOR);
        who->clear_condition("tdhbh_task");
}       
 