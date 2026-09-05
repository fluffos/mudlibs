//mixin Zine Nov 11 2010
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIW"密信"NOR , ({"lin's mixin","letter", "xin"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("value", 0);
    set("long","这是一张林镇南给你的密信，需要用特殊的药水才能显形(xian)。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
  }
  setup();
  call_out("dest",900);
  call_out("tixing",180);
}

int tixing()
{
    object ob=this_object();
    if (environment(ob))
    {
        tell_object(environment(ob),BLINK HIC"你还没有去追回林镇南的财物呢。\n"NOR);
    }
    remove_call_out("tixing");
    call_out("tixing",60);
    return 1;
}

int dest()
{
	if (this_object())
    {
	    destruct(this_object());
    }
	return 1;
}


void init()
{
   int i,count=0;
   object* all=all_inventory(environment());
   add_action("do_xian","xian");
   add_action("do_dig","zhao");
   add_action("do_dig","zhaoxun");
   for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="lin's mixin")
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    
    return;
}

int do_xian()
{
    object me=this_player();
    object ob=this_object();
    object where;
    string fullplace;
    string* info;
    
    if (!present(ob,me))//防止看地上别人的图
    {
        return 0;
    }
    
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你使用了各种法子，却不能让信上的字显现出来。\n");
    }

		        
    if (ob->query_temp("xinread"))
    {
        tell_object(me,"信上的字只能显现一次。\n");//防止刷antirobot刷新地图
        return 1;
    }
    else
    {	    
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               TASK_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd"||
               TASK_D->place_belong(where)==me->query_temp("密信区域"))
        {
          where = TASK_D->random_place();
        }	

        if(!objectp(where) || base_name(where) == "/adm/daemons/taskd")
        {
	        tell_object(me,"你按照林镇南的指示，信上的字却没有显现，再试试吧。\n");
	        return 1;        	
        }
        ob->set("where",base_name(where));
        ob->set("location",TASK_D->place_belong(where));
        me->set_temp("密信区域",TASK_D->place_belong(where));
        ob->set("room",where->query("short"));
        fullplace=TASK_D->place_belong(where)+where->query("short");
                
        write(HIW"你按照林镇南的指示，打开迷信……原来要你到以下地方找(zhao/zhaoxun)到潜逃的伙计并要(yao)回其席卷的财物！\n"NOR);        
        				       	
        ANTIROBOT_D->mxpantirobot_ex(me,fullplace);        
                
        ob->set_temp("xinread",1);
        return 1;
    }
}

int do_dig()
{
    object me=this_player();
    object ob=this_object();
    object room=environment(me);
    object huoji;
    ob->set("currentroom",room->query("short"));
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if(query("owner") != me->query("id"))
    {
    	return notify_fail(HIC"你扯开嗓子，开始大喊：小王八蛋，你给我滚出来。\n"NOR);
    }
    
    
    if (TASK_D->place_belong(environment(me))==ob->query("location"))
    {
        ob->set("correct",1);
    }
    if (ob->query("correct") && ob->query("currentroom")==ob->query("room"))
    {
            huoji=new("/d/fuzhou/npc/huaihuoji");
            if (huoji)
            {
                huoji->set("owner",me->query("id"));
                ANTIROBOT_D->same_as_fullme(me);
                me->delete_temp("密信区域");
                me->delete("hbisrobot");
                huoji->move(environment(me));
                message_vision("一个伙计挖着鼻屎走了出来，道：你找我啥事？\n",me);
                destruct(this_object());
                return 1;
            }
            else
            {
                tell_object(me,HIC"你扯开嗓子，开始大喊：小王八蛋，你给我滚出来。\n"NOR);
                return 1;
            }
    }
    if (base_name(environment(me))!=ob->query("where"))//错误地点
    {
        tell_object(me,HIC"你扯开嗓子，开始大喊：小王八蛋，你给我滚出来。\n"NOR);
        me->add_busy(1+random(2));
        return 1;
    }
    else
    {
        if (random(100)>60)//正确的地点也可能给假信息。
        {
            tell_object(me,HIC"你扯开嗓子，开始大喊：小王八蛋，你给我滚出来。\n"NOR);
            me->add_busy(random(2));
            return 1;
        }
        else  
        {
            huoji=new("/d/fuzhou/npc/huaihuoji");
            if (huoji)
            {
                huoji->set("owner",me->query("id"));
                ANTIROBOT_D->same_as_fullme(me);
                huoji->move(environment(me));
                message_vision("一个伙计挖着鼻屎走了出来，道：你找我啥事？\n",me);
                destruct(this_object());
                return 1;
            }
            else
            {
                tell_object(me,HIC"你扯开嗓子，开始大喊：小王八蛋，你给我滚出来。\n"NOR);
                return 1;
            }
        }
    }
    
}