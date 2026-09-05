// meizhuang        孤山梅庄
// by bing

#include <ansi.h>

inherit ROOM;


void init();

void create()
{
    set("short", "孤山梅庄");
        set("long","这里是一座朱门白墙的大庄院。大门(gate)外写着\n\n\n" + HIG "                 梅      庄" NOR + "\n\n\n                               两个大字，旁边署着“虞允文题”四字。
虞允文是南宋破金的大功臣，这几个字儒雅之中透着勃勃英气。\n");

    set("exits", ([
         "northeast" : "/d/hangzhou/xihu/gu_shan",
  ]));

    set("outdoors", "riyuejiao");
    set("item_desc",([
        "tong huan"     :"这铜环擦得精光雪亮，你可以用它来敲门(knock+ gate(door) + 次数)。\n",
        "gate"  : "这是两扇朱漆的大门，紧紧的关闭着。门上有两个铜环(tong huan)。\n",
    ]));
    setup();
}


void init()
{
        add_action("do_knock", "knock");
        add_action("do_enter", "enter");
}

int do_enter()
{
        object me;
        me = this_player();
        
        if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30)
                return notify_fail("你身上背的东西太多，进不了梅庄。\n");


        if ((me->query_temp("riyue/opendoor")) && query("exits/enter"))
        {
                message_vision("$N整了整衣服，走了进去。\n",me);
                message_vision("两个家丁上前关上了大门。\n",me);
                delete("exits/enter");
                me->move(__DIR__"tianjing");
                return 1;
        }
        if(!query("exits/enter"))
                return notify_fail("什么？\n");
        if(!me->query_temp("riyue/opendoor"))
        {
                tell_object(me,"主人又没让你进去，你怎么能往里闯呢？\n");
                return 1;
        }
}
int check_ob(object me)
{
        object* inv;
        object ding;
        int i;

        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
                if(userp(inv[i]))
                {
                        if(!( ding = find_living("ding jian")) )
                                ding = load_object("/d/riyuejiao/npc/dingjian");
                        ding->set("combat_exp",1000000000);
                        ding->set("max_neili",200000);
                        ding->set("neili",200000);
                        ding->set("max_qi",100000);
                        ding->set("qi",100000);
                        ding->set("jiali",30000);
                        ding->move(environment(me));
                        inv[i]->move(__DIR__"meizhuang");
                        ding->command("say 什么人！竟敢私闯梅庄！");
                        ding->kill_ob(inv[i]);
                        inv[i]->set("qi",2);
                }
        return 1;
}
                
        

int do_knock(string arg)
{
        object me,room;
        int num,i;
        string gate;
        me = this_player();
//      if(!( room = find_object(__DIR__"meizhuang")) )
//        room = load_object(__DIR__"meizhuang");

        if (query("exits/enter"))
                return notify_fail("大门已经是开着了。\n");

        if (!arg || sscanf(arg, "%s %d",gate, num) != 2)
                return notify_fail("你要敲几下？\n");
        if (gate != "gate" && gate != "door")
                return notify_fail("你要敲什么？\n");
        
        i = sscanf(arg,"%s %s",gate,arg);
      message_vision("$N抓住门环，敲了" + CHINESE_D->chinese_number(num) + "下。\n",me);
        if (num == 4)
        {
                me->set_temp("riyue/敲1",1);
                return 1;
        }
        if (num == 2 && me->query_temp("riyue/敲1"))
        {
                me->set_temp("riyue/敲2",1);
                me->delete_temp("riyue/敲1");
                return 1;
        }
        if (num == 5 && me->query_temp("riyue/敲2"))
        {
                me->set_temp("riyue/敲3",1);
                me->delete_temp("riyue/敲2");
                return 1;
        }
        if (num == 3 && me->query_temp("riyue/敲3"))
        {
                me->delete_temp("riyue/敲3");
                message_vision("过了半晌，大门缓缓打开，并肩走出两个家人装束的老者。\n",me);
/*                if ((me->query("title") == MAG "日月神教" NOR + HIR "圣姑" NOR)
                || ( me->query("title") == MAG "日月神教" NOR + HIG "总管" NOR)
                || ( me->query("title") == MAG "日月神教" NOR + HIR "副教主" NOR))
                {
                        message_vision("一位老者说道:「我们庄主吩咐了，从此孤山梅庄与日月神教已经没有关系。" 
                                + RANK_D->query_respect(me) + "请回吧！」说着关上了门。\n",me);
                        return 1;
                } */  
 				//拜师任我行之后可以自由进出梅庄，不需要四宝（拜任我行已经消耗了四宝） by lordstar 2017/8/25
               if ( (objectp(present("heimu ling",me)) && me->query_temp("riyue/杀任"))
				|| ( me->query("family/master_id")=="ren woxing"
					 && me->query("family/master_name")=="任我行")
                ||(     objectp(present("guangling san",me))
                        && objectp(present("ouxue pu",me))
                        && objectp(present("shuaiyi tie",me))
                        && objectp(present("xishan tu",me)) ))
                {
                        message_vision("一位老者说道：「" + RANK_D->query_respect(me) + "请进厅上用茶，待在下去禀告敝上。」\n",me);
                        me->set_temp("riyue/opendoor",1);
                        message_vision("$N整了整衣服，走了进去。\n",me);
                        me->move(__DIR__"tianjing");
                      call_out("check_ob",1,me);
                        return 1;
                }
                message_vision("一位老者说道：「我家主人向不见客。」说着关上了门。\n",me);
        }

        return 1;
}


