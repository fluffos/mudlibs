 inherit ROOM;
void create()
{
        set("short", "危崖");
        set("long", @LONG
黄土路渐渐被杂草荆棘所覆盖。四周都是一人多高的荆棘，几只斑鸠咕
咕地叫著，在荆棘的空隙间跳来跳去。环绕四周，你发现你站在危崖之上。
向下看，隐约可见一潭湖水泛著粼光。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"npc/yellowman" : 2,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",220);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",220);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
}
