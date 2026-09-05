//  Room:  duqiu-dating
//  by  hubo  

#include <ansi.h>
inherit  ROOM;

void  create()
{
    set  ("short",  HIC"博彩公司"NOR);
    set  ("long",
HIW"这是扬州城新开的博彩公司，这里的老板据说是北侠的巫师与欧洲各大联赛有着密切的关系。
房间里几台上网的电脑，一群赌徒围在电脑前查询着赔率，后面还有一台大电视，放映着精彩的足
球比赛。在墙上还有个大屏幕（pingmu）滚动播放着博彩规则。

柜台上有个大牌子写着：
    开放中的赌局：
        1号房：中超联赛：长春亚泰   VS  北京国安    不让球  （截止投注时间：2008.5.17 12:00）
  
        2号房: 中超联赛：天津康师傅 VS  山东鲁能    不让球 （截止投注时间：2008.5.17 12:00）
 
\n"NOR
);
    set("item_desc",([
        "pingmu"  :  "想赌哪场比赛进入不同房间，用bet命令下注，详细规则请查help duqiu。\n"
    ]));
    set("objects",  ([  /*  sizeof()  ==  1  */
        __DIR__"npc/caopan"  :  1,
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_beg",  1);
    setup();
}

