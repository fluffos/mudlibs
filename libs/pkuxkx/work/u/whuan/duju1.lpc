//  Room:  duju1
//  by  hubo  
inherit  ROOM;
#include <ansi.h>
#include <localtime.h>

int  room_status  =  0;
int  *res  =  allocate(5);

mapping  bets  =  ([
    "1"  :  "主队胜",
    "2"  :  "平局",
    "3"    :  "客队胜",
]);

void  create()
{
    set  ("short",  HIC"赌球室一"NOR);
    set  ("long",
HIW"这是博彩公司后面的一间赌球室，一个操盘手用警惕的眼光打量着你，在墙上挂着一个大屏幕
电视，即将放映本场竞猜足球比赛。

柜台上有个大牌子写着：
    本房间的赌局：（为了方便携带，赌球单位一律是cash）
            中超联赛：长春亚泰   VS  北京国安    不让球  （截止投注时间：2008.5.17 12:00）
                      赔率代码: 1 主队胜   赔率：  2.20
                      赔率代码: 2 打和     赔率：  1.20   
                      赔率代码: 3 客队胜   赔率：  2.00  
\n"NOR
);
   
    set("exits",  ([  /*  sizeof()  ==  1  */
        "out"  :  "/d/city/dating",
    ]));
    set("objects",  ([  /*  sizeof()  ==  1  */
//        __DIR__"npc/caopan"  :  1,
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_beg",  1);
    setup();
}

void  init  ()
{
    add_action  ("do_bet","bet");
    add_action  ("do_betlist","betlist");
}

int  do_bet  (string  arg)
{
    object  me  =  this_player();
    int  amount;
    string  code;
    object cash;
    object  ob;
    mixed *t;

    t = localtime( time() );
    if( t[LT_MON] >= 3 && t[LT_MDAY] > 17 )
    	  return  notify_fail("对不起，投注时限已经过了，下次请早点来。\n");

    if  (!arg  ||
            sscanf(arg,"%s %d",code,amount)  !=  2)
        return notify_fail("请使用：  bet <赔率代码> <数目> \n");

    if  (code  !=  "1"  &&
         code  !=  "2"  &&
         code  !=  "3" )
        return  notify_fail("你要押哪种赔率代码？\n");
    
    cash = present("cash", me);
    if(!cash) 
       return notify_fail("你身上没有银票。\n");
        
    if((int) cash->query_amount() < amount)
        return notify_fail("你身上没有那麽多银票。\n"); 

    if  (amount  <  1)
        return  notify_fail("请多押一些钱。\n");
 
    if  (me->query("duqiu/amount1") > 0)
        return  notify_fail("你已经赌过这场了，再玩其他场次吧。\n");

    if  (room_status  >  1)
        return  notify_fail("现在正在赌呢，稍等片刻。\n");

    me->set("duqiu/what1",1);  //确定本场赌局序号，以后赌局依次排序，防止bug
    me->set("duqiu/code1",code);
    me->set("duqiu/amount1",amount);
    message_vision  (sprintf("$N拿出%s张银票，买了本场比赛%s。\n",
                                                    chinese_number(amount),
                                                    bets[code]),
                                    me);

    if  (amount  ==  cash->query_amount())
        destruct  (cash);
    else
        cash->add_amount(-amount);

    return  1;
}

int  do_betlist  (string  arg)
{
    object me; 
    me = this_player();
    if( !me->query("duqiu") )
    {
       write("你应该先下注这场球! \n");
       return 1;
    }
    if( !me->query("duqiu/amount1") )
       write("你没有下注这场球! \n");       
    else 
       write("你在本赌场买了"+me->query("duqiu/amount1")+" 张银票，赔率代码是"+me->query("duqiu/code1")+"。\n"); 

    return 1;
}

