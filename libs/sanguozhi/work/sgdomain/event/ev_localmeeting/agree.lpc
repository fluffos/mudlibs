// agree.c
// by fire on Auguest 06 1998
// this is used for localmeeting to handle agree of suggestion
#include <localmeeting.h>
void begin_judge(int task_id);
void dis_over(int task_id);
string get_problem(int task_id);
void do_agree_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ag,*dg,*ng;
        string p_act;
        int p_ran;
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        if(member_array(t_id,ag)!=-1)
                pos=1; // agree
        
        if(member_array(t_id,dg)!=-1)
                pos=2; // disagree
        if(member_array(t_id,ng)!=-1)
                pos=3; // no idea
        p_ran=random(5);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
                case 0:
                        p_act="$N对$T一拱手，道：$R真高见也。\n";
                        break;
                case 1:
                        p_act="$N一拍$T的肩膀，道：高！高！实在高明。\n";
                        break;
                case 2:
                        p_act="$N对$T笑道：$R之见与$s不谋而和呀。\n";
                        break;
                case 3:
                        p_act="$N点头道：我支持$m$R的观点。\n";
                        break;
                default:
                        p_act="$N一拍大腿，道：$m$R所言极是。\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        switch(pos)
        {
                case 1:
                        ag+=({my_id});
                        TASK_D->set_task(task_id,"supportgrp",ag);
                        p_act="$N接着道：我支持"+p_problem+"。";
                        break;
                case 2:
                        dg+=({my_id});
                        TASK_D->set_task(task_id,"againstgrp",dg);
                        p_act="$N接着道：我反对"+p_problem+"。";
                        break;
                default:
                        ng+=({my_id});
                        TASK_D->set_task(task_id,"neutalgrp",ng);
                        p_act="$N接着说道：对于"+p_problem+"，我没有看法。";
                        break;
        }
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed agree_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "现在没有什么议题。\n";
        if(sub=="train") 
             return "训练没什么好讨论的，用cmd me表示参加。\n";   
		if(sub=="over")
             return "提前散会没什么好讨论的，不同意用cmd against表示反对。\n";   
        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "你同意谁的意见？\n";
        if(t_id==my_id)
                return "你当然同意你的意见了。\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s就没有参加会议。\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s还没有发表意见。\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "你已经发表过高见了。\n";
        do_agree_sb(task_id,my_id,t_id);
        return 0;
}
void do_disagree_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ag,*dg;
        string p_act;
        int p_ran;
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        if(member_array(t_id,ag)!=-1)
                pos=1; // agree
        
        if(member_array(t_id,dg)!=-1)
                pos=2; // disagree
        p_ran=random(5);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
                case 0:
                        p_act="$N皱眉道：$m$R之见似乎与理不合。\n";
                        break;
                case 1:
                        p_act="$N对$T摇头道：$R之见，$s不敢苟同。\n";
                        break;
                case 2:
                        p_act="$N摇摇头，道：$m$R所言非我心所想。\n";
                        break;
                case 3:
                        p_act="$N道：我反对$m$R的观点。\n";
                        break;
                default:
                     p_act="$N沉吟片刻，道：$m$R所言似乎有理，其实不然。\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        switch(pos)
        {
                case 2:
                        ag+=({my_id});
                        TASK_D->set_task(task_id,"supportgrp",ag);
                        p_act="$N接着道：我支持"+p_problem+"。";
                        break;
                default:
                        dg+=({my_id});
                        TASK_D->set_task(task_id,"againstgrp",dg);
                        p_act="$N接着说道：我反对"+p_problem+"。";
                        break;
        }
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed disagree_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "现在没有什么议题可反对。\n";
        if(sub=="train") 
             return "训练没什么好讨论的，用cmd me表示参加。\n";   
		if(sub=="over") {
			object o;
			o=CHAR_D->find_char(my_id);
			if(!objectp(o)) return; // impossible
			o->simple_action("$N道：别忙，别忙散会，我还有话讲。\n");
			dis_over(task_id);
			return 0;
		}

        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "你反对谁的意见？\n";
        if(t_id==my_id)
                return "你反对你自己？\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s就没有参加会议。\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s还没有发表意见。\n",p_name);
        if(member_array(t_id,ng)!=-1)
                return sprintf("%s的意见没法反对。\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "你已经发表过高见了。\n";
        do_disagree_sb(task_id,my_id,t_id);
        return 0;
}
void do_neutral_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ng;
        string p_act;
        int p_ran;
        ng=TASK_D->get_task(task_id,"neutalgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        pos=3; // neutral
        
        p_ran=random(2);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
           case 0:
	      p_act="$N道：$m$R之见好像对，也好像不对，总之，恩……\n";
              break;
           default:
              p_act="$N皱眉道：$m$R所言，支持不是，不支持也不是，唉……\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        ng+=({my_id});
        TASK_D->set_task(task_id,"neutalgrp",ng);
        p_act="$N接着道：对于"+p_problem+"，我没有看法。\n";
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed neutral_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "现在没有什么议题可表示中立。\n";
        if(sub=="train") 
             return "训练没什么好讨论的，用cmd me表示参加。\n";   
		if(sub=="over")
             return "提前散会没什么好讨论的，不同意用cmd against表示反对。\n";   
        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "你对谁的意见表示中立？\n";
        if(t_id==my_id)
                return "你对你自己表示中立？\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s就没有参加会议。\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s还没有发表意见。\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "你已经发表过高见了。\n";
        do_neutral_sb(task_id,my_id,t_id);
        return 0;
}
