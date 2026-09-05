
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "信相寺");
        set("long", "这里是川西著名的佛教寺院。它的前身是唐代的妙圆塔院，宋时改称信相寺。\n");
       

        set("exits", ([
               //"south" : __DIR__"zongdufu",
               //"east" : __DIR__"wenshuyuan",
               "west" : __DIR__"northstreet2",
               
                
        ]));
        
        //set("outdoors", "chengdu");
        setup();
   
}

void init()
{
    object me=this_player();
    if (me->query_temp("jn/step3a"))
    {
        tell_object(me,"一个女声道：还是在青羊宫见面比较好。\n");
        tell_object(me,"人影一闪而过，你还以为自己花了眼。\n");
        me->delete_temp("jn/step3a");
        me->set_temp("jn/step3b",1);
    }
    return;
}
