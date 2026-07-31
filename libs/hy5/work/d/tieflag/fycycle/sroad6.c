 inherit ROOM;
void create()
{
        set("short", "城南小路");
        set("long", @LONG
北边就是高大的风云城，向东是一条宽阔的马路，一直通向大海。
马路上人来人往，热闹非凡。都是些江湖儿女，面带严肃，赶去为紫
衣侯大战白衣人加油去的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
  "east" :      __DIR__"fyeast",
  "southwest": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
       set("coor/x",100);
        set("coor/y",-10);
        set("coor/z",0);
 
        set("coor/x",100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();      
}       
