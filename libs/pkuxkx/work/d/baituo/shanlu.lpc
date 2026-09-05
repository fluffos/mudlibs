inherit ROOM;
void create()
{
     set("short","山路");
     set("long",
             "这是一条通往山上的泥路，你脚下滑滑的，很不好走，不知道这\n"
         "条路是通向哪里的，也没有人修一修！\n"   
        );
     set("exits",([
            "northwest" : __DIR__"shanlu1",
            "southeast" : __DIR__"guangchang",
                 ]));
     set("outdoors", "baituo");
     setup();
     replace_program(ROOM);
}
