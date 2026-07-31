 inherit ROOM;
void create()
{
        set("short", "三清湖");
        set("long", @LONG
湖水清澈透明，不时可以看到几尾鱼跳上水面。湖水尽头
是一个大瀑布。在这里可以听到瀑布从山上直冲而下，发出的
轰轰雷声。湖边一块巨石，上写＂三清湖＂。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"grassland1",
                "north" : __DIR__"lake2",
                ]));
         set("objects", ([ 
                __DIR__"npc/watcher_taoist" : 1,
                __DIR__"npc/feng" : 1,
                ]));
 
        set("resource/water",1);
        set("liquid", (["container":"湖"]));
        set("outdoors", "taoguan");
        set("coor/x",-10);
        set("coor/y",2070);
        set("coor/z",80);
        setup();
}       
