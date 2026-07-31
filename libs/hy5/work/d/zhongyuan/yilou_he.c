// /d/map/zhongyuan/yilou_he.c
// by lala&lnwm, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","伊娄河边");
    set("long",@LONG
原本扬州是在长江边的，但是由于长江北岸不断淤积，致使北岸南移，后来
扬州就远离长江了。到唐朝玄宗开元二十五年的时候，润州刺史齐瀚开伊娄河二
十五里，以使漕船能从瓜洲直达扬子。诗仙李白曾为此赋诗一首：

    齐公凿新河，万古流不绝，丰功利生人，天地同朽灭。
        
LONG );
    set("exits",([
        "north"     : __DIR__"yunhe4",
//        "south"     : __DIR__"yilou_he",
//      "southwest" :
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

