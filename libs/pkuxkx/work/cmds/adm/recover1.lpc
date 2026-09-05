// Modified by iszt@pkuxkx, 2007-04-16

#include <ansi.h>

int main(object me,string arg)
{
        mapping skills;
        object ob;
        if(!arg||arg=="")
                return notify_fail("你要给谁恢复死亡损失？\n");
        if(!ob=find_player(arg))
                return notify_fail("你要给谁恢复死亡损失？\n");
        skills=ob->query_skills();
        if(mapp(skills))
        {
                string *skname;
                skname=keys(skills);
                for(int i=0;i<sizeof(skills);i++)
								{
												if(intp(skills[skname[i]])) skills[skname[i]]++;
								}
        }
        ob->add("potential", ((int)ob->query("potential")-(int)ob->query("learned_points"))/2);
        ob->add("combat_exp",(int)ob->query("combat_exp")/49);
        ob->save();
        message("vision",HIY+ob->name()+"("+arg+")恢复一次死亡损失！\n"NOR,ob);
        message("vision",HIY+ob->name()+"("+arg+")恢复一次死亡损失！\n"NOR,me);
        log_file("wiz/recover",ob->name()+"恢复一次，时间："+ctime(time())+"\n"+"执行人："+getuid(me)+"\n");
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式：recover1 <使用者姓名>

恢复一次死亡损失。
HELP
        );
        return 1;
}
