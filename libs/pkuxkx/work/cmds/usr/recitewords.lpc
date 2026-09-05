//recitewords.c
//By kiden@pkuxkx 帮助大家背单词
//目前支持CET4,CET6和GRE
#include <ansi.h>
int main(object me,string arg)
{
        int max_line_gre=6715;
        int max_line_ct4=4644;
        int max_line_ct6=1287;
        int max_line;
        int i;
        string filetxt;
        string question;
        string type;
        string *qrlist;
        if (arg=="gre" || arg=="GRE"){
        	max_line=max_line_gre;
        	filetxt="/d/wizard/npc/grewords.txt";
        	type="GRE";
          }
        else if (arg=="cet6" || arg=="CET6"){	
        	max_line=max_line_ct6;
        	filetxt="/d/wizard/npc/cet6words.txt";
        	type="CET6";
          }
        else{
        	max_line=max_line_ct4;	
        	filetxt="/d/wizard/npc/cet4words.txt";
        	type="CET4";
          }
        i=random(max_line)+1;
        
        
/*
        if (me->is_busy()) 
                return notify_fail("Take care of yourself first!\n");
*/
        
        if (time()-me->query_temp("recite_time") < 6 && !wizardp(me))
                return notify_fail("Keep the last word in your mind! please try again later!\n");
        
        me->set_temp("recite_time",time());
        question=read_file(filetxt,i,1);
        qrlist=explode(question,"@@@@");
        
        tell_object(me,HIY"Word Type："+type
                +"\n"+HIW"━━━━━━━━━━━\n"+HIR+qrlist[0]
                +"\n"+HIG+qrlist[1]+HIW"━━━━━━━━━━━\n"NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: recitewords <单词类型>
 
帮助玩家背单词。（目前支持gre,cet4和cet6）
亦可直接输入gre，cet4和cet6进行背诵。
 
HELP
        );
        return 1;
}

