// rukou.c  监狱入口
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"监狱入口"NOR);
       set("long", @LONG
这里是明教的地下监狱的入口处。明教的执法者站在那里，威严无比，令
人不敢正视。入口处有一扇大铁门(men)，铁门处用一大锁锁住。
LONG);    
	set("exits", ([		
		"northwest" : __DIR__"jinqi",
                "southwest" : __DIR__"zl7",
	]));  
        set("item_desc", ([
                "men" : "一扇大铁门，看上去十分牢固。\n"
        ]));                       
	set("objects",([
                __DIR__"npc/dizi1" : 1,
                __DIR__"npc/dizi4" : 1,
                CLASS_D("mingjiao") + "/leng" : 1,
	]));
        set("coor/x",-260);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-260);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("mj/rukou"))
           me->set_temp("mj/rukou",1);
}
