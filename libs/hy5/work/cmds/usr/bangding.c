
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
       	string info,name,id,filen,infoa,infob,arg3;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2,delid,aid;
        object ob;
        string mission, wname, wmin, file,mission2,wname2;
        string *wmission;
        if( me!=this_player(1) ) return 0;
        //if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
        //        return notify_fail("你只能改变当前使用者的任务。\n");
        //mission = replace_color( mission, 1);
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

  //if (!wizardp(me))
  //	return notify_fail("没有对玩家开放！\n"); 

        if( !arg )
                return notify_fail("指令格式：bangding <位置1-50> (道具名称)\n");


       if( arg=="-a" )
{
 seteuid(getuid());
        filen = "/p/residence/banding/"+me->query("id");

        if (!read_file(filen))  write_file(filen, "", 1);

        
        
        wmission = explode(read_file(filen), "\n");
//wmission = sort_array(wmission, 1);
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname2, wmin)!=2 ) continue;
if (wname2!="-a")
{
if (strlen(wname2)==1)
{
wname2="0"+wname2;
//printf(HIG"修改数据:"HIR+wname2+"\n"NOR);
wmission[i] = sprintf("%s %s\n", wname2, wmin);
       
}
  
}


        }

wmission = sort_array(wmission, 1);

        file="";

        for( file = "", i=0; i<sizeof(wmission); i++)
        {
        	
        	 //printf(HIG"处理数据:"HIR+wmission[i]+"\n"NOR);
         if (wmission[i]!="" && wmission[i]!="\n")
         {
         file += wmission[i] + "\n";
        }        

        }
  write_file(filen, file, 1);
me->start_busy(2);
return notify_fail("整理数据成功! \n");        
}

if (sscanf(arg, "%s %d", arg3, delid))
{
if (arg3="-d" && (delid>0 && delid<=50))
{
 seteuid(getuid());
        filen = "/p/residence/banding/"+me->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");
        
file="";

        for( file = "", i=0; i<sizeof(wmission); i++)
        {
if( wmission[i][0]=='#' || sscanf(wmission[i], "%d %s", aid, wmin)!=2 ) continue;
	
         if (wmission[i]!="" && wmission[i]!="\n")
         {
if (aid!=delid)
{
         file += wmission[i] + "\n";
}
        }        

        }
  write_file(filen, file, 1);
        me->start_busy(2);
        
return notify_fail("删除第"+delid+"行数据成功! \n");        
}
}

if(!sscanf(arg, "%d %s", arg2, mission2)) 
return notify_fail("指令格式：bangding <1-50> (道具名称)\n");

        if(sscanf(arg, "%d %s", arg2, mission2)) 
{

        if(arg2<=0 || arg2>50)
            return notify_fail("错误的位置设置, 指令格式：bangding <位置1-50> (道具名称)\n");

}

        if( !arg || sscanf(arg, "%s %s", arg, mission)!=2 )
                return notify_fail("指令格式：bangding <位置1-50> (道具名称)\n");


        seteuid(getuid());
        filen = "/p/residence/banding/"+me->query("id");
        
        //printf(mission);
        
        oldob=present(mission,me);
        if (!oldob) return notify_fail("你身上没有"+mission+"\n");
        
        if (!oldob->query("systemmake"))  return notify_fail("只有特殊装备可以绑定."+"\n");
        
        name=oldob->query("name");

        if (!read_file(filen))  write_file(filen, "", 1);

        mission=base_name(oldob);
        
        wmission = explode(read_file(filen), "\n");


        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                if( wmin==mission ) {
                //printf(wname);
                //printf(arg);
                return notify_fail("此物已经在位置"+wname+"处绑定."+"\n");
                        break;
                }
        }
        oldob->set("no_get",1);
        oldob->set("no_drop",1);

        //j=0;
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                //j=j+1;
                if( wname==arg ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for( file = "", i=0; i<sizeof(wmission); i++)
        {
         if (wmission[i]!="" && wmission[i]!="\n")
         {
         file += wmission[i] + "\n";
        }        

        }

        if(!flag) write_file(filen, arg + " " + mission + "\n", 0);
        else      write_file(filen, file, 1);
        message_vision("$N在位置"+arg2+"处绑定装备: " + name + " 。\n", me, ob);
        me->start_busy(3);
        return 1;
}
        
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
        write(@HELP
指令格式 : bangding <位置1-50> (道具名称) 
整理排序 : bangding -a
删除绑定 : bangding -d 位置		

HELP
        );
        return 1;
}