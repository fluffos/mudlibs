//  Room:  duqiu-dating
//  by  hubo  

#include <ansi.h>
inherit  "/feature/player_hockshop";

void  create()
{
    set  ("short",  HIC"通四海长安分店"NOR);
    set  ("long","财源通四海，贸易达三江。\n");

    set("exits",  ([  /*  sizeof()  ==  1  */
        "west"  :  __DIR__"eastmarket-3",
    ]));
	
	//玩家店铺id从100开始
	unique_id = 500;

  setup();
	setup_shop();
  set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}

