
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
void create()
{
        set("short", "打铁铺");
        set("long", @LONG
这是洛阳城里普通的一家打铁铺，以维修兵器著称。只要兵器没断，无论损坏程度如何，
都能给修好了。当然，价格也是不菲的。墙角有一只大橱柜(chugui)。
LONG
        );

        set("exits", ([
               "southwest" : __DIR__"dongdajie1",
        ]));
        set("objects", ([
                __DIR__"npc/tiejiang":1,                
        ]));
        set("item_desc", ([
		"chugui" : "一只大橱柜，也不知有什么用。\n", 
		
	    ]));
        set("outdoors", "luoyang");
        set("enterperson",5);
        setup();
        call_out("gettime",1);
        
}
int clear_room()
{
	string* where =({"/d/luoyang/mishi1","/d/luoyang/mishi2","/d/luoyang/mishi3","/d/luoyang/mishi4","/d/luoyang/mishi5","/d/luoyang/mishi6","/d/luoyang/mishi7","/d/luoyang/mishi8",});
	object *ob,place;
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	for (int i=0;i<sizeof(ob);i++)
	{
		for (int j=0;j<sizeof(where);j++)
		if (environment(ob[i])==load_object(where[j]))
		{
			ob[i]->move(this_object());
			tell_object(ob[i],"你稀里糊涂就来到了这里。\n");
			ob[i]->delete_temp("tiejiangjob/ticket");
		}
	}
	return 1;
}
int gettime()
{
    mixed* timeinfos;
    int hour;
    int minute;
    int mday;
    object mishigate=load_object("/d/luoyang/mishigate");
    object hammer,tiejing,target,loc;
    timeinfos = localtime(time());
    hour = timeinfos[LT_HOUR];
    minute = timeinfos[LT_MIN];
    mday = timeinfos[LT_MDAY];
    if (hour==18 && minute==30)
    {
        hammer=new("/d/luoyang/obj/hammer");
        if (hammer)
        {
            target=new(__DIR__"npc/holder");
            hammer->move(target);
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(loc) || 
               !loc->isroom()||
               TASK_D->place_belong(loc)=="不明区域"||
               base_name(loc) == "/adm/daemons/taskd")
        {
          loc = TASK_D->random_place();
        }
//	        loc = TASK_D->random_place();
   	        target->move(loc);
            if (target)    
            {
		        CHANNEL_D->do_channel(this_object(), "jh", "洛阳城传闻：欧冶子的铁锤据说在"+TASK_D->place_belong(loc)+"出现过！", -1);
            }
        }
       
    }
    if (minute==11)
    {
        tiejing=new("/d/luoyang/obj/tiejing");
        if (tiejing)
        {
            target=new(__DIR__"npc/holder2");
            tiejing->move(target);
	        loc = TASK_D->random_place();
   	        target->move(loc);
            if (target)    
            {
		        CHANNEL_D->do_channel(this_object(), "jh", "洛阳城传闻：铁精据说在"+TASK_D->place_belong(loc)+"出现过！", -1);
            }
        }
       
    }
    if (minute==41 )
    {
        tiejing=new("/d/luoyang/obj/tongkuai");
        if (tiejing)
        {
            target=new(__DIR__"npc/holder2");
            tiejing->move(target);
	        loc = TASK_D->random_place();
   	        target->move(loc);
            if (target)    
            {
		        CHANNEL_D->do_channel(this_object(), "jh", "洛阳城传闻：铜块据说在"+TASK_D->place_belong(loc)+"出现过！", -1);
            }
        }
       
    }
    if (minute==28)
    {
        
        if (mishigate)
        {
            mishigate->delete("mishiopen");
        }
        this_object()->delete("enterperson");
        CHANNEL_D->do_channel(this_object(), "bd", "铁匠(Tie jiang): 杀人啦，救命啊！", -1);
		clear_room();
    }
    if (minute==29)
    {
        CHANNEL_D->do_channel(this_object(), "bd", "铁匠(Tie jiang): 快来啊，不然老子要完蛋大吉啦！", -1);
    }
    if (minute==30)
    {
        this_object()->set("enterperson",5);
    }
    remove_call_out("gettime");
    call_out("gettime",60);
    return 1;
}


void init()
{
    add_action("do_move", ({ "move" }));
    add_action("do_da", ({ "dazao" }));
}
int removeanqi()
{
    this_object()->delete_temp("luoyang/anqi");
}
int do_da(string arg)
{
    object me=this_player();
    object material,product;
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
	    return 1;
    }
   
    if (!arg||(arg!="anqi" && arg!="throwing" && arg!="暗器"))
	{
		return notify_fail("你要打造什么？\n");
	}
    if (!present("ouyezi's hammer",me))
    {
        return notify_fail("你没有欧冶子的铁锤无法打造暗器！\n");
    }
    if (me->query("forging")<=149)
    {
        return notify_fail("以你目前的锻造术无法打造暗器！\n");
    }
    if (this_object()->query_temp("luoyang/anqi"))
    {
        return notify_fail("刚刚有人在这里打造过东西，炉火还没有退，你迟些再来吧。\n");
    }
    if (present("iron essence",me))
    {
        material=present("iron essence",me);
        product=new("/d/xingxiu/npc/obj/chuanxinding");
        if (product)
        {
            product->set("owner",me->query("id"));
            product->move(me);
            if (material)
            {
                destruct(material);
            }
            me->add_busy(random(5));
            this_object()->set_temp("luoyang/anqi",1);
            message_vision("$N悉心打造出一枚星宿派的镇派之宝--穿心钉。\n",me);
            CHANNEL_D->do_channel(this_object(), "jh", HIY"听说有人在洛阳城打造出一枚穿心钉！", -1);
            call_out("removeanqi",120+random(120),this_object());
        }
        return 1;
    }
    if (present("liu huang",me)&&present("copper block",me))
    {
        
        product=new("/d/xingxiu/npc/obj/shuoxindan");
        if (product)
        {
            product->set("owner",me->query("id"));
            product->move(me);
            material=present("liu huang",me);
            if (material)
            {
                destruct(material);
            }
            material=present("copper block",me);
            if (material)
            {
                destruct(material);
            }
            me->add_busy(random(5));
            this_object()->set_temp("luoyang/anqi",1);
            message_vision("$N悉心打造出一枚星宿派的独门暗器--烁心弹。\n",me);
            CHANNEL_D->do_channel(this_object(), "jh", HIY"听说有人在洛阳城打造出一枚烁心弹！", -1);
            call_out("removeanqi",120+random(120),this_object());
        }
        return 1;
    }
    else
    {
        return notify_fail("你没有任何原材料，怎么打造东西？\n");
    }
}

int do_move(string arg)
{
    object me=this_player();
    
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
	    return 1;
    }
   
    if (!arg||(arg!="chugui" && arg!="chu gui" && arg!="gui" && arg!="大橱柜" && arg!="橱柜"))
	{
		return notify_fail("你要做什么？\n");
	}

    if (time()-(me->query("tiejiangjob_last_time"))<12600)//cd时间
	{
		tell_object(me,"你上次才来帮助过铁匠没多久，这次把机会让给别人吧。\n");
		return 1;
	}
    if (this_object()->query("enterperson")>4)
    {
        tell_object(me,"大橱柜似乎被太多人搬坏了，再也回复不到原位。\n");
        return 1;
    }
    else
    {
        this_object()->add("enterperson",1);
        message_vision("$N轻轻挪动了一下橱柜，橱柜翻转过去，$N立刻不见了踪迹。\n",me);
        me->move(__DIR__"mishigate");
        me->set_temp("tiejiangjob/ticket",1);
        me->delete_temp("tiejiangjob/permit");
        message_vision("$N从橱柜中钻了出来。\n",me);
        return 1;
    }

}