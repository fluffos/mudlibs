 // street3.c
#include <room.h>
inherit ROOM;
// #include "/questnpc/lovestory1/event_place.h"
void create()
{
  set("short","舞雩台");
  set("long",@LONG
这里便是济南城每年祭祀孔圣人的祭台，台上有两块石碑，一块刻着“舞雩
台”，另一块刻着“圣贤乐趣”，据说当年孔子的门生樊迟随孔子游于舞雩台下，
便求教“崇德、修慝、辨惑”之道，孔子一一解答，遂成佳话。百年沧桑，经后
人多次修葺，舞雩台历久如新，高高耸立。东西两侧，皆是些热闹的豪宅。
LONG
  );
  set("exits",([
         "northdown":__DIR__"street2",
         "southdown":__DIR__"street4",
         "westdown":__DIR__"qiyuan1",
               ]));
        set("objects", ([
        __DIR__"obj/shibei1" : 1,
//            "/obj/specials/ding/ding_jn" : 1,
                        ]) );
    set("outdoors", "jinan");
        set("coor/x",30);
        set("coor/y",1930);
    set("coor/z",20);
        setup();  
}  
/* int valid_enter(object me)
{ 
        if(me->query("lovestory1"))
                add_trigger_count(me);
        return 1;
}     */ 
