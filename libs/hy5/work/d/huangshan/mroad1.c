 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
耳边还回响着轰鸣的水声，你似乎还可以在空气中闻到瀑布的气息，然而到这
里你已然看不到水流，四周苍松翠柏，一片生机绿意盎然，间或几株艳丽的野花点
缀其间，增加些色彩，脚下青石台阶逐级而上，依山势曲折盘环。       
LONG
        );
    set("exits", ([ 
                "northup" : __DIR__"jiulong",
                "southeast" : __DIR__"baizhang",
        ]));
        set("item_desc", ([
         ]) );
    set("outdoors", "huangshan");
    set("coor/x",-550);
        set("coor/y",-490);
    set("coor/z",10);
        setup();
}
void init() {
        object me;
        me = this_player();
        call_out("turtle_move", random(10), me);
        add_action("do_search", "search");
} 
int turtle_move(object me) {
        if (environment(me) == this_object()  && !me->query("stone_mark/gstone")) {
                if(me->query("marks/无悔") && !present("green turtle", this_object()) && !random(20)) {
                        tell_object(me, "花草丛中似乎有什么慢慢动了一下，你以为自己眼花了。\n"); 
                        me->set_temp("marks/search_turtle", 1);
                        return 1;
                }
        }  
  return 1;     
}
int do_search() {
        object me, ob;
   
        me = this_player();
        if (!me->query_temp("marks/search_turtle")) {
                return 0;
        }
        message("vision", me->name() + "在草丛中仔细寻找。\n", environment(me), me);
        tell_object(me, "你拨开草丛仔细寻找，竟然发现一只背壳上生满细细绿毛乌龟在慢慢爬。\n"); 
        me->delete_temp("marks/search_turtle");
        ob = new(__DIR__"npc/turtle");
        if(objectp(ob)) {
                ob->move(this_object());
        }
        return 1;
}       
