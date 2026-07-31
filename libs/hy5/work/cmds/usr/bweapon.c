
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2,isdest=0;
        object *inv;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
        if( me!=this_player(1) ) return 0;
        //if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
        //        return notify_fail("你只能改变当前使用者的任务。\n");
        //mission = replace_color( mission, 1);
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

 // if (!wizardp(me))
 // 	return notify_fail("没有对玩家开放！\n"); 

        seteuid(getuid());
        filen = "/p/residence/banding/"+me->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");


        if( !arg )
{
	if (!me->is_busy())
{
	        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
if (strlen(wname)==1)
        printf(HIG"序号:"HIR+wname+HIG" 当前绑定装备:"NOR);
else    printf(HIG"序号:"HIR+wname+HIG"当前绑定装备:"NOR);     
         if (newob=load_object(wmin))
        {
        printf(newob->query("name"));
      }
        printf("\n");
        }
}
me->start_busy(1);
                return notify_fail("存取装备指令格式：bweapon <位置1-50> \n");
}


if(!sscanf(arg, "%d %s", arg2, mission2)) 
return notify_fail("指令格式：bangding <1-50> (道具名称)\n");

        if(sscanf(arg, "%d %s", arg2, mission2)) 
{

        if(arg2<=0 || arg2>50)
            return notify_fail("错误的位置设置, 指令格式：bangding <位置1-50> (道具名称)\n");

}


        //j=0;
me->start_busy(3);
        
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                //j=j+1;
                if( wname==arg ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
newob=load_object(wmin);
	if (newob)
	inv = all_inventory(me);
oldob=present(newob->query("id"),me);
if (oldob)
{
		for(i=0; i<sizeof(inv); i++)
if (base_name(inv[i])==wmin)
{
me->set_temp("isnbwp",1);
message_vision(HIG "$N双手一收 一"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIG" 消失在了虚空中。\n" NOR, me);
isdest=1;
//if (inv[i]->query("bowner")==me->query("id"))
//{
	 destruct(inv[i]);
//}
}
}

if (isdest==0)
{
message_vision(HIR "$N双手一展 一"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" 从虚空中出现在$N身上。\n" NOR, me);
me->set_temp("isnbwp",1);
newob=new(wmin);
newob->move(me);
newob->delete("equipped");
newob->set("bowner",me->query("id"));
//newob->set("name",newob->query("equipped"));
newob->set("equipped",0);
}

me->start_busy(3);
//                message_vision("$N在位置"+wname+"取出装备: " + wmin + " 。\n", me, ob);
                        flag = 1;
                        break;
                }
        }
if (flag==0) return notify_fail("错误的装备位置 (此位置无绑定装备) \n");
        
        return 1;
}
        


int help(object me)
{
        write(@HELP
指令格式 : bweapon <位置1-50> 

HELP
        );
        return 1;
}