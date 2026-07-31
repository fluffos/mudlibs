//密洞内 
// by steel 
// change by wind
#include "ansi.h"
inherit ROOM;
//#include "mimi.h"
void create()
{
        object gold;
        set("short", "内洞");
        set("long", @LONG
        这里就是堆放天下密宝的密洞了!!快拿吧!    
洞顶刻的有字.(zi)
LONG
        );
set("valid_startroom", 1);
set("no_clean_up",1);
set("no_quit",1);
        set("exits", ([
                "north" : __DIR__"midong",
                ]));
    set("item_desc",([
                "zi" : HIR "
                   人     鸟
                   为     为 
                   财     食
                   死     亡 
                   \n\n"NOR,
        ]));   

   
        set("objects",([
            __DIR__"obj/cw_armor":1,
            __DIR__"obj/cw_boots":1, 
            __DIR__"obj/cw_cloth":1,
            __DIR__"obj/cw_hat" :1,
            __DIR__"obj/book-blade":1,
            __DIR__"obj/book-parry":1,
                     __DIR__"npc/baoshu":1,
        ]) );
 setup();
} 

int valid_leave(object me, string dir)
{
        int num_dia,num_fei,total_steps;
        object gold,feicui;

 gold=present("diamond",this_object());
        return ::valid_leave(me,dir);
}
