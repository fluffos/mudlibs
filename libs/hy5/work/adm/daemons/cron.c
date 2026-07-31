// TIEYU@FY3
// This is a daemon that calls itself every minte. it checks
// all major daemons to make sure that they are up and running.

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void check_dns();
void check_pets();
void check_whonature();
void create()
{
        seteuid( ROOT_UID );
        init_cron();
}
int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}
int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}
void init_cron()
{
        mixed *local;
//Edit by cloth
//___________________________________________________________________________________
//        int hour,min,sec,i,j;
//        string a,b,c,d,e,*dir,*ppls;
//        sscanf(ctime(time()), "%s %s %s %d:%d:%d %s",a,b,c,hour,min,sec,e);
//        dir = get_dir(DATA_DIR + "login/");
//        if(hour==24 && min==0 && sec==0)
//        {
//        for(i=0; i<sizeof(dir); i++)
//        {
//          ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
//          for(j=0; j<sizeof(ppls); j++)
//          {
//           cp(DATA_DIR+"login/"+dir[i]+"/"+ppls[j],"/u/cloth/login");
//           cp(DATA_DIR+"user/"+dir[i]+"/"+ppls[j],"/u/cloth/user");
//          } 
//        }
//        }
//___________________________________________________________________________________
        local = localtime(time());
        if ( !random(120)) 
        TASK_D->init_dynamic_quest();
//        if ( !((local[1])%1)) autosave();
        if ( !((local[1])%45)) autosave();
        

//How long the system will refresh all tasks. Added by FY@SH-Morrison
//--------------------------------------------------------------------
 if ( !((local[1])%260))
      {
        message("system",
                HIW     "\t\t【海洋V-星月传奇】将在五分钟后重新分布task！\n\n" NOR,
                users() );
        call_out("countdown", 60, 5);
   }
//--------------------------------------------------------------------
//修改以上第一行中百分号后的数字(现在设的60代表1小时)就可以修改task重新分布的时间间间隔了。
//above is add by Morrison

// Check pets that's lost heartbeat
        if( !(local[1]%5)) 
       if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");
        check_pets();
// if dns_master not working, every 15 mins re-initalize it
        if ( !(local[1]%15)) 
        {
        check_dns();
// if WHO_D,NATURE_D dies restart them
        check_whonature();
        STATUS_D->write_list();
        }
        call_out("init_cron", 60);//zzz modify 20 to 60 
}

private void countdown(int min)
{
	object *allp = users();
	object present;
        object *ob_list,ob;
        int i;
        min--;
        if( min ) {
                message("system",
                        HIR     "\t\t【海洋V-星月传奇】将在" + chinese_number(min) + "分钟后重新分布task！\n\n"NOR,                  users() );
                call_out("countdown", 60, min);
        } else {
            message("system",HIR "重新分布所有使命。。。" NOR,users());
//为解决萧秋水传奇问题而加 
           ob_list = children("/quest/shenshu/npc/man2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
		message_vision("$N笑了笑说：东西已经到手，任务完成，撤了！\n",ob_list[i]);
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/npc/man");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
		message_vision("$N笑了笑说：东西已经到手，任务完成，撤了！\n",ob_list[i]);
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/gbook");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/jinbook");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/gbook1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/gbook2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/jbook1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/jbook2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/shang");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/xia");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                      ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                   ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book5");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book6");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book7");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book8");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book9");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book10");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book11");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book12");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book13");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book14");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book15");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book16");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book17");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book18");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book19");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book20");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book21");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book22");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book23");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book24");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book25");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book26");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book27");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book28");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book29");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book30");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book31");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book32");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book33");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book34");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book35");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book36");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book37");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book38");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book39");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book40");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book41");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book42");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/clone/misc/findbook");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
//结束

    ob_list = livings();
    ob_list = sort_array(livings(), "sort_user", this_object());
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        
if(!ob->query_temp("nhdjoblb")) continue;
if(!ob->query_temp("nhdjobtg")) continue;
ob->delete_temp("nhdjoblb");
ob->delete_temp("nhdjobtg");
ob->delete_temp("nhdjobsc");
ob->delete_temp("nhdjoben");
    }   
write_file("/log/taskjob", "\n", 1);    
            TASK_D->init_dynamic_quest(1);
            message("system",HIG "。。。所有使命分布完毕\n" NOR,users());
        }
}

void check_dns()
{
        mapping mud_list;
        mixed *muds;
        object dns;

        if(!dns = find_object(DNS_MASTER))
        // dns not started, not our problem
        return;
        mud_list = (mapping) DNS_MASTER->query_muds();
        muds=keys(mud_list);
        if(sizeof(muds)<= 1)
        { destruct(dns);
        call_other(DNS_MASTER,"???");
        }
        return;
}

void check_whonature()
{
        mixed *info;
        int i;
        object ob;
        int who=0, nature=0;
        info = call_out_info();
        for(i=0; i<sizeof(info); i++)
        {
        if( "/"+sprintf("%O",info[i][0]) == WHO_D ) who =1;
        if( "/"+sprintf("%O",info[i][0]) == NATURE_D ) nature=1;
        }
        if(!who)
        {
                if(ob=find_object(WHO_D)) destruct(ob);
                call_other(WHO_D,"???"); 
        }
        if(!nature)
        {
                if(ob=find_object(NATURE_D)) destruct(ob);
                call_other(NATURE_D,"???");
        }
        return;
}

void check_pets()
{
int i;
object ob,*ob_list;
ob_list=children("/clone/npc/pet");
for(i=0; i<sizeof(ob_list); i++) {
if( !ob = environment(ob_list[i]) ) continue;
ob->heal_up();
                }

return;
}

void autosave()
{
 object *ob;
object *n;
 object *user ;
 int i,z;
 n = filter_array( livings(),
(: $1->is_character() && !userp($1) && !query_heart_beat($1) && clonep($1):) );
         user = users();
        message("system", HIR "\n 全部玩家自动存档．．．", users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
	message("system", HIG "．．．存档完毕 \n" NOR, users()); 
}