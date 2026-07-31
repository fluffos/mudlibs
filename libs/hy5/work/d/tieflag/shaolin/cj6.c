 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
满屋子灰尘，似乎久已无人上来，屋顶是精钢所铸，楼下有藏经楼
首座护卫，便是蝼蚁也难进入，四周墙壁上皆是梵文经卷，相传为当年
觉远大师梦游天竺佛祖亲授。是武学之中的不二法门。
LONG
        );
        set("exits", ([ 
  "down": __DIR__"cj5",
]));
        set("objects", ([
                __DIR__"npc/killera" : 1,
                __DIR__"npc/killerb" : 2,
                __DIR__"obj/xisuihe" : 3,
       ]) );
        set("coor/x",-210);
        set("coor/y",360);
        set("coor/z",120);
        set("no_magic",1);
        setup(); 
}     
