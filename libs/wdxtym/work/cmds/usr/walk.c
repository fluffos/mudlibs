// walk.c

inherit F_CLEAN_UP; 

#include "/d/rw.h"
 
#define PATH_D  "/adm/daemons/pathd.c"

int main(object me, string arg)
{
        mixed a;
        mixed br;
        string str = "",*walks;
        
 /*       if( uptime() < 2100 )
                return notify_fail("系统气喘嘘地叹道：重启不到2100秒，请稍后再试 ....\n");
*/
     //   if(time() - me->query_temp("last_walk") < 10 )
 //               return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");
 	
	if (me->is_ghost())
		return notify_fail("你还是等还了阳再说吧。\n");
 if (me->is_busy())
 return notify_fail("你还是先停下手头里的事情再说吧！\n");
	if( !arg) 
		return notify_fail(INPUTTXT("你想去哪里？输入地名即可,如若你想寻找人物，可直接输入人物姓名，目前只有部分位置库","walk $txt#")+"\n");
//		ZJOBACTS2+ZJMENUF(3,3,8,30)+"最大:enforce max"ZJSEP"取消加力:enforce none\n");

if (where[arg]&&!me->is_busy()||arg=="师傅")
{
string name;
if(arg=="师傅"&&me->query("family/master_name"))
name= where[me->query("family/master_name")];
else
name = where[arg];
me->move(name);
me->start_busy(5);
tell_object(me,"你因为长期赶路，已气喘吁吁，忙乱不已！\n");
return 1;
}
        if( environment(me)->is_chat_room() ) return notify_fail("聊天室内不能使用寻路功能！\n");

        if( sscanf(base_name(environment(me)), "/f/%*s") )
                return notify_fail("副本里禁止使用walk寻路功能 ....\n");

        if( !is_chinese(arg) )
                return notify_fail("指令格式：walk <中文地址>\n");

        me->set_temp("last_walk", time());
        a = PATH_D->search_for_path(me, arg);
        if( !a || a == 1) {
                me->set_temp("last_walk", time()+10);
                write("没有这个地方，或者这个地方离这里超过规定的距离限制。\n");
                return 1;
        }
        write(arg+"路径搜索完成，共"+sizeof(a[1])+"步，路线为：\n");
        for( int i = 0;i < sizeof(a[1]);i++ )
        {
                str    += a[1][i] + ";";
        }
        str = str[0..<2]; 
        write(str+"\n");//输出路线
        br = me->query("env/brief");
        me->set("env/brief", 1);
        walks = explode(str,";");
for(int i = 0;i < sizeof(walks);i++)
{
tell_object(me,ZJFORCECMD(walks[i]));//利用客户端来处理指令，可以达到防止玩家进行机器人或脚本操作等行为。
}
        me->set("env/brief", br);
        write("你已经到达"+arg+"。\n");
       // me->force_me("maphere");
   //    tell_object(me,ZJFORCECMD("maphere -m"));
        return 1;
}

