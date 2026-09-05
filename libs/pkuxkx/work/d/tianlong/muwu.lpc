// /d/dalicheng/muwu
inherit ROOM;

void create()
{
    set("short", "松木屋");
    set("long", @LONG
这间屋全以松木拾成，板门木柱，木料均不去皮，天然质朴，
和一路行来金碧辉煌的殿堂截然不同。
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "east" : __DIR__"changlang2",
                ]));
    set("objects", ([
                __DIR__"npc/benguan" : 1,
                CLASS_D("tianlong")+"/kurong" : 1 ,
                ]) );
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

