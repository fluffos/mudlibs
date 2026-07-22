// gaibang_npc.c, recruiting gb_dizi and promoting system
#include <ansi.h>

mapping *names = ({
        ({
                (["name":                   "打手",
                "award_exp" :              80,
                   "award_pot" :                          10]), 
                   (["name":                "盐枭",
                "award_exp" :              60,
                   "award_pot" :                          10]),
                   (["name":                "男弟子",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                  (["name":                "女弟子",
                "award_exp" :              90,
                   "award_pot" :                          20]), 
                  (["name":                "王坏水",
                "award_exp" :              80,
                   "award_pot" :                          20]), 
                    (["name":                "殷离",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                    (["name":                "星宿派弟子",
                "award_exp" :              80,
                   "award_pot" :                          10]), 
                     (["name":                "哈萨克牧民",
                "award_exp" :              60,
                   "award_pot" :                          20]), 
                    (["name":                "巴依",
                "award_exp" :              80,
                   "award_pot" :                          20]), 
                     (["name":                "京城客",
                "award_exp" :              60,
                   "award_pot" :                          20]), 
                   (["name":                "林震南",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                    (["name":                "土匪头",
                "award_exp" :              120,
                   "award_pot" :                          30]),  
                  (["name":                  "采花子",
                "award_exp" :              120,
                   "award_pot" :                          30]),  
        }),
        ({
                   (["name":                  "采药道长",
                "award_exp" :              80,
                   "award_pot" :                          20]),  
                 (["name":                  "温南扬",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "空空儿",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "王夫人",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "常遇春",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                 (["name":                  "苏普",
                "award_exp" :              100,
                   "award_pot" :                          30]), 
                 (["name":                  "严妈妈",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                 (["name":                  "谷虚道长",
                "award_exp" :              150,
                   "award_pot" :                          40]), 
                 (["name":                  "红衣武士",
                "award_exp" :              60,
                   "award_pot" :                          10]), 
                 (["name":                  "青衣武士",
                "award_exp" :              100,
                   "award_pot" :                          10]), 
                 (["name":                  "单伯山",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "单仲山",
                "award_exp" :              110,
                   "award_pot" :                          20]), 
                 (["name":                  "吴劲草",
                "award_exp" :              110,
                   "award_pot" :                          20]),  
                 (["name":                  "守寺僧兵",
                "award_exp" :              80,
                   "award_pot" :                          15]), 
                 (["name":                  "吴劲草",
                "award_exp" :              110,
                   "award_pot" :                          20]), 
                 (["name":                  "阿紫",
                "award_exp" :              120,
                 "award_pot" :                          30]), 
                 (["name":                  "神秘镖师",
                "award_exp" :              90,
                   "award_pot" :                          20]), 
                 (["name":                  "徐达",
                "award_exp" :              80,
                   "award_pot" :                          30]), 
                 (["name":                  "唐光雄",
                "award_exp" :              120,
                   "award_pot" :                          15]), 
                 (["name":                  "慧彰喇嘛",
                "award_exp" :              160,
                   "award_pot" :                          20]), 
                  }),
             ({
                 (["name":                  "宋青书",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "亲兵",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "白袍剑侠",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "出尘子",
                "award_exp" :              120,
                   "award_pot" :                          10]), 
                 (["name":                  "亲兵队长",
                "award_exp" :              150,
                   "award_pot" :                          10]), 
                 (["name":                  "殷野王",
                "award_exp" :              180,
                   "award_pot" :                          30]), 
                 (["name":                  "昌齐大喇嘛",
                "award_exp" :              260,
                   "award_pot" :                          50]), 
                 (["name":                  "采花贼",
                "award_exp" :              150,
                   "award_pot" :                          20]), 
                 (["name":                  "计老人",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "沙通天",
                "award_exp" :              160,
                   "award_pot" :                          30]), 
                  (["name":                  "侯通海",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                  (["name":                  "独行大侠",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "钱青健",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "冷谦",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "独脚大盗",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "说不得",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "彭连虎",
                "award_exp" :              180,
                   "award_pot" :                          40]), 
                 (["name":                  "彭莹玉",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                 (["name":                  "周颠",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "史季强",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                 (["name":                  "史伯威",
                "award_exp" :              120,
                   "award_pot" :                          23]), 
                 (["name":                  "天狼子",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "方碧琳",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "贝锦仪",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "史仲猛",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "史孟捷",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "善勇喇嘛",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "慧智大喇嘛",
                "award_exp" :              140,
                   "award_pot"   :                         40]), 
 
         }),
        ({
                  (["name":                  "摘星子",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                  (["name":                  "多吉大喇嘛",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                 (["name":                  "黯然子",
                "award_exp" :              160,
                   "award_pot"   :                         40]), 
                (["name":                  "胜谛喇嘛",
                "award_exp" :              160,
                   "award_pot"   :                         40]),
                 (["name":                  "武修文",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                 (["name":                  "静和师太",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "静闲师太",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                 (["name":                  "静玄师太",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "静道师太",
                "award_exp" :              100,
                   "award_pot"   :                         50]), 
                 (["name":                  "静风师太",
                "award_exp" :              180,
                   "award_pot"   :                         15]), 
                 (["name":                  "包不同",
                "award_exp" :              190,
                   "award_pot"   :                         80]), 
                 (["name":                  "邓百川",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                  "武敦儒",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "风波恶",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "温方施",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "温方悟",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "静空师太",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "史叔刚",
                "award_exp" :              200,
                   "award_pot"   :                         120]), 
                 (["name":                  "澄尚",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "澄心",
                "award_exp" :              120,
                   "award_pot"   :                         35]), 
                 (["name":                  "澄识",
                "award_exp" :              160,
                   "award_pot"   :                         20]), 
                 (["name":                  "澄思",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "澄明",
                "award_exp" :              110,
                   "award_pot"   :                         30]), 
                 (["name":                  "澄灭",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "静照师太",
                "award_exp" :              100,
                   "award_pot"   :                         40]), 
                 (["name":                  "静心师太",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "澄坚",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                   "大丑",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                 (["name":                    "二丑",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                    "三丑",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                    "澄知",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                    "灵智上人",
                "award_exp" :              180,
                   "award_pot"   :                         80]), 
         }), 
        ({
                  (["name":                    "灵智上人",
                "award_exp" :              100,
                   "award_pot"   :                         30]), 
                  (["name":                    "慕容复",
                "award_exp" :              160,
                   "award_pot"   :                         60]), 
                  (["name":                    "齐云敖",
                "award_exp" :              200,
                   "award_pot"   :                         40]), 
                  (["name":                    "桑结大喇嘛",
                "award_exp" :                         180,
                   "award_pot"   :                         60]), 
                  (["name":                    "智善大喇嘛",
                "award_exp" :                         180,
                   "award_pot"   :                         50]), 
                  (["name":                    "温方达",
                "award_exp" :                        180,
                   "award_pot"   :                         50]), 
                  (["name":                    "温方义",
                "award_exp" :                        180,
                   "award_pot"   :                         50]), 
                  (["name":                    "李莫愁",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "黛绮丝",
                "award_exp" :                       240,
                   "award_pot"   :                         80]), 
                  (["name":                    "潇湘子",
                "award_exp" :                      180,
                   "award_pot"   :                         50]), 
                  (["name":                    "血刀老祖",
                "award_exp" :                         260,
                   "award_pot"   :                         70]), 
                  (["name":                    "玄悲大师",
                "award_exp" :                         180,
                   "award_pot"   :                         50]), 
                  (["name":                    "玄慈大师",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "玄生大师",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "谢逊",
                "award_exp" :                     270,
                   "award_pot"   :                         90]), 
                  (["name":                    "殷天正",
                "award_exp" :              180,
                   "award_pot"   :                         40]), 
                  (["name":                    "杨逍",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "范遥",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "韦一笑",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "玄难大师",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "灭绝师太",
                "award_exp" :              180,
                   "award_pot"   :                         60]),  
                  (["name":                    "达而巴",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
            }), 
          ({
                  (["name":                    "丁春秋",
                "award_exp" :                       270,
                   "award_pot"   :                         100]), 
                  (["name":                    "风陵师太",
                "award_exp" :                        180,
                   "award_pot"   :                         60]), 
                  (["name":                       "何铁手",
                "award_exp" :                        200,
                   "award_pot"   :                         80]), 
                  (["name":                    "慕容博",
                "award_exp" :                        180,
                   "award_pot"   :                         60]), 
                  (["name":                    "枯荣长老",
                "award_exp" :                         180,
                   "award_pot"   :                         80]), 
                  (["name":                    "渡厄",
                "award_exp" :                     180,
                   "award_pot"   :                         60]), 
                  (["name":                    "渡劫",
                "award_exp" :                    180,
                   "award_pot"   :                         60]), 
                  (["name":                    "渡难",
                "award_exp" :                     180,
                   "award_pot"   :                         60]), 
                  (["name":                    "成昆",
                "award_exp" :                    180,
                   "award_pot"   :                         50]), 
                  (["name":                    "玄难大师",
                "award_exp" :                     180,
                   "award_pot"   :                         40]), 
                  (["name":                    "玄慈大师",
                "award_exp" :                     180,
                   "award_pot"   :                         40]), 
 
           }), 
                   ({ 
                  (["name":                              "金轮法王",
                    "award_exp" :                                  180,
                  "award_pot"   :                         60]), 
                  (["name":                              "鸠摩智",
                    "award_exp" :                                  160,
                  "award_pot"   :                         60]), 
                  (["name":                              "胡逸之",
                    "award_exp" :                                  160,
                  "award_pot"   :                         50]), 
                  (["name":                              "无名老僧",
                    "award_exp" :                                  180,
                  "award_pot"   :                         60]), 
                  (["name":                              "张无忌",
                    "award_exp" :                                 180,
                  "award_pot"   :                         60]), 
                  (["name":                              "归辛树",
                    "award_exp" :                                  260,
                  "award_pot"   :                         120]), 
                  (["name":                              "归二娘",
                    "award_exp" :                          200,
                  "award_pot"   :                         70]), 
                  (["name":                              "张三丰",
                    "award_exp" :                                  320,
                  "award_pot"   :                         80]), 
                   (["name":                               "成昆",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                  (["name":                                      "渡厄",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                  (["name":                               "渡劫",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                   (["name":                               "渡难",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
          }),
     });

void kill_ob(object me)
{     
      command("hehe");
      me->remove_killer(this_object());
}

string ask_job(string arg)
{
                    object applicant, me;
                    mapping target;
                                  int exp,position;

                    applicant = this_player();
                    me = this_object();
                                  
                   exp = (int)applicant->query("combat_exp",1);

                   if (!applicant->query("gb_pass"))
                    return "你没有通过接引弟子的考验，我可不敢用你。"; 
                  if(exp>2000000)
                 return "阁下武艺高强，在下可不敢劳烦您老。";
                      if (interactive(applicant) && applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))  
                     return "让你去杀"+applicant->query_temp("promotion_target")+"还不快去？";

                         if (interactive(applicant) && !applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))  
                     return "教给你的任务你还没完成怎么又跑回来了！";   

           if (interactive(applicant) && applicant->query_temp("gb_job_exp") || applicant->query_temp("gb_job_pot")) 
                                      return "你的任务还没完成，怎么就跑回来了。"; 

                    if (interactive(applicant)&&
                     (int)applicant->query_condition("xx_task"))
                  {
                  applicant->delete("gb_job");
                   tell_object(applicant,HIW"你从此不再是丐帮帮众了。\n"NOR);
                    return "竟敢偷偷为丁老怪效力，从此你以后和我丐帮再没关系了！\n"; 
                    }
        if (interactive(applicant) &&
                (int)applicant->query_condition("guanfu_task"))
        return "你已经投靠官府这棵大树，还来我们穷要花子这干什麽？\n";

    if (interactive(applicant) &&
        (int)applicant->query_condition("gb_busy"))  
         return "现在我可没有给你的任务，等会再来吧。\n";
       if (interactive(applicant) &&
             (int)applicant->query_condition("dali_songxi"))
            return "你已经在震南王府高就，到我们这里寻什么开心？\n";
    if(exp>=1100000)
         position=7;
     else if(exp>=850000)
          position=6;
     else if(exp>=640000)
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
        applicant->set_temp("promotion_target", target["name"]);
              applicant->set_temp("gb_job_exp", target["award_exp"]);
              applicant->set_temp("gb_job_pot", target["award_pot"]);
        applicant->set_temp("assigned_by", me->query("name"));  
        applicant->apply_condition("gb_mission",random(20)+30);
        return "好吧，最近「"+applicant->query_temp("promotion_target")+"」一直和我丐帮作对，你前去设法将此人除掉！";
}

int accept_object(object apper, object ob)
{
    object me = this_object();
// check if accept corpse from player

        if ( !apper->query("gb_pass")) 
              return 0;
        if ( ob->query("id") != "corpse" ) {
                command("say 这东西我要来没用。");
                return 0;
        }
        if ( !apper->query_temp("promotion_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if ( !apper->query_temp("gb_job_exp") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if ( !apper->query_temp("gb_job_pot") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if ( ob->query("victim_name") 
        != apper->query_temp("promotion_target") ) {
                command("say 嘿嘿。。。，你杀错人了。");
                return 0;
        }
     if ( ob->query("victim_user") ) {         // is it player's corpse?
                command("say " + RANK_D->query_rude(apper) + 
                        "，居然敢欺骗本长老，拿命来把！");
                call_out("killing_object",1,apper);
                return 0;
        }
        if ( ob->query("kill_by") != apper) {
                command("say 这个任务似乎不是你自己完成的吧？");
                command("chat "+ apper->name(1) +"作弊，大家说怎么办？");
                return 0;
        }
        if (interactive(apper) &&
                (int)apper->query_condition("xx_task")){
            command("chat "+ apper->name(1)+"偷偷为星宿派效力，现在把他驱逐出丐帮。\n");
            command("chat "+ apper->name(1)+"这等武林败类，人人得而诛之!!!\n");
            apper->delete("gb_pass");
            apper->delete("gb_job");
             return 1; 
         }

              
        apper->delete_temp("assigned_by");
        apper->delete_temp("promotion_target");
        apper->clear_condition("gb_mission");
        call_out("destroying", 1, ob);
        call_out("ok", 1, apper);
        return 1;
}

void ok(object apper)
{
        int job_time;
        if (!apper) return;
        command("thumb " + apper->query("id"));
        command("say 你为丐帮立下了功劳，我们绝不会亏待你的。");
 
              job_time=(int)apper->query("gb_job")/800;
                    if (job_time <1) job_time = 0;

            tell_room(environment(),
           		HIY "吴长老在"+ apper->name()
		+ "的耳边低声似乎在讲解着什麽，一会儿"+ apper->name() +"不住点头，面呈喜色。\n"NOR, ({ apper }));
            write(HIY"吴长老伏身在你耳边悄声指点了你一些武功要领，你听了一会渐有所悟，感到自己武学修为有所提高。\n"NOR);
               apper->add("combat_exp", apper->query_temp("gb_job_exp"));
               apper->add("potential", apper->query_temp("gb_job_pot"));
                    apper->add("combat_exp",job_time);
             if(apper->query("potential") > apper->query("max_pot")) 
         apper->set("potential", apper->query("max_pot"));
           apper->add("gb_job",1); 
                   apper->delete_temp("gb_job_exp");
                   apper->delete_temp("gb_job_pot");
                  return;
 
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
string ask_fangqi()
{
            object me;
            int exp;

           me = this_player();
           exp = me->query("combat_exp",1);
           if(!me->query("gb_pass"))
           return "你非我丐帮英雄,跑这里瞎嚷嚷什麽?";
           if(me->query_condition("gb_mission")<=1)
          return "你没有领任务,跑这里瞎嚷嚷什麽?";
          me->clear_condition("gb_mission");
          me->add("combat_exp",-10+random(15));
                if(exp>500000){
                   me->apply_condition("gb_busy",6+random(4));
         me->add("combat_exp",-30);
          me->add("gb_job",-2+random(2));
               }
            me->apply_condition("gb_busy",6+random(4));
                me->delete_temp("assigned_by");
           me->delete_temp("promotion_target");
                   me->delete_temp("gb_job_exp");
                   me->delete_temp("gb_job_pot");
          me->add("gb_job",-1);
        return "既然你干不了也没关系,再去刻苦练功吧,以后再来为丐帮出力!";
}
void destroying(object obj)
{
        destruct(obj);
        return;
}
string ask_gonglao(object who)
{
            object me;
            int i;
             
                    me = this_player();

         i =(int)me->query("gb_job"); 

           if(!me->query("gb_job"))
           return "你没为我丐帮出过任何力，跑来问什么功劳呢?"; 

               message_vision("$N掏出一本册子翻了翻，指着上面的墨迹对$n说道，这上面共记载着你历次的功劳，目前已记功" + chinese_number(i) + "次。\n",who,me);
        return "我丐帮向来赏罚分明，继续努力吧！随手将功劳簿揣入怀中。";
}
