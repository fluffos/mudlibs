// resign.c 
// by row on May 29, 1999
// used for player char to risign a job
#include <ansi.h>
string job_id;
string job_memo1;
  string *forbiden = ({"xu zijiang", "hua tuo", "landlord","train"});
void confirm_resign(string p_idd,mixed p_input)
{
        string p_id;
        int rep,cut_rep;
        this_body()->modal_pop();
        p_id = this_body()->query_id()[0];
//        cut_rep=random(50);
        if(p_input=="yes"){
                write("你决定放弃"HIY""+job_memo1+""NOR"的工作。\n");
                this_body()->resign_job(p_idd);
                rep=CHAR_D->get_char(p_id,"reputation");
                if( (rep-cut_rep)<10 ){
                        return;
                }
		cut_rep=random(rep/20);
		if (cut_rep>250) cut_rep=250;
                rep=rep-cut_rep;
                write("你的声望下降了"+chinese_number(cut_rep)+"点。\n");
                CHAR_D->set_char(p_id,"reputation",rep);
                return;
        }
        else
        write("工作是不能随便放弃的呀。\n");
        return; 
}
void start(string arg)
{
        string job_id,job_memo;
        int beg_time,time;
        time=time();
        if( (!arg)||(arg=="") ){
                write("用法: cmd resign <job_id>\n");
                write("例子：cmd resign whisper (放弃策反敌将的工作)\n");
                return;
        }
        if( member_array(arg, forbiden) != -1 ){
                write("你不能放弃这项工作。\n");
                return;
        }
        beg_time = this_body()->query_job(arg,"beg_time");
        if (beg_time==0){
                write("你并没有领过这项工作。\n");
                return;
        }
        job_memo=JOB_D->query_job(arg,"name");
        job_memo1=job_memo;
        job_id=arg;
        if ((time-beg_time)/60<8){
                write("你刚刚才接受工作，至少先试试再考虑放弃吧。\n");
                return;
        } else {
                write("你决定了要放弃"HIY""+job_memo+
""NOR"这项工作吗？（将会有一定损失）\n确定请输入yes，任意键回车后退出。\n");
                this_body()->modal_push((: confirm_resign,arg:),"",0,0);
        }
}
