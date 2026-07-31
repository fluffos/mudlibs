// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_valid_create(string skillname);
int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic;
string arg2,arg3,arg4,arg5;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0;
                string mission, wname, wmin, file,mission2;
        string *wmission,pfm,fz1,fz2,fz3;
        
        object ob;
        
        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !arg )
                return notify_fail("指令格式：selfpf <武功> <种类> <分类> <描述>\n");



if(!sscanf(arg, "%s %s %s %s", arg2, arg3,arg4,arg5)) 
return notify_fail("指令格式：selfpf <武功> <种类> <分类> <描述>\n");

        if(check_valid_create(arg2)==0)
                return notify_fail("这不是你创建的功夫呀？\n");


if(CHINESE_D->check_length(arg5) > 160)
{
return notify_fail("描述太长!\n");
}

if(CHINESE_D->check_control(arg5))
{
return notify_fail("描述不正确!\n");
}

if (arg3!="dan" && arg3!="hun" && arg3!="lian")
return notify_fail("种类不正确! 种类为dan hun lian  三种\n");

if (arg4!="招名" && arg4!="出招" && arg4!="中招" && arg4!="未中")
return notify_fail("分类不正确! 分类为招名 出招 中招 未中 四种\n");

if((int)me->query("combat_exp") < 5000000)
       return notify_fail("你的经验值还不够。\n");

if (arg4=="招名")
me->add("combat_exp",-2000000);


        seteuid(getuid());
        filen = "/p/skill/"+arg2+arg3;
        if (!read_file(filen))  write_file(filen, "招名 无\n出招 无\n中招 无\n未中 无", 1);
        wmission = explode(read_file(filen), "\n");
mission="";
for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wmin,wname)!=2 ) continue;
        if (wmin=="招名")        pfm=wname;
        if (wmin=="出招")        fz1=wname;
        if (wmin=="中招")        fz2=wname;
        if (wmin=="未中")        fz3=wname;

if (wmin==arg4) mission+=wmin+" "+arg5+"\n";
else mission+=wmin+" "+wname+"\n";
        }

      write_file(filen, mission, 1);
      //write_file(filen, "", 1);  
        if (arg4=="招名")
        message_vision("你经过苦思冥想 终于创建了一门绝学\n"+mission+"成功！\n", me, ob);
		tell_object (me,mission);


return 1;                   
//if (1==1)                
         //return notify_fail("这"+pfm+"不"+fz1+"是"+fz2+"你"+arg2+"创"+check_valid_create(arg2)+"建"+filen+"的"+fz3+"功夫呀？\n");       
}

int check_valid_create(string skillname)
{
string file,*list,playername;
object me;

me=this_player();
file=read_file(SKILL_D(skillname+".c"));
if(!file) 
     return 0;
list = explode(file, "\n");
playername=geteuid(me);

if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
           return 0;

return 1;
}


int help(object me)
{
        write(@TEXT
指令格式：selfpf <种类> <分类> <描述>

这个指令让你练习某个自己创建的技能的绝招 每创建一招或修改招名，需要消耗玩家2M经验
武功为你自创武功的ID
种类为dan hun lian  三种 dan(单招) hun (混合) lian(连招)
分类为招名 出招 中招 未中 四种
描述中不能出现控制符，不然将删除!
描述中 你 与 小鱼儿 代表你与敌人的名称
例如:你纵身一跃，一招「金光泻地」对准小鱼儿斜斜刺出一剑
例如：selfpf mytest-unarmed dan 招名 第一招
      selfpf mytest-unarmed dan 出招 你纵身一跃，一招「金光泻地」对准小鱼儿斜斜刺出一剑

TEXT
        );
        return 1;
}

