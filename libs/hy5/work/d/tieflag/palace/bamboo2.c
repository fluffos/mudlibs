 inherit ROOM;
void create()
{
        set("short", "翠竹林");
        set("long", @LONG
这是一个竹子的世界，光线透过茂密翠绿的竹叶，仿佛都染上了淡淡的绿
色，一条小溪静悄悄地穿过这片竹林，似乎连流水都不忍破坏这里的宁静。在
这里你忘却了江湖的险恶，心里充满了宁静。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"bamboo3",
  "north" : __DIR__"bamboo",
]));
        set("outdoors", "palace");
        set("resource/water",1);
        set("coor/x",290);
        set("coor/y",-60);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}     
