// Room: /d/emei/shanpo.c 山坡
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "山坡");
	set("long", @LONG
这里是玉女峰旁一处悬崖，向深谷中望去，只见蔼蔼白雾不时的上下翻滚
飘动，寒气逼人。在悬崖里面景色又是一变，山坡上张满了各色的花草，每当
清晨雾气过后，雨水打湿的花瓣，在朝霞的映照下显的格外的艳丽夺目。在你
的身旁正对的石壁上杂草丛生，不过隐约可以看到石壁左方凹陷处有一铁环。
LONG
	);
        set("exits", ([
           "down":  __DIR__"milin3",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *inv,room;
    mapping myfam;
    myfam = me->query("family");
    room = load_object(__DIR__"shandong14");
    inv = all_inventory(this_player());
     for(i=sizeof(inv)-1; i>=0; i--) {
    if( inv[i]->is_character() && dir == "west")
       return notify_fail("这里只能有一个人通过，你这样是过不去的。\n");
     }
   if ( (!(myfam = me->query("family"))) &&  dir == "down")
       return ::valid_leave(me,dir);
   if ( (!(myfam = me->query("family"))) || (myfam["master_name"] != "周芷若") && dir=="west")
     {
                remove_call_out("close_gate");
     if(objectp(room))
      {
        delete("exits/west");
        message("vision", "只听轰的一声巨响，石门又从新合了起来。\n",
            this_object());
        room->delete("exits/east");
        if (objectp(room))
           message("vision", "只听轰的一声巨响，石门又从新合了起来。\n", room);
     }
      return notify_fail("");
    }
    return ::valid_leave(me,dir);
   
}

void init()
{
    add_action("do_pull", "pull");
}

int close_gate()
{
    object room;
    if(!( room = find_object(__DIR__"shandong14")) )
        room = load_object(__DIR__"shandong14");

    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "只听轰的一声巨响，石门又从新合了起来。\n",
            this_object());
        room->delete("exits/east");
        if (objectp(room))
           message("vision", "只听轰的一声巨响，石门又从新合了起来。\n", room);
     }
}

int do_pull(string arg)
{
    object room;

    if (query("exits/west"))
        return notify_fail("石门已经是开着了。\n");

    if (!arg || (arg != "tiehuan"))
        return notify_fail("你要拉什么？\n");

    if(!( room = find_object(__DIR__"shandong14")) )
        room = load_object(__DIR__"shandong14");
    
    if(objectp(room))
    {
        set("exits/west",__DIR__"shandong14");
        message_vision("$N用劲向外拉了一下铁环，"
            "只听吱吱几声轻响，在石壁前出现了一个洞口。\n",this_player());
        room->set("exits/east", __FILE__);
        message("vision", "你面前的石壁传来了几声轻响，吱呀呀的被人打开了。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}
