// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "山谷");
        set("long", @LONG
这里是五毒教的的禁地，四周种满了各种草本花木，浓郁的花香让你感到
晕玄。几名五毒教弟子奉命在这里看守。
LONG
        );

        set("exits", ([
              "out" : __DIR__"slu9",
               
             ]));
        set("objects", ([
                 __DIR__"npc/jiaozhong" : 2,
             ]));
        set("outdoors", "miaojiang");
        set("ling_count", 2);
        set("jin_count", 2);
        setup();
}
void init()
{
        add_action("do_wa", "wa");
        add_action("do_shao", ({ "shao", "shao" }));
} 
int do_wa(string arg)
{ 
        object lan;
        object me;
        me = this_player();
        if (!( present("xiao tiechan", this_player())))
        return notify_fail("用手挖，不怕中毒！\n");
        if ( !arg || arg != "hua" )
            return notify_fail("你要做什麽？\n");
        if (query("ling_count") > 0) 
       {
        message_vision("$N拿起铁铲，小心翼翼的挖出一株灵脂兰。\n",me);
        add("ling_count", -1);
        lan=new(__DIR__"obj/lian");
        lan->move(__DIR__"shangu1",);
      me->set_temp("mark/挖",1);
        me->add("jingli",-100);
        }
        else
       message_vision("$N发现这里已经被人挖过了。\n", me);
        return 1;
}
int do_shao(string arg)
{
     object jinshe,yinshe;
    object me=this_player(), ob;

    if((!arg) || (arg != "lingzhi lan"))
        return notify_fail("你要做用什么？\n");
    if( !(ob=present("fire", me)) )
      return notify_fail("你没有点火之物！\n");
    if( !(ob=present("lingzhi lan", me)) )
        return notify_fail("你要烧什麽！\n");
          if (query("jin_count") > 0) 
          {
        message_vision("$N点燃灵脂兰，四下里一下散发着阵阵檀香。$N忽然看到
从灌木里钻出两条奇怪的小蛇。\n", me);
         add("jin_count", -1);
         jinshe=new(__DIR__"npc/jinshe");
         jinshe=new(__DIR__"npc/yinshe");
 
         me->add("jingli", -200);
         jinshe->move(__DIR__"shangu1",);
         yinshe->move(__DIR__"shangu1",);
          }
        else
         message_vision("$N等了半天，什麽也没有发现。\n", me);
         return 1;
//         destruct(ob);
         return 1;
}
