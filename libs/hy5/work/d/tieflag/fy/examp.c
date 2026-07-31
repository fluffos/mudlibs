 inherit ROOM;
void create()
{
        set("short", "考场");
        set("long", @LONG
风云城人才辈出，凡是有志于宦途的风云年青人都要在这里通过第一次考试。
文武双全的前三名会被送入京都再试。风云的老一辈大多是望子成龙，每到一年一
度的考季，这里就会人山人海，看热闹的比参考的还多。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/kaoguan" : 1,
        __DIR__"npc/student" : 3,
                        ]) ); 
        set("coor/x",-10);
        set("coor/y",-1);
        set("coor/z",0);
        setup();
}      
