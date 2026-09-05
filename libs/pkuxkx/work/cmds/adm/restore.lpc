// restore.c 
// Modified by Whuan@pkuxkx, 2008-9-17, to restore the data of player
// cp /data/backup/w/whuan.o /data/user/w/whuan.o

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string src,dst; //src原档案在/data/backup下面,dst目标档案在/data/userxia
        string str;
        if (!arg)
        	      return notify_fail("你想恢复谁的档案？\n");
        src = "/data/backup/"+arg[0..0]+"/"+arg+".o";
        dst = "/data/user/"  +arg[0..0]+"/"+arg+".o";
        if( file_size(src) == -1 )
                return notify_fail("不存在文件"+src+"，"+arg+"并没有备份档案。\n");	
        if( cp(src, dst) )

        {
                str = me->query("name") + "(" + me->query("id") + ")于"+ctime(time())+"恢复"+arg+"的档案。 \n";
                write_file("/log/wiz/restore", str); 
                write("原档案："+src+"\n");
                write("目标档案："+dst+"\n");
                write("恢复成功！\n");
                
        }
        else
                write("你没有足够的读写权利。\n");
        return 1;       
}
int help(object me)
{
  write(@HELP
指令格式 : restore <玩家id>
 
此指令可让你把玩家的档案恢复，适用于掉档但是有备份的玩家。
操作前请慎重，最好能查看一下玩家的过往数据文件！
HELP
    );
    return 1;
}
