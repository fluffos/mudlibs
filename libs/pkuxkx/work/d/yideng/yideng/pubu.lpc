//桃源瀑布
//by icer
inherit ROOM;

int do_jiejing();
int do_climb();
void create()
{
        set("short", "瀑布");        set("long", @LONG
空山寂寂，水声在山谷间激荡回响。只见一道白龙似的大瀑布从
对面双峰之间奔腾而下，声势甚是惊人。北边有一块大石，名曰
“观瀑台”，如果爬到上面似乎可以更加清楚的看到瀑布全景。
瀑布旁有间草屋。瀑布旁柳树下坐着一个人，头带斗笠，身披蓑衣。
LONG
);
set("exits", ([
                "southwest" :__DIR__"road3",
]));
set("objects",([

      __DIR__"npc/yu" : 1,
     ]));
set("outdoors", "taoyuan");

setup();
}

void init()
{
        add_action("do_jiejing","jiejing");
        add_action("do_climb","climb");
}
int do_climb()
{
        object me=this_player();
        object *inv;
        int lp,user;
        
        inv=all_inventory(me);
        user=0;
        for(lp=0;lp<sizeof(inv);lp++)
        	if(userp(inv[lp]))
        		user=1;
        		
        if(user)
        	return notify_fail("你的负重太高了，爬不上去。\n");
        	
        if (me->query_skill("dodge")<100)
          return notify_fail("就你目前的轻功水平，还没爬上去就恐怕跌下来摔死。\n");
        
        message_vision("$N抬头看了观瀑台一眼，叹了口气，手脚并用向上爬去。\n",me);
        me->move(__DIR__"pubu1");
        message_vision("$N哼哧哼哧的爬上了观瀑台。\n",me);
        return 1;        
}
int do_jiejing()
{
        object me=this_player();
  object *inv;
  int lp,user;
        
  inv=all_inventory(me);
  user=0;
  for(lp=0;lp<sizeof(inv);lp++)
  	if(userp(inv[lp]))
   		user=1;
        		
  if(user)
  	return notify_fail("你的负重太高了，进不了小船。\n");

        if (me->query("task_duan1"))
        {
                me->move(__DIR__"houshan");
                return 1;
        }
        else if(me->query_temp("dali/ask_yideng"))
        {       
                tell_object(me,"你按照镇南王指点的捷径直接上了后山。\n");
                me->move(__DIR__"houshan");
                return 1;                 
        }
        else if(me->query("family/master_id")=="yideng dashi")
        {       
                tell_object(me,"你从捷径直接上了后山。\n");
                me->move(__DIR__"houshan");
                return 1;                 
        }        
        else
        {
                return notify_fail("什麽?\n");
        }
}
