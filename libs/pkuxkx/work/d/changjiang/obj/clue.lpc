//newmap Zine Nov 11 2010
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( WHT"奇怪的线索"NOR , ({"qiguai xiansuo","xiansuo","clue"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("value", 0);
    set("long","这是一张你自己画下的地图，似乎藏着什么东西，地图深奥难懂，你可以研究(yanjiu)一下。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
    set("correct",0);
  }
  setup();
}

void init()
{
   int i,count=0;
   object* all=all_inventory(environment());
   add_action("do_yanjiu","yanjiu");
   add_action("do_zhao","zhao");
   add_action("do_zhao","xunzhao");
   for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="qiguai xiansuo")
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

int do_yanjiu(string arg)
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
    if (!arg || (arg!="qiguai xiansuo" && arg!="xiansuo" && arg!="clue"))
    {
        tell_object(me,"你要研究什么？\n");
        return 1;
    }
    
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你对着这张地图看又了看，什么也看不出来。\n");
    }

		        
    if (ob->query_temp("mapread"))
    {
        tell_object(me,"你已经查看过了，没看清楚吗？\n");//防止刷antirobot刷新地图
        return 1;
    }
    else
    {	    	
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               TASK_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where = TASK_D->random_place();
        }
        if(!objectp(where) || base_name(where) == "/adm/daemons/taskd")
        {
	        tell_object(me,"你看了又看，还是看不清楚地图。再试试吧。\n");
	        return 1;        	
        }
        ob->set("where",base_name(where));
        ob->set("location",TASK_D->place_belong(where));
        ob->set("room",where->query("short"));
        fullplace=TASK_D->place_belong(where)+where->query("short");
                
        write(HIW"你打开了自己画的地图，仔细查看……在以下位置打了个宝物的标记。\n"NOR);        
        				       	
        ANTIROBOT_D->mxpantirobot_ex(me,fullplace);        
        write(HIW"到了所在地找(zhao/xunzhao)一下也许能发现什么。\n"NOR);        
        ob->set_temp("mapread",1);
        return 1;
    }
}
string get_author()
{
	object * ob,pl;
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	for (int i=0;i<sizeof(ob);i++)
	{
		if (ob[i]->query("combat_exp")<50000000)
		{
			ob-=({ob[i]});
		}
	}
	if (!sizeof(ob))
	{
		return "";
	}
	pl=ob[random(sizeof(ob))];
	if (pl->query("family/family_name"))
	{
		return pl->query("family/family_name")+"高手"+pl->query("name");
	}
	else
	{
		return "一代高手"+pl->query("name");
	}
}
int do_zhao()
{
    object me=this_player();
    object ob=this_object();
    object room=environment(me);
    object dan;
    int reward,preward,rreward,lvl,index;
    string msg,author;
    ob->set("currentroom",room->query("short"));
    
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你对着地图看又了看，什么也看不出来。\n");
    }
    if (ob->query("questfinish"))//拿过奖励了
    {
        tell_object(me,"这张图已经没有任何价值了！\n");
        return 1;
    }
    if (base_name(environment(me))!=ob->query("where"))//错误地点
    {
        tell_object(me,"你反复对照线索，发现这里的地形很像线索上的画的图形，仔细寻找起来！\n");
        me->add_busy(1+random(1));
        return 1;
    }
    else
    {
        if (random(100)>80)//正确的地点也可能给假信息。
        {
            tell_object(me,"你反复对照线索，发现这里的地形很像线索上的画的图形，仔细寻找起来！\n");
            me->add_busy(random(2));
            return 1;
        }
        else  
        {
            dan=new("/d/changjiang/obj/dan");
            dan->move(me);
			author=get_author();
			if (author!="")
			{
				author+="所著的";
				dan->set("author",author);
			}
            tell_object(me,"你在这里找到了一本"+dan->query("name")+"。\n");
			CHANNEL_D->do_channel(this_object(), "jh", HIW + me->query("name") +HIW "机缘巧合，意外获得了一本"+author+dan->query("name")+"。", -1);
            ANTIROBOT_D->same_as_fullme(me);
            destruct(this_object());
            return 1;
        }
    }
    
}