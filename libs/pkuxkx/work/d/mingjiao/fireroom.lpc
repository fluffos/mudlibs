#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"圣火坛"NOR);
        set("long", @LONG 
这里是明教的圣火坛，圣火(shenghuo)熊熊燃烧着。有明教弟子不间断的看
守着圣火。
LONG );
        set("no_task",1);
        set("exits", ([
                "out" : __DIR__"dadian",
               
 ]));
       /* set("objects", ([
                CLASS_D("mingjiao") + "/zhang" : 1,
 ]));*/
        set("no_mj_newbie",1);
        setup();

}

void init()
{
    object me=this_player();
    add_action("do_kanshou","kanshou");
    
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    {
        tell_object(me,"你是怎么混进来的？\n");
        me->move(__DIR__"dadian");
        return;
    }
}



int shenghuo(object me)
{
    int n=random(100);
    string desc;
    string* space=({" ","  ","   ","    ","     ","      ","好像","似乎","也许","可能","应该","大约"});
    string* des1=({"圣火看起来烧得正旺，",
                   "圣火熊熊地燃烧着，",
                   "圣火势头略微小了一点，",
                   "圣火越烧越旺，",
                   "圣火烧得噼里啪啦的，",
                   "圣火势头略微大了一点，",
                   "圣火中出现了几朵火花，"});
    string* des2a=({"不需要加柴火。\n",
                   "没必要加柴火。\n",
                   "没有必要加柴火。\n",
                   "柴火不加也行。\n",
                   "但是还不用加薪。\n",
                   "仔细盯着就是了。\n",
                   "你可以休息一下。\n",
                   "你需要小心看着。\n"});
    string* des2b=({"不需要扇风。\n",
                   "没必要用扇子。\n",
                   "没有必要用扇子。\n",
                   "不必要用扇子。\n",
                   "扇子就收起来吧。\n",
                   "扇子的另一头正好用来挠痒。\n",
                   "这时候用扇子不太明智。\n",
                   "你盯着就可以了。\n"});
    string* des2c=({"快加点柴火吧。\n",
                   "有需要加柴火。\n",
                   "很需要加柴火。\n",
                   "太需要加柴火了。\n",
                   "柴火快烧光了。\n",
                   "再不加柴火，圣火就要熄灭了。\n",
                   "有多少柴火都加进去吧。\n",
                   "马上加柴火。\n"});
    string* des2d=({"赶紧扇风，火会更大。\n",
                   "有必要用扇子。\n",
                   "很必要用扇子。\n",
                   "马上扇呀。\n",
                   "扇！\n",
                   "你拿着扇子干什么的？快扇风啊。\n",
                   "但是风不够大啦。\n",
                   "快点扇风吧，要灭了。\n",
                   "一二三，扇扇扇，快快快。\n"});
    if (me->query_temp("mingjiao/tasks/task1fail"))
    {
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/chai"))
    {
        message_vision("因为$N没有及时添柴，圣火熄灭了。快去狮王那里领罪吧。\n",me);
        me->delete_temp("mingjiao/tasks/task1act");
        me->set_temp("mingjiao/tasks/task1fail",1);
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/shan"))
    {
        message_vision("因为$N没有及时扇风，圣火熄灭了。快去狮王那里领罪吧。\n",me);
        me->delete_temp("mingjiao/tasks/task1act");
        me->set_temp("mingjiao/tasks/task1fail",1);
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/task1actsuc")>9)
    {
        me->set_temp("mingjiao/tasks/task1suc",1);
        tell_object(me,"你已经看守了足够久时间的圣火，可以会狮王那里复命了。\n");
        return 1;
    }
    if (n<=99)
    {
        desc=des1[random(sizeof(des1))]+space[random(sizeof(space))]+des2a[random(sizeof(des2a))];
       
        me->set_temp("mingjiao/tasks/task1act","no");
    }
    if (n<74)
    {
        desc=des1[random(sizeof(des1))]+space[random(sizeof(space))]+des2b[random(sizeof(des2b))];
        
        me->set_temp("mingjiao/tasks/task1act","no");
    }
    if (n<49)
    {
        desc=des1[random(sizeof(des1))]+space[random(sizeof(space))]+des2c[random(sizeof(des2c))];
        me->set_temp("mingjiao/tasks/chai",1);
        me->set_temp("mingjiao/tasks/task1act","chai");
    }
    if (n<24)
    {
        desc=des1[random(sizeof(des1))]+space[random(sizeof(space))]+des2d[random(sizeof(des2d))];
        me->delete_temp("mingjiao/tasks/chai");
        me->set_temp("mingjiao/tasks/shan",1);
        me->set_temp("mingjiao/tasks/task1act","shan");
    }
    tell_object(me,desc);
    
    call_out("shenghuo",10,me);
    return 1;
}

int do_kanshou()
{
    object me=this_player();
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    return 0;
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (me->query_temp("mingjiao/tasks/task1start"))
    return notify_fail("你已经开始看守圣火了。\n");
    if (me->query_temp("mingjiao/tasks/task1fail"))
    return notify_fail("圣火已经熄灭，快去狮王那里领罪吧。\n");
    else
    {
        me->set_temp("mingjiao/tasks/task1start",1);
        message_vision("$N找了个地方，席地坐了下来，开始看守圣火。\n",me);
        
        call_out("shenghuo",1+random(5),me);
        return 1;
    }
}

int valid_leave(object me,string dir)
{  
	
    if (dir=="out"&& me->query_temp("mingjiao/tasks/task1fail"))
    {
        return ::valid_leave(me, dir);
    }
	if (dir=="out"&& me->query_temp("mingjiao/tasks/task1actsuc")>9)
    {
        return ::valid_leave(me, dir);
    }
    else
    
	return notify_fail("你是来看守圣火的，不能随意离开！\n");
}