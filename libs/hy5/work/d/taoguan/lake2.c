 inherit ROOM;
void create()
{
        set("short", "三清湖");
        set("long", @LONG
湖水清澈透明，不时可以看到几尾鱼跳上水面。湖水尽头
是一个大瀑布。在这里可以听到瀑布从山上直冲而下，发出的
轰轰雷声。湖边稀稀落落地站着几个道人。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"grassland2",
                "south" : __DIR__"lake1",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 2,
                __DIR__"npc/shan" : 1,
                
]));
        set("resource/water",1);
        set("liquid", (["container":"湖"]));
        set("outdoors", "taoguan");
        set("coor/x",-10);
        set("coor/y",2080);
        set("coor/z",80);
        setup();
}   
