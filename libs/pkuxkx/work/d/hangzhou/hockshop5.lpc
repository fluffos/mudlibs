//  Room:  duqiu-dating
//  by  hubo  

#include <ansi.h>
inherit  "/feature/player_hockshop";

void  create()
{
    set  ("short",  HIC"通四海临安府分店"NOR);
    set  ("long","财源通四海，贸易达三江。\n");

    set("exits",  ([  /*  sizeof()  ==  1  */
        "south"  :  __DIR__"xidajie1",
    ]));
	
	//玩家店铺id从100开始
	unique_id = 400;

    setup();
	setup_shop();
}

