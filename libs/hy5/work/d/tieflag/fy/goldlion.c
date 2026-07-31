inherit ROOM;
void create()
{
        set("short", "金狮镖局大院");
        set("long", @LONG
这里几十年来几乎没有什么变化，黑石铺地，大院右边零乱的放着一些大小不
一的石锁，想必是镖局中的趟子手用来练臂力的。左侧则是碗口粗细一人多高的梅
花桩。总镖头查猛是少林俗家弟子出身，虽然教出的徒弟不怎么样，但是他的轻功
和掌法都已经炉火纯青了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwind4",
  "east"  : __DIR__"ghall", 
  "north" : __DIR__"gcang",
  "south" : __DIR__"gkitchen",
]));
        set("objects", ([
        __DIR__"npc/biaoshi" : 1,
        __DIR__"npc/biaoshi1": 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",40);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
