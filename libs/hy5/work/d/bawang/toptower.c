 inherit ROOM;
void create()
{
        set("short", "断塔顶"); 
        set("long", @LONG
这里是断塔顶，一盏黄油纸灯笼，用竹竿斜斜挑起。竹竿插在断墙里，灯笼不
停地摇晃。昏暗的灯光下有三个人，一个衰老佝偻的残废人，阴暗丑陋的脸上满是
刀疤。一个中年锦衣大汉，另一个则是个很高大的黑衣人。 
LONG); 
        set("type","street");
        set("exits",([
                "down":__DIR__"broketower5",
        ]) ); 
        set("objects", ([
                __DIR__"npc/baili_changqing": 1,
                __DIR__"npc/deng":1,
                __DIR__"npc/hu_5":1
        ]));
        set("indoors", "bawang");
        setup(); 
    set("coor/x",200);
    set("coor/y",-210);
    set("coor/z",60);
        replace_program(ROOM);
}    
