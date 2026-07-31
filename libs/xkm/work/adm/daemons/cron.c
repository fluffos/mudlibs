//adm/daemons/cron.c

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>

void init_cron();
void check_dns();
void autosave();

void create()
{
        seteuid( ROOT_UID );
        init_cron();
}

void init_cron()
{
	mixed *local;
	object *wiz;
	
	local = localtime(time());
	wiz = filter_array(children(USER_OB), (: userp($1) && wizardp($1) :));

	if (!((local[1])%10))
	{       // 检测邮件服务器IP地址。	        
                message("system", HIR"\n【注册精灵】"HIR ":正在检测SMTP服务器IP地址．．．"NOR ,wiz);
	        SMTP_D->update_mail_server_ip();
                message("system", HIR "．．．检测完毕。\n"NOR ,wiz);
	        //message("system", HIR"\n【注册精灵】"RED ":正在处理48小时未登陆确认的玩家．．．",wiz);
	        //SMTP_D->user_no_login();
	        //message("system", GRN "．．．处理完毕。\n" ,wiz);
	} 
	
	if ( !((local[1])%5)) autosave();

        if( !(local[1]%5))
        if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");

        //if ( !(local[1]%15)) 
        //{
        //check_dns();
        //STATUS_D->write_list();
        //}
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
void autosave()
{
	object *user ;
	int i;
	user = filter_array(children(USER_OB),(: userp :));
        message("system", HIR"\n【存档精灵】"HIR ":自动存档．．．"NOR, user);
	for(i=0; i<sizeof(user); i++) 
	user[i]->save();
        message("system", HIR "．．．存档完毕 \n" NOR, user); 
}
