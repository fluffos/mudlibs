//adm/daemons/cron.c

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>

void init_cron();
void check_dns();

void create()
{
        seteuid( ROOT_UID );
        init_cron();
}

void init_cron()
{
        mixed *local;   
        
        local = localtime(time());

        if (!((local[1])%20))
        {
        message("system",HIR"【电子邮件精灵】"HIW"正在检测SMTP服务器IP地址．．．" NOR,users() );
        SMTP_D->update_mail_server_ip();
        message("system",HIW"．．．检测完毕。\n\n" NOR,users() );
        message("system",HIR"【电子邮件精灵】"HIW"正在处理48小时未登陆确认的玩家．．．" NOR,users() );
        SMTP_D->user_no_login();
        message("system",HIW"．．．处理完毕。\n\n" NOR,users() );
        } // 检测邮件服务器IP地址。

        if( !(local[1]%5)) 
        if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");

        if ( !(local[1]%15)) 
        {
        check_dns();
        //STATUS_D->write_list();
        }
        call_out("init_cron", 60);
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

