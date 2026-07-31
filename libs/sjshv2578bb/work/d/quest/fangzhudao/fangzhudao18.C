//放逐岛 fangzhudao18

#include <ansi.h>
#include <room.h>
inherit FANGZHU_ROOM; //放逐岛继承文件，不是普通的room

string *list=({
        "tiger","fox","wolf","heibao","pig",
});

void create (int num)
{
  set ("short","放逐岛");
  set ("long", @LONG

这里是人迹罕至的放逐岛，荆棘丛生，一片荒芜，只有豺狼猛兽，
极难见到半个人影。
LONG);

        num=random(3)+4;  
        set("outdoors", "fangzhudao");
        set("exits", ([ /* sizeof() == 4 */    
                "east" : __DIR__"fangzhudao16",
        ]));
        set("objects", ([   
                __DIR__"npc/wolf" : 1,
                __DIR__"npc/tiger" : 1,
                __DIR__"npc/fox" : 1,
                __DIR__"npc/pig" : 1,
        ]));
  
        set("alternative_die",1); 
        set("fangzhuroom",1); 
//放逐岛房间标志，cmds npc 判断所需！
        set("npc_num",num);//自己可以设定！
        set_heart_beat(300);
        setup();
        setup2();
}

void init2()
{
}

void heart_beat()
{      
        reset();
}

/* 以下是更新时间、 内容的设定*/
void reset() 
{
        object guai;
        int i;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;i<this_object()->query("npc_num");i++) { 
                                guai = new("/d/quest/fangzhudao/npc/"+list[random(sizeof(list))]);
                                guai->move(this_object());
                        }
                }
        }
        ::reset();
}
