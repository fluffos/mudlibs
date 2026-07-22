// ----/cmds/usr/quit.c ----
// rewrite by jzw for scheme  2006/1/27
#include <command.h>
#include <ansi.h>
#define HTTP_D "/adm/daemons/httpd"

inherit F_DBASE;
inherit F_CLEAN_UP;
void create() 
{
        seteuid(getuid());
    set("channel_id", "离线指令");
}
string online_time(int t)
{
    int h, m, s;

        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t ;
        
        return sprintf("本次联线时间%d:%d",m,s);
}

int main(object me, string arg)
{
int exp,online,doing;
    object link_ob;
    string ip_num,msg;
object env;
env = environment(me);


    
if (me->is_busy() && ! me->query("doing")&& !me->query_temp("netdead"))
    if(! me->query_temp("suicide") )
            return notify_fail("上一个动作未完成！\n");
    else{
            CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "终于想通了，放弃自杀了。 :)");
            tell_object( me,MAG "\n\n你决定要放弃自杀，太好了，那下次再来吧！\n\n\n" NOR);
    }
//   if(environment(me)->query("fight_room")) return notify_fail("擂台上不能退出！\n")
// player 利用alias的修改，在擂台练功的bug,所以暂时关闭
    if (me->is_fighting())  return notify_fail("战斗中只能逃跑，不能退出游戏！\n");
    // We might be called on a link_dead player, so check this.
    link_ob = me->query_temp("link_ob");
    if( link_ob ) {
        // Are we possessing in others body ?
        if( link_ob->is_character() ) {
                write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                exec(link_ob, me);
                link_ob->setup();
                return 1;
        }
        if(!living(me) ){
                write("什麽？\n");
                return 0;
        }
       if (me->query("doing"))
        {
                if (! interactive(me))
                        return 1;
                if(me->query_condition("can_yanjiu")||me->query_condition("can_dushu")||me->query("gaisi"))
            return notify_fail("你已经领悟出天书残谱，暂时不能退出游戏！\n");
        if( me->query_temp("junquest_quit"))
            return notify_fail("你正在带兵打仗呢！现在不能退出游戏！\n");
        if( me->query("temp/insert"))
            return notify_fail("你正在交易中！请先取出你的会员卡再退出游戏！\n");
        if( !wizardp(me) ) {
            if ((me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age"))
                return notify_fail("你现在不能退出游戏！\n");
 foreach (object ob in all_inventory(me))
            if(ob && !ob->query_autoload())
                        DROP_CMD->do_drop(me, ob,1);
        }


                write("你暂时离线，人物不退出...\n");
                message("vision", me->name() + "离线了。\n",
                                  environment(me), ({ me }));
                me->save();
               destruct(link_ob);  //要清除掉，否则吃内存，甚至可利用
                                   //计划不断残留无效link_ob严重导致当机
                link_ob = new(LOGIN_OB);
                exec(link_ob, me);
              destruct(link_ob);
                return 1;
        }
        if(me->query_condition("can_yanjiu")||me->query_condition("can_dushu")||me->query("gaisi"))
            return notify_fail("你已经领悟出天书残谱，暂时不能退出游戏！\n");
        if( me->query_temp("junquest_quit"))
            return notify_fail("你正在带兵打仗呢！现在不能退出游戏！\n");
        if( me->query("temp/insert"))
            return notify_fail("你正在交易中！请先取出你的会员卡再退出游戏！\n");
        if( !wizardp(me) ) {
            if ((me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age"))
                return notify_fail("你现在不能退出游戏！\n");
            foreach (object ob in all_inventory(me))
            if(ob && !ob->query_autoload())
                        DROP_CMD->do_drop(me, ob,1);
        }
            online=time()-link_ob->query("online_time");
          link_ob->set("last_on", time());
    link_ob->set("last_on",CHINESE_D->chinese_time(5,ctime(time())));
    link_ob->set("last_on_link",CHINESE_D->chinese_time(5,ctime(time())));
    link_ob->set("last_on_temp",1);
    link_ob->set("last_on_time", time());
    link_ob->set("last_from", query_ip_name(me));
    me->set("quit_time", time());
  //me->set("startroom", base_name(env));
//限制某些特定房间原地连线
    if (env->query("outdoors")=="no_startroom" || env->query("outdoors")=="12gong"|| !env->query("outdoors")){
     me->set("startroom", "d/city/wumiao");}
else{
     me->set("startroom",base_name(env));
}
    link_ob->set("quit_time", time());
    me->set("last_on",CHINESE_D->chinese_time(5,ctime(time())));
    me->set("last_on_link",CHINESE_D->chinese_time(5,ctime(time())));
    link_ob->save();
        exp=me->query("combat_exp")-link_ob->query("combat_exp");
        link_ob->set("combat_exp", me->query("combat_exp"));
        if (wizardp(me) && me->query("env/invisibility") )
            ;
        else
            link_ob->save();
        destruct(link_ob);
    }
    write("欢迎下次再来！\n");
    message("system", me->name() + "离开游戏。\n", environment(me), me);
    ip_num = query_ip_number(me);
    if (!ip_num)
        msg=me->query("name")+"("+me->query("id")+")"+HIR+"断线时间过长"+HIW+",自动离开游戏了。";
    else
    msg=me->query("name")+"("+me->query("id")+")("+query_ip_number(me)+")离开游戏了。";
    msg+=online_time(online);
    if (exp!=0)
        msg+=sprintf("，经验增加"+HIR+"%d"+NOR+WHT+"点。",exp);
    else
        msg+="。";
    CHANNEL_D->do_channel(this_object(), "sys",msg);

    reclaim_objects();
    me->save();
    destruct(me);
//  HTTP_D->make_who();
    return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : quit
当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}

