#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int i,total;
        string dest, reason;
        object ob,*inv;
        
        if( me != this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s because %s", dest, reason) != 2 )
                return notify_fail("指令格式 : warn <某人> because <原因>\n");

        ob = find_player(dest);
     
        if( !ob ) return notify_fail("咦... 有这个人吗?\n");
        if( wizardp(ob) ) return notify_fail("此命令只对玩家有效\n");
        if( userp(ob) && (!ob->query_temp("marks/warn1")) )
        {
                log_file("WARN_PLAYER", sprintf("[%s] %s warn %s because %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), reason));
                ob->set_temp("marks/warn1",1);
                shout( HIM "【警告】"+ob->name()+"由于违反玩家规则中有关" + reason + "的规定被首次警告。\n" NOR);
                ob->set("balance",(int)(ob->query("balance")*2/3));
                write( HIM "【警告】"+ob->name()+"由于违反玩家规则中有关" + reason + "的规定被首次警告。\n" NOR);    
                tell_object(ob,"巫师协会现在对你进行第一次警告。\n");
                tell_object(me, "你对"+(string)ob->query("name")+"开始首次警告.\n");
                tell_object(ob,"请仔细阅读help rules。\n");
                tell_object(ob,"你违反了玩家规则中有关" + reason + "的规定\n");
       
                return 1;
        }
        if(userp(ob) && ob->query_temp("marks/warn1"))
        {
                log_file("WARN_PLAYER", sprintf("[%s] %s warn %s because %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), reason));

                tell_object(ob,"第二次警告，巫师协会决定对实行惩罚\n");
                tell_object(me, "你对"+(string)ob->query("name")+"开始惩罚.\n");
                tell_object(ob,"请仔细阅读help rules。\n");
                tell_object(ob,"你违反了玩家规则中有关" + reason + "的规定\n");
                tell_room(environment(ob),"天空中一个警卫伸出了手，把"+
                        (string)ob->query("name")+"抓了起来, 放在惩罚室里。\n", ob);
                tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
                tell_object(ob,"警卫对你搜了搜身。\n");
                shout( HIM "【惩罚】"+ob->name()+"由于违反玩家规则中有关" + reason + "的规定被再次警告，并进行惩罚。\n" NOR);
                write( HIM "【惩罚】"+ob->name()+"由于违反玩家规则中有关" + reason + "的规定被再次警告，并进行惩罚。\n" NOR);
   
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("id")!="marrycard")
                                destruct(inv[i]);
                }
                ob->move("/d/wizard/punish_room");
  
                return 1;
        }
}

int help(object me)
{
        write(@HELP
指令格式 : warn <某人> becuase <原因>

此指令可让你警告违反玩家规则的人。
首次balance 减为三分之二.第二次同punish。

相关指令 : punish
HELP
        );
        return 1;
}

