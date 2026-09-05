#include <ansi.h>

inherit ROOM;


int valid_leave(object me,string dir)
{
    object* invs;
   

    int i;

	if(dir == "enter")
	{
		if(BIWU_D->taskstarted() != 1)
		{
			if(BIWU_D->getnextcycletimespan() > 0)
			{
				return notify_fail("比武尚未开始，你不能进去，请等待"+chinese_number(BIWU_D->getnextcycletimespan())+"秒。\n");
			}
			else
			{
				return notify_fail("你是怎么混进来的？出去！\n");
			}
		}
		invs = filter_array(deep_inventory(me),(:$1->query("weapon_prop") && $1->query("skill_type") != "throwing":));
		if(sizeof(invs) > 6)
		{
			return notify_fail("朝廷有令，最多带六把武器入场比武！\n");
		}
	}
       
          return ::valid_leave(me,dir);   
}

void init()  
 {  
      object me=this_player();

     add_action("do_leave","leave");

 }

int do_leave(string arg) 
 {
     object me=this_player();
    
            if(BIWU_D->taskstarted() == 1)
                       {
				return notify_fail("胜负未分，生死未判，居然想走？不怕被逐出师门吗？\n");
			}
                        else
			{       
                                tell_object(me,HIB"突然天空之中伸出一只大手抓住你。\n"+NOR);   
                                me->move("/biwu/gate");
                                tell_object(me,HIR"下次再敢乱走就没这么幸运了！\n"+NOR);
				return 1;
			}

 return 1;
 }

int isentryroom()
{
	return 1;
}
