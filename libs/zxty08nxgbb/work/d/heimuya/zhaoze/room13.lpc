// Room: room13.c
inherit ROOM;
string* npcs = ({
    "/d/shenlong/npc/jinshe",
    "/d/shenlong/npc/qingshe",
    "/d/shenlong/npc/jinshe",
    "/d/shenlong/npc/qingshe",
    "/d/shenlong/npc/fushe",
}); 
void create()
{
        set("short", "森林");
        set("long", @LONG
前面根本没有路，四周的密林中长满了杂草(weed)，荆棘密布。
浓密宽厚的树叶遮蔽了日月星辰，使人分不出昼夜。四下如死一般的
寂静，只有风吹过树梢的沙沙之声。
LONG
        );

    set("exits", ([
        "east" : __DIR__"room12",
    ]));

    set("item_desc", ([
        "weed" : "这片杂草太深了,要想过去恐怕只有砍出一条路了(kan)。\n",
    ]));
        set("objects", ([
    "/d/shenlong/npc/dushe" : 1+random(2),
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    ]) );

        setup();
}
void init()
{
    add_action("do_kan", "kan");
}
int do_kan ( string arg )
{
    object weapon;
    if( !arg || arg !="weed" ) 
         return notify_fail("你要砍什么？\n" ) ;
    if (!objectp(weapon = this_player()->query_temp("weapon")))
        return notify_fail("不用武器恐怕不行吧！\n");
        message_vision(
        "$N抽出兵刃,对着杂草一阵乱砍。\n", this_player());
        if(this_player()->query("neili")>100)
    {
        set("exits/north", __DIR__"room16");
        message_vision(
        "$N累得气喘吁吁,终于砍出一条小路。\n", this_player());
        this_player()->add("neili",-50);
        remove_call_out("close");
        call_out("close", 20, this_object());
    }
        else    
    {
        message_vision(
        "$N累得气喘吁吁,也没砍开一条路来。\n", this_player());
    this_player()->set("neili",0);
    }
return 1;
}
void close(object room)
{
    message("vision","杂草渐渐合拢起来,终于又恢复了原状。\n", room);
    room->delete("exits/north");
}
