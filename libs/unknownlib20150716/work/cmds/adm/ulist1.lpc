// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// user list
// by canoe 2001.08.24

int help(object me);
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob;
        int i,flag;
        string str;
        if(arg && sscanf(arg,"number %s",str)==1)
        {
        ob=users();
        i = sizeof(ob);
        flag=1;
        while (i--)
        	{
        	if (str==file_name(ob[i]))
        		{
        		write(sprintf("用户文件名为[1;33m%s[m的玩家是[1;33m%s [m。 \n",
        		file_name(ob[i]),ob[i]->query("id")));
        		flag=0;
        		}
        	}
       if(flag) return notify_fail("对不起，查无此人。\n");
       return 1; 
	}
	else if(arg && sscanf(arg,"id %s",str)==1)
       {
     	if(!find_player(str))
       		return notify_fail("对不起，查无此人。\n");
      	write(sprintf("玩家[1;33m%s[m的用户文件名是[1;33m%s[m。\n",str,file_name(find_player(str))));
        return 1; 
	}
	else return help(me); 
}

int help(object me)
{
write(@HELP
[1;37m  
作    用：列出玩家的user number。
[1;33m 
指令格式：ulist1 number <玩家文件名>
         ulist1 id     <玩家id>
[1;37m        
例如：玩家canoe 的user number 为/obj/user#1
[1;33m 
 1、  用ulist1 number /obj/user#1 ,则显示 
      用户文件名为/obj/user#1的玩家是canoe。
      
 2、  用ulist1 id canoe ,则显示 
      玩家canoe用户文件名为/obj/user#1。    
[0;1;37;34m       
对付出错信息比较有用。
[m
HELP
    );
    return 1;
}
