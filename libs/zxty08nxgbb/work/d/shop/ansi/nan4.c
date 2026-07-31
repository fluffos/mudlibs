inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HBYEL+HIW"商业街南四街"NOR);        
set("long", 
"信步而行，不知不觉商业街过了一半，行过一座三层的
市楼，眼前更加热闹，人称“一日有三市”，这里更是商贸
聚集中心，放眼看去，各个铺面花岗岩门坎上都有两道很深
的车辙印痕，这里车水马龙的热闹更可见一斑。

        $HIM$五华楼$NOR$ -- 商业街南四街 -- $HIM$清风阁$NOR$ 
" );
       set("outdoors", "player");
       set("no_fight",1);
        set("exits", ([

  "north" : __DIR__"nan3",
  "west" : __DIR__"jingzhou_shop",
  "east" : __DIR__"ty_shop",
        ]));
        set("objects", ([
        ]));
        setup();
}

void init()
{
        object me = this_player();
                tell_object(me, WHT "\n欢迎光临扬州商业街，想知道如何操作"
                                "请(" HIC "help trade & help cmdtrade" NOR + WHT ")，祝你"
                                "购物愉快。\n\n" NOR);

}

