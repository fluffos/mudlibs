 inherit ROOM;
void create()
{
        set("short", "谷地");
        set("long", @LONG
只见四下流泉白石，奇松异草，将这四山环绕的谷地，点缀得有如神仙世
界一般。林木流水之间，点缀著许多栋飞檐凤阁，及一些假山亭台，一条石板
缀成的道路，宛延通向前方。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house",
  "west" : __DIR__"garden3",
]));
        set("outdoors", "palace"); 
        set("coor/x",280);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}       
