 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","大观峰");
  set("long",@LONG
说是峰，其是一段崖壁，壁前一块平坦开阔的石坪，壁上琳
琅满目的摩崖石刻使无数游人留步驻足，其中《纪泰山铭》碑，
相传为唐玄宗手书，洋洋千言，字体俊逸雄浑，开书法唐隶一格
被誉为“自汉以来碑碣之雄壮未有及者”。
LONG
  );
  set("exits",([
        "southwest" : __DIR__"bixia",
               ]));
        set("outdoors", "taishanfy");
        set("objects", ([
        "/d/taoyuan/npc/rabbit": 2,
        ]) ); 
        
        set("coor/x",335);
        set("coor/y",2395);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}
