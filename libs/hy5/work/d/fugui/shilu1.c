 inherit ROOM;
void create()
{
        set("short", "青石巷"); 
        set("long", @LONG
这是条青条石砌成的小巷，比起吉祥镇的小街宽敞了不少，倒也还算平整，路
旁两排楠木树修剪地整整齐齐，时不时还有几辆四轮的马车沿路飞快的冲入巷子。
LONG);
        set("outdoors", "fugui");
        set("type","road");
        set("exits",([
                "west":__DIR__"xiaojie4",
                "northeast":__DIR__"shilu2",
        ]) );
        set("item_desc", ([
                "tree": "这是棵高大的楠木树，枝叶茂盛，似乎都伸进了金大帅府。\n",
        ]) );
        set("coor/x",-570);
        set("coor/y",90);
        set("coor/z",0);
        setup();
} 
void init ()
{
        add_action ("do_climb", "climb");
} 
int do_climb (string arg)
{
        object me,room;
        int dodge;
        if (!arg || (arg != "tree" && arg != "树"))
                return notify_fail("你要爬什么？\n");
        me = this_player();
        dodge = me->query_skill("dodge");
        if (dodge < 40)
                return notify_fail("树太高了，你爬不上去。\n");
        message_vision("$N吸了口气，手足并用，慢慢的爬上路边的大树。\n",me);
        room = find_object(__DIR__"tree");
        if(!room)
                room=load_object(__DIR__"tree");
   me->move(room);
        message("vision",me->name()+"从树下爬了上来。",room,me);
        return 1;
}
