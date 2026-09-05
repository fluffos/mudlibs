#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob,ob1;
        mapping my;
        string owner,str,quest_type,quest_type1,exp,pot;
		int from_num,i;
		mapping elist,plist;
	    seteuid(getuid(me));
        if(!arg)
                ob = me;
        else
        {
          ob = present(arg, environment(me));
          if (!ob) ob = find_player(arg);
          if (!ob) ob = find_living(arg);
          if (!ob || !me->visible(ob))
          return notify_fail("你要察看谁的状态？\n");
          else
          {
             owner=ob->query("owner_id");
             if(owner) ob1=find_player(owner);
                        }
        }

        if (!ob->query("exp")) 
        {
        my = ob->query_entire_dbase();
        printf("--------------------------------------------------------------------\n\n");
        printf("  玩家：%s（%s）\n\n",my["name"],my["id"]);
        printf(" 【 经验 】：%10d 【 潜能 】：%10d \n",my["combat_exp"],my["potential"]);
        printf("--------------------------------------------------------------------\n\n");
                }
        else {
        my = ob->query_entire_dbase();
		printf("--------------------------------------------------------------------\n\n");
		printf("  玩家：%s（%s）\n\n",my["name"],my["id"]);
		printf(" 【 经验 】：%10d 【 潜能 】：%10d \n",my["combat_exp"],my["potential"]);
		if (sizeof(ob->query("exp")))
	     {
		elist  =  ob->query("exp");
		plist  =  ob->query("pot");
		}
        foreach(str in keys(elist))
        //tell_object(me, sprintf("%s\t== %O\n", str, elist[str]));
		printf(" 【 "+to_chinese(str)+" 】：%10d 【 "+to_chinese(str)+" 】：%10d \n",elist[str],plist[str]);
        printf("--------------------------------------------------------------------\n\n");
        }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : from
           from <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的获得经验的数值。

see also : score
HELP
    );
    return 1;
}
