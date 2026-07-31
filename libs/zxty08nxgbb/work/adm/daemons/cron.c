#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
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
        local = localtime(time());
        if ( !((local[1])%40)) autosave();

        if ( !((local[1])%40))
       if (random(2))TASK_D->init_dynamic_quest();
        else TASK_D->init_dynamic_quest(1);
        call_out("init_cron", 60);  
}

void autosave()
{
 object *user ;
 int i;
        user = users();
         message("system", HIR "\n\n           天涯之碧血江湖task任务系统已经自动更新完毕。\n\n\n"NOR, users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
}

