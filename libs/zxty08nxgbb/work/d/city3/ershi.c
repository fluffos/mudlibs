
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "赌神再世");
        set("long", @LONG
这里是赌二十一点的地方。有个很酷的帅哥在那里坐着，嘴
里不停地嚼着什么，他带着副墨镜，一副很冷静的样子。墙上也
贴着规则说明(rule)。
LONG
        );

        set("exits", ([
                "west" : __DIR__"daxiao",                
        ]));
        set("no_fight",1);

        set("item_desc",([
             "rule" : "这里玩的是世界流行的二十一点，10、\n"+
                      "J、Q、K都算十点，A算十一点，每次限\n"+
                      "压二两黄金，祝你好运！:)\n"
                 ]));
        set("objects",([
                __DIR__"npc/fazai" : 1,
        ]));

                            
        setup();
        replace_program(ROOM);
}


 
