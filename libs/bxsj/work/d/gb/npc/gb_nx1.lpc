// gaibang_npc.c, recruiting gb_dizi and promoting system

#include <ansi.h>

mixed names = ({
        ({
        "打手", "盐枭", "男弟子","女弟子","王坏水","殷离","哈萨克牧民",
        "土匪头", "林震南", "巴依", "采花子","京城客","星宿派弟子",
        }),
        ({
         "守寺僧兵","采药道长", "道觉禅师","道品禅师","道尘禅师","道相禅师",
         "道一禅师","严妈妈","常遇春","闻苍松","胡青牛","谷虚道长","庄铮","吴劲草",
         "神秘镖师","阿紫","采花子","青衣武士","王夫人","红衣武士","徐达","颜垣",
         "唐光雄","单小山","单仲山","单伯山","空空儿","独行侠",
         "苏鲁克","苏普",
        }),
        ({
         "独脚大盗","慧合尊者","慧光尊者","慧洁尊者","慧色尊者","亲兵","宋青书",
         "慧空尊者","慧虚尊者","慧如尊者","辛然","殷野王","出尘子","李四",
         "白衣武士","黑衣大盗","彭连虎","亲兵队长","独行大侠","白袍剑侠",
         "慧真尊者", "周颠","说不得","彭莹玉","张中", "冷谦","狮吼子", "天狼子",
         "侯通海","沙通天","采花贼","钱青健","丁同","计老人","史伯威","史孟捷","史季强",
         "史仲猛","李明霞","苏梦清","贝锦仪","方碧琳",
         }),
        ({
          "包不同","风波恶","邓百川","澄观","澄和","静迦师太","静照师太",
          "樊一翁","武敦儒","飞天子","黯然子","静虚师太","静心师太","静风师太",
          "静真师太", "静闲师太","静玄师太","静和师太","静空师太","静道师太",
          "静慧师太",
           "澄寂","澄坚","澄净","澄灵","澄灭","澄明","澄尚","澄识","澄思","澄心",
          "澄信","澄行","澄意","澄欲","澄知","澄志","摘星子","史叔刚","武修文",
         }),
        ({
          "殷梨亭","莫声谷","张松溪","俞岱岩",
          "玄难大师","玄苦大师","玄生大师","玄慈大师","玄悲大师","俞莲舟","宋远桥","张松溪","俞岱岩",
          "赵爵爷","殷天正","韦一笑","谢逊","杨逍","范遥","慕容复","黛绮丝","潇湘子","李莫愁",
        }),
     });

void kill_ob(object me)
{
      command("hehe");
      me->remove_killer(this_object());
 //       remove_killer(me);

}
string ask_job()
{
  object applicant, me;
  int exp,position;
  string target;
   applicant=this_player();
   me=this_object();
   if(!applicant->query("gb_pass"))
   return "你没有通过接引弟子的考验，我可不敢用你。";
    exp=(int)applicant->query("combat_exp",1);
    if(exp>1500000)
      return "阁下武艺高强，在下可不敢劳烦您老。";
     if (interactive(applicant) && applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))
       return "让你去杀"+applicant->query_temp("promotion_target")+"还不快去？";
     if (interactive(applicant) && !applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))
       return "交给你的任务还没完成，先等会吧。";
    if (interactive(applicant)&&
       (int)applicant->query_condition("xx_task"))
   {
       // command("chat "+ applicant->name(1)+"偷偷为星宿派效力，现在把他驱逐出丐帮。");
     //   command("chat"+ applicant->name(1)+"这等武林败类，人人得而诛之!!!\n");
        applicant->delete("gb_job");
       tell_object(applicant,HIW"你从此不再是丐帮帮众了。\n"NOR);
       return "混蛋，竟敢偷偷为丁老怪效力，滚！！！\n";
      }
    if (interactive(applicant) &&
        (int)applicant->query_condition("gb_busy"))
         return "现在我可没有给你的任务，等会再来吧。\n";
    if(exp>=640000)
         position=5;
     else if(exp>=300000)
         position=4;
     else if(exp>=100000)
          position=3;
     else if(exp>=50000)
          position=2;
     else
          position=1;

        target = names[position-1][random(sizeof(names[position-1]))];
        applicant->set_temp("promotion_target", target);
        applicant->set_temp("assigned_by", me->query("name"));
        applicant->apply_condition("gb_mission",40);
    //   applicant->apply_condition("gb_busy",10);
        return "好吧，你去把" + target +"这狗贼给杀了，提他人头来见我！";
}

int accept_object(object who, object ob,object me)
{

// check if accept corpse from player

        if ( !who->query("gb_pass"))
              return 0;
        if ( ob->query("id") != "corpse" ) {
                command("say 这东西我要来没用。");
                return 0;
        }
        if ( !who->query_temp("promotion_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if ( ob->query("victim_name")
        != who->query_temp("promotion_target") ) {
                command("say 嘿嘿。。。，你杀错人了。");
                return 0;
        }
     if ( ob->query("victim_user") ) {         // is it player's corpse?
                command("say " + RANK_D->query_rude(who) +
                        "，居然敢欺骗本长老，拿命来把！");
                call_out("killing_object",1,who);
                return 0;
        }
        if ( ob->query("kill_by") != who) {
                command("say 这个任务似乎不是你自己完成的吧？");
                command("chat "+ who->name(1) +"作弊，大家说怎么办？");
                return 0;
        }
        if (interactive(who) &&
                (int)who->query_condition("xx_task")){
            command("chat"+ who->name(1)+"偷偷为星宿派效力，现在把他驱逐出丐帮。\n");
            command("chat"+ who->name(1)+"这等武林败类，人人得而诛之!!!\n");
            who->delete("gb_pass");
            who->delete("gb_job");
             return 1;
         }
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,job_time;
        if (!who) return;
        job_time=(int)who->query("gb_job",1);
        command("thumb " + who->query("id"));
        command("say 你为丐帮立下了功劳，我们绝不会亏待你的。");

        if ((int)who->query("combat_exp")<300000){
                pot=10+random(who->query("max_pot")/4);
                exp=((1+random(3))*90+(int)(job_time/5));
                who->add("potential",pot);
                if (who->query("potential") > who->query("max_pot"))
                        who->set("potential", who->query("max_pot"));
                who->add("combat_exp",exp);
                who->add("gb_job",1);
                who->add("shen",exp*10);
                who->delete_temp("assigned_by");
                who->delete_temp("promotion_target");
                    who->clear_condition("gb_mission");
       tell_object(who,HIW"你被奖励了：\n" +
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       chinese_number(exp/2)+"点正神\n"+
                       "你为丐帮做了"+job_time+"次工作。\n"
                       NOR);
                return;
       }
            exp=(1+random(4))*105+(int)(job_time/5);
          pot=10+random(who->query("max_pot")/5*2);
         who->add("potential",pot);
         if (who->query("potential") > who->query("max_pot"))
             who->set("potential", who->query("max_pot"));
        who->add("combat_exp",exp);
        who->add("gb_job",2);
        who->add("shen",exp/2);
        who->delete_temp("assigned_by");
        who->delete_temp("promotion_target");
        who->clear_condition("gb_mission");
         tell_object(who,HIW"你被奖励了：\n" +
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                        chinese_number(exp/2)+"点正神\n"+
                      "你为丐帮完成了"+job_time+"次工作。\n"
            NOR);
}
void gb_apprentice(object ob)
{
        string prev_family_name;

        if ( (int)ob->query("gb_bags") >= 2
       && (prev_family_name = ob->query("family/family_name")) != "丐帮" ) {
                command("say 丐帮可容不下你这种背信弃义的小人！");
                return;
        }
        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
        command("recruit " + ob->query("id"));
        if ( prev_family_name != "丐帮")
                ob->set("gb_bags", 1);
        ob->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(ob->query("gb_bags"))) );
}
void killing_object(object who)
{
        object me = this_object();
        me->kill_ob(who);
        who->unconcious();
}

void destroying(object obj)
{
        destruct(obj);
        return;
}
