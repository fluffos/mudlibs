//Writen by lnwm
//lroad4.c

inherit ROOM;

void create()
{
    set("short", "小泥路");
    set("long", @LONG
你走到了村子的中心，这里是整个村子最热闹的地方，东边是一个小
草棚，西边是一家农舍。到了傍晚收工以后，村民们会三三两两聚集在这
里摆摆龙门阵，这也是他们一天最快乐的时光。
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad2",
        "north"         :       __DIR__ "lroad5",
        "east"          :       __DIR__ "caopeng",
        "west"          :       __DIR__ "nongjia2",              
                ]));
    set("objects",([
                __DIR__ "npc/yunyou" : 1,
                  ])
    );  
    setup();
    replace_program(ROOM);
}


