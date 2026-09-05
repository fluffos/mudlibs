
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", CYN"青羊宫"NOR);
        set("long", "青羊宫地处原青羊肆，传说老子骑青牛过函谷关，为关今尹喜讲道德经，讲\n到一半，老子有事要走，对尹喜说：“子行道千日后于成都青羊肆寻吾”。千日\n后，老子如约而来，在这里继续对尹喜讲经说法。\n");
       

        set("exits", ([
               
               "south" : __DIR__"jinjiang1",
               //"west" : __DIR__"chaguan",
                "north" : __DIR__"weststreet1",
                
        ]));
        set("objects", ([

        "/d/city/npc/bookseller":1,
        ]));
        //set("outdoors", "chengdu");
        setup();
   
}

void init()
{
    object me=this_player();
    if (me->query_temp("jn/step3b"))
    {
        tell_object(me,"女声歉意地道：真不好意思，有人在场，我在合江亭等你。\n");
        tell_object(me,"这次连人影都没有看见。\n");
        me->delete_temp("jn/step3b");
        me->set_temp("jn/step3c",1);
    }
    return;
}

int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
           return notify_fail("锦江看看就好了，难道你真要投河自尽吗？\n");
        
    }
	return ::valid_leave(me, dir);
}