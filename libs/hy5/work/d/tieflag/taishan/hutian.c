 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","无极庙");
  set("long",@LONG
无极庙由山门、正殿、东西配殿和禅房组成。山门联曰：“天台岩下
藏五百，须弥顶上隐三千。”院内石筑正殿三间，门额“太虚灵妙”，楹联称：
“玉楼琼华高山阆苑，青琳翠水俯视昆仑。”东间前窗额称：“泰岳仙宗”，联
语：“涵阴育阳，两仪之始；开天辟地，万法所宗。”西窗额“乾坤正体”，联
曰：“普降甘霖，慈云垂荫；宏开觉路，宝月增辉。”正殿前有东西配殿各三
间，西院为禅房院，有西屋、南屋各三间。
LONG
  );
  set("exits",([
        "down" : __DIR__"doumu",
        "up" : __DIR__"butian",
        "northeast" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}     
