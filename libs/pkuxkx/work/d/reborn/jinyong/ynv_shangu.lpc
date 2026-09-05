inherit ROOM;
int do_dig();
void create ()
{
  set ("short", "山谷");
  set("long", @LONG

好大的一个山谷，远远看去，郁郁葱葱望不到边。山谷的东边有一片碧绿的湖泊，白云的影
子倒影在湖面上，像是天蓝色的绸缎上面绣了几多白色的花，真似那人间仙境一般。湖边是
一片开着野花的草地，一位碧衣女子在练剑。
LONG);
        set("exits",([
                "southup": __DIR__"ynv_shanpo",
                ]));
        set("objects", ([
                __DIR__"npc/ynv_yuenv" : 1,
                "/d/ludingshan/obj/misc/haitang":1,
                ]));
        set("book_count",1);
        set("outdoors", "sz");
 setup();
}
void init()
{
        add_action("do_dig", "dig");
}
int do_dig()
{      
       object ob, me= this_player();
       if (query("book_count") < 1)
           return notify_fail("你挖了半天什么都没挖到。\n");
       ob = new("/d/reborn/jinyong/obj/ynj");
       ob->move(me);
       message_vision("$N在地上刨了半天，挖到一个盒子，打开一看，正是一本《越女剑》。\n", me);
       add("book_count",-1);
       return 1;       
}
