
//      xuelu1.c 积雪小路

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"积雪小路"NOR);
        set("long",@LONG 
这是一条积满雪的小路，蜿蜒向上，本来就陡峭难行，现在满覆冰雪，一
步一滑。路一侧是看不到底的山谷，山风呼啸而过，吹得人遥遥欲坠，如果一
个不小心摔了下去......
LONG);
        set("exits",([
                "northup" : __DIR__"xuelu2",
                "eastdown": __DIR__"shanmen"

        ]));

        setup();
}
void init()
{
        if(NATURE_D->query_daytime() != "event_noon"){
        	message_vision(HIW"\n狂风夹着雪花劈头盖脸打了过来，吹得$N睁不开眼。突然从山崖边落下一大块积雪，$N躲闪不及正砸在头上！\n\n"NOR,this_player());
        	message_vision(HIR"$N脚下不稳，顺着山崖跌落下去。\n"NOR,this_player());
    		this_player()->move(__DIR__"xuegu");
    		this_player()->unconcious();
       		}
}
