//放逐岛 shandong

#include <ansi.h>
#include <room.h>
inherit FANGZHU_ROOM; //放逐岛继承文件，不是普通的room

void create ()
{
  set ("short","放逐岛");
  set ("long", @LONG

这里是人迹罕至的放逐岛，荆棘丛生，一片荒芜，只有豺狼猛兽，
极难见到半个人影。
LONG);

        set("exits", ([ /* sizeof() == 4 */             
                "out" : __DIR__"shanding",              
        ]));
        
        set("objects", ([ /*     */   
        ]));
  
        set("alternative_die",1); 
        set("fangzhuroom",1); 
//放逐岛房间标志，cmds npc 判断所需！

        set("objects", ([/* sizeof() == 3 */    
                "/d/obj/food/baozi" : 5, 
                "/d/obj/food/chahu" : 2,
        ])); 
        set("resource", ([ /* sizeof() == 1 */ 
                "water" : 1, 
        ])); 

        setup();
        setup2();
}

void init2()
{
}

int valid_leave() 
{ 
        if(present("bao", this_player()) ) 
                return notify_fail("你听见一个声音说：吃完包子再走是这的规矩！\n"); 
        if(present("teapot", this_player()) )    
                return notify_fail("你听见一个声音说：别把我的茶壶拿跑了！\n"); 
        return ::valid_leave(); 
} 
