// Room: /d/emei/shandong14.c 山洞14
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "山洞");
	set("long", @LONG
你从黑暗中走了出来，顿觉得视野十分的开阔，这里是一个宽大的山
洞，两边各插了一只火把(fire)，照的如同白昼一般，在前面有一个巨大
的石门紧紧关闭着，阻住了去路。
LONG
	);
        set("exits", ([
           "west":  __DIR__"shandong13",
	]));
       set("item_desc", ([
           "fire" : "一只燃烧正旺的火把。好象可以试着(pull)。\n",
          ]));
	setup();
}
void init()
{
    add_action("do_pull", "pull");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"shanpo")) )
        room = load_object(__DIR__"shanpo");

    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "只听轰的一声巨响，石门又从新合了起来。\n",
            this_object());
        room->delete("exits/west");
        if (objectp(room))
           message("vision", "只听轰的一声巨响，石门又从新合了起来。\n", room);
     }
}

int do_pull(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("石门已经是开着了。\n");

    if (!arg || (arg != "fire"))
        return notify_fail("你要拉什么？\n");

    if(!( room = find_object(__DIR__"shanpo")) )
        room = load_object(__DIR__"shanpo");
    
    if(objectp(room))
    {
        set("exits/east",__DIR__"shanpo");
        message_vision("$N用劲向外拉了一下火把，"
            "只听吱吱几声轻响，石门慢慢的打开了。\n",this_player());
        room->set("exits/west", __FILE__);
        message("vision", "不远处传来了几声轻响，在前面突然出现了一个洞口。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}
