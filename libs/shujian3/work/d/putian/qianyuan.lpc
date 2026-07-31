// Room: /d/putian/qianyuan.c 前院
// lklv 2001.7.21

inherit ROOM;
void create()
{
        set("short", "前院");
        set("long", @LONG
这是山门内的一个大院子，很空荡，地上整齐的铺着一块块条石。靠近院
子的东南角，放有一个兵器架，上面整齐的摆着各式兵器。几个身穿灰布的僧
人正在一边练武。另外有几个身着青布僧衣的僧人，手里拿着大扫帚在低着头
扫地。闻名武林的莆田少林寺，看来似乎也很普通。
LONG
        );

        set("exits", ([
                "south" : __DIR__"cb-dian",
                "east" : __DIR__"xiaoyuan2",
                "west" : __DIR__"xiaoyuan3",

        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "福州");
        setup();
}
void init()
{
        add_action("do_open", "open");
        add_action("do_open", "kai");
        add_action("do_close", "close");
}

void close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"shanmen")) )
                room = load_object(__DIR__"shanmen");
        if(objectp(room))
        {
                delete("exits/north");
                        message("vision", "僧兵上前把大门关了起来。\n", this_object());
                room->delete("exits/south");
                message("vision", "乒地一声，里面有人把大门关上了。\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/north"))
                return notify_fail("大门已经是关着的了。\n");

        if (!arg || (arg != "gate" && arg != "north"))
                return notify_fail("你要关什么？\n");

        message_vision("$N朝僧兵点了点头。\n", this_player());

        remove_call_out("close_gate");
        call_out("close_gate", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/north"))
                return notify_fail("大门已经是开着了。\n");

        if (!arg || (arg != "gate" && arg != "north"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"shanmen")) )
                room = load_object(__DIR__"shanmen");
        if(objectp(room)){
                set("exits/north", __DIR__"shanmen");
                message_vision("$N使劲把大门打了开来。\n", this_player());
                room->set("exits/south", __FILE__);
                message("vision", "吱地一声，里面有人把大门打开了。\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
}

string look_gate()
{
        return "一道三丈来高的朱红杉木包铜大门。\n";
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && me->id("seng bing")) return 0;
        return ::valid_leave(me, dir);
}

