// ROOM : biguan.c
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","闭关室");
  set("long",@LONG
这是天山童姥闭关修练的地方，只见一个身材娇小, 貌如处子的十八
九岁的女子盘膝而坐，她就是闻名天下的天山童姥。如果不是她的亲传弟
子，千万不要轻易打搅。
LONG
    );
  set("exits",([
      "south" : __DIR__"men3",
     ]));
  set("objects",([
                "/kungfu/class/lingjiu/tonglao" : 1,
     ]));
  set("lit_count", 3);
 setup();
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_search","search");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "tong lao") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "灵鹫宫" && me->query("family/fa
mily_name") != "灵鹫宫" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);

           if ( ob1=present("tong lao", environment(me)) ) {
                message_vision("$N一声冷笑：大胆狂徒！竟敢当着我的面行凶杀人，当我灵鹫宫好欺负么？\n", ob1);
                ob1->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           return 1;
} 
int do_search(string arg)
{

        object ob,  me = this_player();

        if( !arg || arg=="" ) return 0;
        
        if( arg != "yi jing" ) return 0;

        if( me->query("family/family_name") != "灵鹫宫" )
                return notify_fail("你在书架上找了找，却没有发现易经文学。\n");

        if ( query("lit_count") >= 1 && !me->query_temp("search/yijing") ) {
           ob = new("/d/lingjiu/obj/lit_book");      
           ob->move(me);
           add("lit_count", -1);
           CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了紫霞秘籍。", me->query("name")));
           me->set_temp("search/yijing", 1);
           write(HIW"你从书架上拿起一本易经文学小心的收好。\n"NOR);
        }
        else {
           write("你在书架上找了找，却没有发现易经文学,可能被别人拿光了。\n");
        }
   
        return 1;
}


