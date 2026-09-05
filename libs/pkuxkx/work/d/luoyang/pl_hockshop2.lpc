
#include <ansi.h>
inherit  "/feature/player_hockshop";

void  create()
{
    set  ("short",  HIC"美廉美当铺"NOR);
    set  ("long","美的不止是商品，廉的绝对是价格。\n");

    set("exits",  ([  /*  sizeof()  ==  1  */
        "northwest"  :  __DIR__"center",
    ]));
	
	//玩家店铺id从100开始
	unique_id = 101;

    setup();
	setup_shop();
}

