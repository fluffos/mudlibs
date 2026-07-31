inherit ROOM;
void create()
{
        set("short", "棉花坊");
        set("long", @LONG
每当天气渐冷，风云老少都会到这儿来将自己的冬衫，冬被弹一弹，这里的老
板娘更善长补衣服，补出来的衣服不但牢固，而且总是恰到好处地绣朵花，打个褶
儿什么的，一点儿也看不出补过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud4",
]));
        set("objects", ([
            __DIR__"npc/mianhua" : 1,
                        ]) ); 
        set("coor/x",40);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
