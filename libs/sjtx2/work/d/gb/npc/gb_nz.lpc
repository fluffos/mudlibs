// gaibang_npc.c, recruiting gb_dizi and promoting system

#include <ansi.h>

mixed names = ({
	({
          "海砂帮帮主元广波", "巨鲸帮帮主麦鲸","神拳门主过三拳",
//          "巫山帮帮主梅石坚","三江帮舵主艳娘们","泰山单家掌门单正",
  //        "五凤刀掌门孟正鹏","丐帮叛逆徐长老",
	}),
       });
mixed ids=({
          ({
            "yuan guangbo","mai jing","guo sanquan",
    //        "mei shijian","yan woman","shan zheng",
      //      "meng zhengpeng","xu zhanglao",
          }),
          });

mixed directory=({
                ({
                 "/u/hunthu/npc/yuan","/u/hunthu/npc/mai",
                 "/u/hunthu/npc/guo",
                 // "/u/hunthu/npc/yan",
                 //"/u/hunthu/npc/shan","/u/hunthu/npc/meng",
                 //"/u/hunthu/npc/xu",
               }),
               });
mixed wheres=({
             ({
               "杨州","苏州","杭州","福州","襄阳","嘉兴",
               "武当山","明教","慕容世家","少林寺",
            })
            });
mixed wherei=({
               "/d/city/bingqin","/u/beyond/suzhou/majiu",
                "/d/fuzhou/biaoju","/d/xiangyang/eroad1","/d/jiaxing/tieqiang",
                "/d/wudang/guangchang","/d/mingjiao/qianting","/u/beyond/mr/yanziwu",
                "/d/shaolin/ting",
               })
               });
 //void killing_object(object who);

string ask_me()
{
	mapping fam, my_fam;
        object applicant, me,ob;
	int position,xx;
	string target,weizhi,t_id,weizhi_w;
	applicant=this_player();
	me=this_object();
	my_fam  = me->query("family");
// check if this player is gb dizi and meet the requirements for promotion
     if(!applicant->query("gb_pass"))
       return "你从没为帮中做过工作，居然来找我?!\n";
       if ((int)applicant->query("gb_job",1)<100)
            return RANK_D->query_respect(applicant)+
           "为我帮贡献太少，这么大的任务给你我可不放心。\n";
       if ((int)applicant->query("combat_exp",1)<280000)
            return RANK_D->query_respect(applicant)+
           "武功未成，为帮中出马我可不放心。\n";
       if (interactive(applicant) &&
        (int)applicant->query_condition("gb_mission"))
        return "你在吴长老那的任务还没完成，居然跑来找我?!\n";
        if (interactive(applicant) &&
        (int)applicant->query_condition("gb_jiaomie"))
        return "不是让你去剿灭"+applicant->query_temp("promotion_target)
               +"了么，快快去干。\n";
     	position=random(sizeof(names[0]));
        xx=random(sizeof(wheres[0]));
        target = names[0][position];
        weizhi = wheres[0][xx];
        t_id=ids[0][position];
        weizhi_w=wherei[0][xx];
        if (ob=find_living(t_id))
          destruct(ob);
        ob=new(directory[0][position]);
        ob->move(weizhi_w);
        applicant->set_temp("promotion_target", target);
        applicant->apply_condition("gb_jiaomie",60);
        return target+"和手下帮众多行不义，帮主已经颁下青竹追杀令\n"
               +"但是他们已经闻风逃窜至"+weizhi+"一带，你即刻出发\n"
               +"剿灭这王八蛋，收回青竹令给我。\n";
}



/*string ask_job()
{
  object applicant, me;
  int exp,position;
  string target;
   applicant=this_player();
   me=this_object();
   if(!applicant->query("gb_pass"))
   return "你没有通过接引弟子的考验，我可不敢用你。\n";
    exp=(int)applicant->query("combat_exp",1);
    if(exp>1500000)
      return "阁下武艺高强，在下可不敢劳烦您老。\n";
     if (interactive(applicant) &&
            	(int)applicant->query_condition("gb_mission"))
       return "让你去杀"+applicant->query_temp("promotion_target")+"还不快去？\n";
    if (interactive(applicant) &&
      	(int)applicant->query_condition("gb_busy"))
         return " 现在我可没有给你的任务，等会再来吧。\n";
    if(exp>=700000)
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
        applicant->apply_condition("gb_mission",30);
        applicant->apply_condition("gb_busy",10);
        return "好吧，你去把" + target +"这狗贼给杀了，提他人头来见我！\n";
}*/
 int accept_object(object who, object ob,object me)
{
//        int val;
//        object me = this_object();
// check if accept corpse from player

        if ( !who->query("gb_pass"))
              return 0;
        if ( ob->query("id") != "qing zhuling" ) {
		command("say 这东西我要来没用。");
		return 0;
	}
        if ( !who->query_temp("promotion_target") ) {
		command("say 好啊！不过你得先申请任务。");
                return 0;
	}

/*        if ( who->query_temp("assigned_by") != me->query("name") ) {
		command("say 好样的！快拿去给给你任务的舵主吧。");
                return 0;
        }*/

// all right, now it's time to check if the corpse is correct ;
// there is still a bug here, since i can't check if corpse is
// npc's corpse or a player who has the same name as that npc,
// although it's illegal.
/*	if ( ob->query("kill_name")
	!= who->query_temp("promotion_target") ) {
		command("say 嘿嘿。。。，你杀错人了。");
		return 0;
	}*/
/*	if ( ob->query("victim_user") ) { 	  // is it player's corpse?
		command("say " + RANK_D->query_rude(who) +
			"，居然敢欺骗本长老，拿命来把！");
		call_out("killing_object",1,who);
		return 0;
	}*/

// benifits from 升袋, 10 maxneili + 1 begging,sttealing level
	command("applaud " + who->query("id"));
        command("say 做得好，行侠仗义正是本帮本色。\n");
//        me->add_money("gold",10);
  //      command("give gold to"+who->query("id"));
//        val=1+random(9);
        call_out("destroying", 1, me, ob);
        who->add("potential",100+random(100));
         if (who->query("potential") > who->query("max_pot"))
                who->set("potential", who->query("max_pot"));
        who->add("combat_exp",1200);
        who->add("gb_job",5);
//	who->delete_temp("assigned_by");
	who->delete_temp("promotion_target");
        who->clear_condition("gb_jiaomie");
	return 1;
       }
/*         who->add("potential",random(10+who->query("max_pot")/3)*2);
         if (who->query("potential") > who->query("max_pot"))
             who->set("potential", who->query("max_pot"));
        who->add("combat_exp",(1+random(8))*100);
        who->set("gb_job",2);
	who->delete_temp("assigned_by");
	who->delete_temp("promotion_target");
        who->clear_condition("gb_mission");
	return 1;*/
}


void killing_object(object who)
{
	object me = this_object();
	me->kill_ob(who);
	who->unconcious();
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
/* void gbzl_apprentice(object ob)
{
        string prev_family_name;

        if ( (int)ob->query("gb_bags") >= 2
	&& (prev_family_name = ob->query("family/family_name")) != "丐帮" ) {
                command("say 丐帮可容不下你这种背信弃义的小人！");
                return;
        }
        if ( prev_family_name != "丐帮"){
                 if((int)ob->query("jobs")<2000)
                     command("say 你为丐帮未尽全力，我还要看你的表现。\n");
                      return;
                     command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好为本门效力，在帮主面前有一个好的表现。\n");
        command("recruit " + ob->query("id"));
                    ob->set("gb_bags", 6);
                    ob->set("title",sprintf("丐帮%s袋弟子",
                  chinese_number(ob->query("gb_bags"))) );
                   return;
          }
            if((int)ob->query("gb_bags")<6)
              {
               command("say + RANK_D->query_respect(ob)+在帮中资历尚浅，要继续努力。\n");
               return;
              }
        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好为本门效力，在帮主面前有一个好的表现。\n");
        command("recruit " + ob->query("id"));
        return;
    }*/
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
