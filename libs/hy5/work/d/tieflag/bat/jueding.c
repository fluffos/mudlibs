 inherit ROOM;
void create()
{
        set("short", "孤峰绝顶");
        set("long", @LONG
海风劲吹。天下尽在眼底，这才是人间的绝顶。
只有举世无匹的高手才能登上这里，但是高处不胜寒！
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"renjiandao3",
]));
        set("outdoors", "bat");
        set("objects", ([
        __DIR__"npc/baiyiren": 1,
                        ]) ); 
        set("coor/x",3290);
        set("coor/y",40);
        set("coor/z",50);
        setup();
}  
