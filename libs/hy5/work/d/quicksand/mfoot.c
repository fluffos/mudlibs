 inherit ROOM;
void create()
{
        set("short", "山脚");
        set("long", @LONG
沙漠到了这里似乎已经被西边的山冈挡住了。无论狂风怎么吹，大漠也
不向西扩展一步。这里虽然也是光秃秃的，可是已经不再有灼人的酷热。几
株被风刮来的滚草已经在这里扎下根来。翻过这座山就是塞外人居住的地方。
西北方向则是条不见尽头的沙道。。。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"desert10",
  "northwest" : __DIR__"skyroad1",
  "west" : __DIR__"mroad",
]));
        set("outdoors", "quicksand"); 
        set("coor/x",-1110);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
