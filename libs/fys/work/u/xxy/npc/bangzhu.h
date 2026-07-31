#include <localtime.h>
int check_banghui();
int re_rank();
string check_player();
object ob=this_player(),me=this_object();
int ask_jiaru()
{
  int cla;
  cla=check_banghui();
  switch(cla)     {
       case 1:    
                      {        
              tell_object(ob,"你和"+me->query("name")+"已是同一帮会!\n");
              return 1;
                            }
    case 2:            
                      {
             tell_object(ob,"你要先脱离(tuoli)原来的帮会才能再加入新的帮会!\n");
             return 1;
                    }
    case 0:
            {
         command("say "+RANK_D->query_respect(ob)+"如愿加入本帮,请用(jiaru "+
             me->query("id")+").\n");
         command("yaoqing "+ob->query("id"));
   return 1;
       }
            }
  return;
}
int check_banghui()
{
   string bm_ob,bm_me;
   bm_ob=ob->query("banghui");
   bm_me=me->query("banghui");
 if (bm_ob==bm_me) 
                          return 1;
 if (bm_ob&&bm_ob!=bm_me)
                                     return 2;
 else return 0;
} 
int re_rank()
{
   string oldrank,newrank;
      int cla;
  cla=check_banghui();
 if (cla!=1) 
            return notify_fail("你不是"+me->query("banghui")+"中人.\n");
 newrank=check_player();
 oldrank=ob->query("title");
 if (ob->query("banghui")+newrank==oldrank)
        {     command("say 你的武功这段时间并没多大长进，还想升职?\n");
               return 1;
        }
   command("say 依你的武功看来,可在帮中担当"+newrank+"一职.\n");
   command("chat 自今日起,"+ob->query("name")+"在"+ob->query("banghui")+
"中担任"+newrank+"一职.\n");
   ob->set("title",ob->query("banghui")+newrank);
   tell_object(me,"你被委任为"+ob->query("title")+".\n");
   return 1;
}
int ask_renwu()
{
   mixed *local;
  int t,i;
 string renwu;
i=check_banghui();
if (!i==1)   {       command("say 你我不是同一帮会的吧!\n");     return 1;}
   local = localtime(time()*60);
t=local[4];
 renwu=menpai[t+1];
 command("say 这个月的任务是攻打"+renwu+".\n");
return 1;
} 
