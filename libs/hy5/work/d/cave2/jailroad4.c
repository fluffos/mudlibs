 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "地道尽头");
        set("long", @LONG
石壁上生满了盘旋纠缠的青苔，尽掩了山石的颜色。 
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad3", 
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()
{
        add_action("do_push", "push");
} 
int do_push(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"mouseroom1");
        message_vision("这片青苔长得最密，但却有大半已枯死，拨开青苔，就露出一个黑黝黝的洞穴，里面连
光都瞧不见。\n",me);
        tell_object(me,"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n");
        me->move(room);
        return 1;
}     
