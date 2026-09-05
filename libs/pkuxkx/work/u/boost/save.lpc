// save.c

#include <ansi.h>
inherit F_CLEAN_UP;

// 将检查移至 /feature/save.c中，这里只能检查主动save

////既然修改不了mudos，那么只能在保存前后对比修改时间了， by boost
//
//int check_save(object ob)       
//{
//    int last_modify_time, ret;
//    string file = ob->query_save_file();
//    mixed s = stat(file+ __SAVE_EXTENSION__);
//    if (sizeof(s) == 0)
//    {
//        write(HIR"原始文件不存在：" + file + " 请立即联系wiz，并保留当前日志及操作\n"NOR);
//        ob->force_me("backup");
//        //              return 0;
//    }
//
//    ret = ob->save();
//
//    s = stat(file+ __SAVE_EXTENSION__);
//    if (sizeof(s) == 0)
//    {
//        write(HIR"保存失败，档案丢失！ " + file + " 请立即联系wiz，并保留当前日志及操作\n"NOR);
//        ob->force_me("backup");
//        return 0;
//    }
//    last_modify_time = s[1];
//
//    if ((last_modify_time == s[1]) && (last_modify_time != time()))
//    {
//        write(HIR"保存失败，档案无法写入！ " + file + " 请立即联系wiz，并保留当前日志及操作\n"NOR);
//        ob->force_me("backup");
//        return 0;
//    }
//    return ret;
//}

int main(object me, string arg)
{
    object link_ob,room;
    int agediff,expdiff,timediff;
    string str;
    room=environment(me);

    seteuid(getuid());
    if(time()-me->query("last_save_time")<300 && !wizardp(me))
        return notify_fail("请不要过于频繁的存储。\n");
    if( !objectp(link_ob = me->query_temp("link_ob")) )
        return notify_fail("你不是经由正常连线进入，不能储存。\n");

    if ( ! me->query("learn_xiake_gf") )
    {
        if( (room->query("selfcreate")&&me->query("id")==room->query("host")) || !room->query("selfcreate") ) //表明是自创山庄，只允许主人savestart
        {
            if( room->query("valid_startroom") )
            {
                me->set("startroom", base_name(environment(me)));
                write("当你下次连线进来时，会从这里开始。\n");
            }
        }
    }

    "/adm/daemons/savetotxtd"->savetotxt(me);
    if( (int)link_ob->save() && (int)me->save() ) {
//    if( check_save(link_ob) && check_save(me) ) {    //暂时替代一下看看效果

        write("档案储存完毕。\n");
        me->set("last_save_time",time());
        return 1;
    } else {
        write("储存失败。\n");
        return 0;
    }
}

int help(object me)
{
    write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
        );
    return 1;
}
