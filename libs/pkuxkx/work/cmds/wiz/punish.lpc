#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
     int i;
        string dest, reason;
        object ob,*inv;
        if( me != this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s because %s", dest, reason) != 2 )
                return notify_fail("指 令 格 式 punish <某 人> because <指 令>
\n");

     ob = LOGIN_D->find_body(dest);
     if (!ob) return notify_fail("咦... 有这个人吗?\n");

if(wizardp(ob)) return notify_fail("此命令只对玩家有效\n");
        if( userp(ob) )
                log_file("punishment", sprintf("[%s] %s punish %s because %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), reason));

       tell_room(environment(ob),"天空中一个警卫伸出了手，把"+
        (string)ob->query("name")+"抓了起来, 放在惩罚室里。\n", ob);
        tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
   tell_object(ob,"你违反了玩家规则中的第 “" + reason +"”的规定\n");
tell_object(ob,"警卫对你搜了搜身，没收了你的物品。\n");
   inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++) {
                    if(inv[i]->query("id")!="marrycard"){
                    destruct(inv[i]);
                            }
                         }
 shout( HIM "【惩罚】"+ob->name()+"由于违反玩家规则中的第" +reason+"条规定被实施惩罚。\n" NOR);
 write( HIM "【惩罚】"+ob->name()+"由于违反玩家规则中的第" +reason+"条规定被实施惩罚。\n" NOR);

        ob->move("/d/wizard/punish_room");
        tell_object(me, "你对"+(string)ob->query("name")+"开始惩罚.\n");
        tell_object(ob,"警卫对你说到：违反玩家规则，现在开始接受惩罚。\n");
   
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : punish <某人> becuase <原因>
此指令可让你惩罚违反玩家规则的人。
在一定时间内，不能执行chat,tell,rumor,do,drop等命令。
没收所有的身上的东西。
balance 减少为原来的五分之一.
注意慎用，because 的部分可简写为玩家规则中的第几条。
HELP
    );
    return 1;
}
