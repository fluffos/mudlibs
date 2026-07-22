// shishi3.c

inherit ROOM;
void create()
{
        set("short", "石室");
        set("long", @LONG
这里是一个极大的石室，比之外面的任何一个都大了数倍，室中一排排
地列满了木制成的书架(shelf)，室中还有一张小床(bed)。
LONG
        );
       set("exits", ([
               "south" : __DIR__"shidong",
       ]));
        set("item_desc",([
        "shelf":"\n书架上却空荡荡地连一本书也没有，走近看时，只见书架\n"
                "上贴满了“昆仑派”，“少林派”，“青城派”之类的条目，\n"
                "想象当年所列，皆是各门各派的武功秘籍。\n\n",
        ]));
        set("sleep_room", "1");
       setup();
}
void init()
{
        add_action("do_move","move");
        add_action("do_put","put");
}
int do_move(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="bed") return 0;
        message_vision("$N用力把小床移开，发现里面竟然有一条秘密通道！\n",me);
        me->move(__DIR__"midao1");
        tell_object(me,"接着是一阵轰隆隆的响声，你定神一看，自己已经处身在秘密通道中了。\n");
     return 1; 
}
int do_put(string arg)
{
        object me,ob;
        me = this_player();

        if ( me->query_temp("kejuan") ) {
        if (!objectp(ob=present("bo juan",me)))
            return notify_fail("你身上没有那样东西。\n");
        if( arg=="juan in shelf" || arg=="bo juan in shelf") {
            message_vision("$N将手中的"+ob->query("name")+"放回书架。\n",me);
            destruct(ob);
            message("vision","突然“轰隆”一声，书架由于年月太久，塌了下来。\n",this_object());
            message("vision", "帛卷也遂着书架掉在地上\n",this_object());
            me->delete_temp("kejuan");
            me->set_temp("duxiaowu", 1);
            new(__DIR__"obj/bojuan-xia")->move(this_object());
        return 1;
            }
      } else return notify_fail("书架都烂了，你放什么啊？\n");
      return 0;
}
