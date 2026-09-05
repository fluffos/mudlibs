#include <ansi.h>
inherit  "/feature/player_hockshop";

void  create()
{
    set  ("short",  HIC"通四海兰州分店"NOR);
    set  ("long","财源通四海，贸易达三江。\n");

    set("exits",  ([  /*  sizeof()  ==  1  */
        "west"  :  __DIR__"east_lane2",
    ]));
	
	//玩家店铺id从100开始
	unique_id = 111;

	setup();
	setup_shop();
}

