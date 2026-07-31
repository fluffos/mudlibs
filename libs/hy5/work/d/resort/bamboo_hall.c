 inherit ROOM;
void create()
{
        set("short", "翠竹屋");
        set("long", @LONG
青青的软竹搭成小小的翠竹屋。屋中几乎所有的家具都是用青
竹编成的。屋中的竹几上放着一套名贵的紫砂茶具。铁雪山庄的男
女主人正在品茶下棋。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"front_yard",
  "north" : __DIR__"back_yard",
  "west" : __DIR__"teagarden",
  "east" : __DIR__"restroom",
]));
       set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
        set("coor/x",-1230);
        set("coor/y",60);
        set("coor/z",-10);
        setup();
}
int valid_leave(object me, string dir)
{
        object ob;
    if( me->query("class") != "legend" && (dir == "east"|| dir== "west")) {
        if(ob=present("master tieshao", this_object())){
                return notify_fail("铁少微微皱了皱眉。\n\n这个方向的路被"+ob->name()+"挡住了 。\n");
                } else if(ob=present("master xuerui", this_object())){
                        return notify_fail(ob->name()+"柳眉微蹙。\n\n这个方向的路被"+ob->name()+"挡住了 。\n");
                }
        }
        return 1;
}  
