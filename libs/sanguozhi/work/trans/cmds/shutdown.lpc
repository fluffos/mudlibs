/* Do not remove the headers from this file! see /USAGE for more info. */

/*
**  /trans/cmds/shutdown - shuts the game down imediately or starts the
**                         shutdown daemon.
**
**  960614 - Alexus adds timed shutdown daemon support
*/
#include <log.h>

inherit CMD;

protected void do_shutdown(string s)
{
    if (!check_privilege(1)) 	//"Admin:system"
	{
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf("do_shutdown() failed due to insufficient privilege (possibly due to being called directly) at %s\n", ctime(time())));
        return;
    }
    
    LOG_D->log(LOG_SHUTDOWN,
      sprintf("SHUTDOWN executed at %s [%s]\n",
        ctime(time()), s));

    foreach (object ob in users())
        catch(ob->quit());
 
    unguarded(1, (: shutdown :));
}

nomask void count_down(int num, string s) {
    string time;
    int interval;
    if(!num)
    {
        tell(users(), "系统核心告诉你：系统立刻 ＳＨＵＴ ＤＯＷＮ！\n");
        do_shutdown(s);
        return;
    }
    if (num >= 60) {
    	time = CHINESE_D->chinese_number(num/60) + "分钟";
    	if (num == 60) interval = 30;
    	else interval = 60;
    }
    else {
    	time = CHINESE_D->chinese_number(num) + "秒钟";
    	if (num > 10) interval = 10;
    	else interval = 1;
    }
    CHANNEL_D->deliver_tell("gossip","管恪",
       "草民夜观天象，帝星大异，宇间时显凶险之兆，天地必在" +
       time + "后陷落，叹歙，悲歙。");
    
    call_out("count_down", interval, num - interval, s);
}

private void main(mixed args, mapping flags)
{
    int num;
    string s;
     
    if ( !check_privilege(1) )	//原来是"Admin:system"
    {
        outf("你以为你是谁呀？你不够资格！\n");
        return;
    }

    s = implode(args[0], " ");

    // handle cancelation checking first!
    if(flags["c"]) {
        if (remove_call_out("count_down") == -1) {
            write("目前没有 shutdown 的进程在运作中。\n");
            return;
        }
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf( "Shutdown cancelled %s by %s [%s]\n",
                            ctime(time()), this_body()->query_userid(), s));
        tell(users(), "系统核心告诉你：系统 ＳＨＵＴ ＤＯＷＮ 被中止了。\n");
        return;
    }

    // Check to see if a -t # switch was given.  If so, don't shut down,
    // just start the shutdown daemon.
    if(flags["t"]) {
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf("Shutdown started %s by %s [%s]\n",
                           ctime(time()), this_body()->query_userid(), s));
        num = to_int(flags["t"]);
        count_down(num * 60, s);
        write("系统 shutdown 进程开始...\n");
        return;
    }
    LOG_D->log(LOG_SHUTDOWN,
               sprintf("Immediate shutdown requested by %s\n",
                       this_user()->query_userid()));
    tell(users(), "系统核心告诉你：系统立刻 ＳＨＵＴ ＤＯＷＮ！\n");
    do_shutdown(s);
}

