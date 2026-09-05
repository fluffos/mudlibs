
#include <room.h>
inherit ROOM;

void create()
{
        set("short","神龙潭");
        set("long",@LONG 
前面走着走着就是一片光亮的地带，旁边立了一块石碑，暗红色的字迹隐隐
便是“神龙潭”三字。听说背叛神龙教的人如果被抓住，就会被扔到神龙潭这里受死，
或许就是这里。地上乱七八糟的全是骸骨和骷髅，也许就是前人留下的。
LONG
        );

        set("exits", ([
                "out" : __DIR__"shandong2",
                   
        ]));
        set("objects", ([
        "/d/shenlongdao/obj/skeleton":1+random(3),
        "/d/shenlongdao/obj/kulou":1+random(3),	
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
        "/d/shenlongdao/npc/snake"+random(7):1,
      	"/d/shenlongdao/npc/snake"+random(7):1,
     		"/d/shenlongdao/npc/snake"+random(7):1,
     		"/d/shenlongdao/obj/dulongbian":1,
       ]));
		set("no_newbie_task",1);
        set("outdoors","shenlongdao");
        setup();

}

