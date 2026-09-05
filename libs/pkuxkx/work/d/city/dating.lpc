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
        1号房：欧冠：中央陆军  VS  国际米兰    （不让球）    （截止投注时间：2010.4.6 24:00）
        2号房：欧冠：巴塞罗那  VS  阿森纳      （不让球）    （截止投注时间：2010.4.6 24:00）

\n"NOR
);
    set("item_desc",([
        "pingmu"  :  "想赌哪场比赛进入不同房间，用bet命令下注，详细规则请查help duqiu。\n"
    ]));
    set("exits",  ([  /*  sizeof()  ==  1  */
        "west"  :  "/d/city/fangchan",
        "1"  :  "/d/city/duju1",
      "2"  :  "/d/city/duju2",
//       "4"  :  "/d/city/duju4",
//       "3"  :  "/d/city/duju3",
    ]));
    set("objects",  ([  /*  sizeof()  ==  1  */
        __DIR__"npc/caopan"  :  1,
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_beg",  1);
   set("no_task",1);
    setup();
}

