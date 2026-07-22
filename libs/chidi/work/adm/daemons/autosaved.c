 //#pragma optimize all

#include <ansi.h>
#include <localtime.h>
inherit F_DBASE;
void create()
{
        seteuid(getuid());
        set("name", "存盘精灵");
        set("channel_id", "自动存盘精灵");
        set("id", "autosave");
        CHANNEL_D->do_channel( this_object(), "sys", "自动存盘已经启动。\n");
        remove_call_out("auto_save");
        call_out("auto_save",10);
}

void auto_save()
{
        int i;
        object *ob, link_ob;

        seteuid(getuid());
        ob=users();
        i=sizeof(ob);
        while(i--) {

                if(!environment(ob[i]) )        continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) )  continue;

                link_ob->save();
                ob[i]->save();
                tell_object(ob[i],HIG "【存盘精灵】" HIY " 您的资料已自动存盘了。\n" NOR);
               
                if(ob[i]->query_condition("killer")){
                UPDATE_D->check_user(ob[i]);//更新这个玩家，如果是杀人犯就会派杀手追杀
                CHANNEL_D->do_channel(this_object(),"rumor","据可靠消息，杀人犯"
                +ob[i]->query("name")+"["+ob[i]->query("id")+"]在"
                +environment(ob[i])->query("short")+"一带流窜。\n");}
        }
                 
        CHANNEL_D->do_channel( this_object(), "sys",sprintf("系统自动清除 " + reclaim_objects() + " 个变数。\n"));
        remove_call_out("auto_save");
        call_out("auto_save", 30+random(600));
        return;
}