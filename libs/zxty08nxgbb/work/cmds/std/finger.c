// finger.c
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
void create()
{
        seteuid(getuid());
}
mixed query(string arg)
{
    if (arg && arg=="channel_id")  return HIY "监视精灵(Finger)";
    return 0;
}
private void finger_user(object me,mixed ob)
{
    if (!me || !ob) return;
    if (objectp(ob)){
    if (ob==me){
        write( FINGER_D->finger_user(geteuid(ob)) );
        return;
    }
            if (wizardp(ob))
                tell_object(ob,HIY+me->short(1)+"正在查看你的资料。\n"NOR);
            else if (!wizardp(me) ){
               if ( random(10)>6 && me==ob->query_temp("finger_user"))
                tell_object(ob,HIY+me->short(1)+"正在查看你的资料。\n"NOR);
               else
                tell_object(ob,HIY"你不由得打了一个冷战...\n"NOR);
                CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s) <=Finger=> %s(%s)",me->query("name"),me->query("id"),ob->query("name"),ob->query("id")));
                ob->set_temp("finger_user",me);
                me->set_temp("finger_time",time());
            }
        write( FINGER_D->finger_user(geteuid(ob)) );
    }else if (stringp(ob)){
        CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s) <=Finger=> %s",me->query("name"),me->query("id"),ob));
        write( FINGER_D->finger_user(ob) );
    }
}

int main(object me, string arg)
{
    object ob;
    string *msg;

    if( !arg )
        if (wizardp(me)) {
            msg=explode(FINGER_D->finger_all() ,"\n");
            foreach (string mes in msg)
                write(mes+"\n");
            return 1;
        }else return help(me);
   
    if( (int)me->query("jing") < 15 || time()-me->query_temp("finger_time")<5)
            return notify_fail("你的精神无法集中。\n");
    if( !wizardp(me) ){
            me->receive_damage("jing", 15);
    }
    if ( is_chinese(arg) ){
        foreach (ob in users() )
            if (ob->name(1)==arg){
                finger_user(me,ob );
            }
    }else{
        ob=find_player(arg);
        if (!ob)
                finger_user(me,arg );
        else
                finger_user(me,ob );
    }
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : finger <使用者id>
 
这个指令可显示有关某个玩家的连线, 权限等资料.
 
如果玩家在线，也可以使用 finger <使用者中文名>　进行查看。
see also : who
HELP
    );
    return 1;
}

