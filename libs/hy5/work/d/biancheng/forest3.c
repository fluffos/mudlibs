 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "密林");
        set("long", @LONG
密林里一片漆黑，绝无树叶触擦的声音，也绝无夏夜的那种半明半昧的清光。
高大的杈丫狰狞张舞。枯萎丛杂的矮树在林边隙地上瑟瑟作声。长大的野草在寒风
中鳗鲡似地蠕蠕游动。蓁莽屈曲招展，有如伸出了长臂，张爪攫人。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"forest2",
                "southeast":    __DIR__"village",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1050);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "southeast"){
                if (present("bandit", this_object()))
                {
                        another = present("bandit", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>5) {
                        another = new(__DIR__"npc/bandit");
                        another->move(environment(obj));
                        message_vision(HIB"树叶哗啦啦一阵乱响，跳下一个人来！\n"NOR, obj);      
                        return notify_fail(another->name()+"喝道，什么人敢私闯我龙虎寨，拿命来！\n");
                }
        }       
        return 1;
}    
