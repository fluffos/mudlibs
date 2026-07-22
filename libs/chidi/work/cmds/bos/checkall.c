// ----/cmds/arch/checkall.c ----
inherit F_CLEAN_UP;
int help(object me);

int busy;

int main(object me, string arg)
{    
    if (busy)
                return notify_fail(HIR "整理玩家数据正在进行！\n" NOR);
        message("system", RED"\n 整理玩家储存档，请稍候....\n" NOR, users());
    write("处理中：\n");
    rm("/log/bad_data");
    rm("/log/checkweapon");    
    rm("/log/checkuser");
    rm("/log/checkskill");
    rm("/log/checkpotcard");    

   
    busy=1;
        call_out("checking",2);
        return 1;
}
int checking(int i)
{
        int j;
        string *dir, *ppls, *puls, name,arg;
        object ob,obj;
        
        seteuid(getuid());
        dir = get_dir(DATA_DIR + "login/");
        if (!i){
            i=0;
        }
        ob=new("/clone/misc/player");
                if ( i<sizeof(dir) ){
                reset_eval_cost();
                arg=dir[i];
                write("正在整理 -= "+arg+" =-\n");
                i++;
                ppls = get_dir(DATA_DIR + "login/" + arg + "/");
                puls = get_dir(DATA_DIR + "user/" + arg + "/");
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                          if( (string)SECURITY_D->get_status(name)!="(player)" ){
                              write(BOLD+"排除巫师"+name+"\n"+NOR);
                                  continue;
                                }
                          if (!ob->new_object(name)){
                                  log_file("bad_data",name+"\tis bad.\n");
                                  continue;
                                }                   
                          if (ob->query("id")!=name)
                                  log_file("bad_data",name+"\tisn't\t"+ob->query("id")+"\n");                                                                  

                          if (ob->query("weapon/lv",1)>20)
                                  log_file("checkweapon",sprintf("%10s(%s) 第一把武器:%d级,上线时间:%d天\n",
                                            ob->name(),name,ob->query("weapon/lv",1)*10,ob->query("mud_age")/86400));

                          if (ob->query("weapon2/lv",1)>20) 
                                  log_file("checkweapon",sprintf("%10s(%s) 第二把武器:%d级,上线时间:%d天\n",
                                            ob->name(),name,ob->query("weapon2/lv",1)*10,ob->query("mud_age")/86400));

                          if (ob->query("max_neili")>2000000||ob->query("max_jingli")>2000000 )
                                  log_file("checkusers",sprintf("%10s(%s) 内力:%10d,精力:%10d,上线时间:%d天\n",
                                            ob->name(),name,ob->query("max_neili"),ob->query("max_jingli"),ob->query("mud_age")/86400));

                          if (ob->query_skill("kuihua-xinfa",1)>10000)
                                  log_file("checkskill",sprintf("%10s(%s) 葵花心法:%d级,上线时间:%d天\n",
                                            ob->name(),name,ob->query_skill("kuihua-xinfa",1),ob->query("mud_age")/86400));
       
                          if (ob->query("card_potential",1)>100000)
                                  log_file("checkcardpot",sprintf("%10s(%s) 银行卡潜能:%d,上线时间:%d\n",
                                            ob->name(),name,ob->query("card_potential",1),ob->query("mud_age")/86400));                   
                        }
                                }
                destruct(ob);
                call_out("checking",1,i);
                return 1;
        }else{
             message("system", BOLD"\n 整理完毕!\n" NOR, users());
                busy=0;
        }
        return 1;
}
int help(object me)
{
write(@HELP
指令格式：checkall

HELP
        );
    return 1;
}



