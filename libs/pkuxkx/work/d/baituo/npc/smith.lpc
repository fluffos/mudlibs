// smith.c
inherit NPC;
inherit F_DEALER;
string ask_yangzhou();
void create()
{
        set_name("张二楞", ({ "zhang tiejiang", "smith zhang", "zhang" }));
        set("long","这位就是在这方圆百里远近闻名的铁匠张二愣，虽说他人有些愣，\n可是打出的兵器确实都不错，价格又公道，也有不少主顾。");
        set("nick","铁匠");
        set("shen_type", 1);
        set("gender", "男性" );
        set("age", 33);
        set("long", "铁匠正用汗流浃背地打铁。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("vendor_goods",({
                   __DIR__"obj/dakandao",
                "/d/yuewangmu/obj/changqiang",
                "/d/yuewangmu/obj/hyqiang",
                "/d/city/obj/tiejia",
        }));
        set("inquiry", ([ 
                "扬州" : (: ask_yangzhou :),
                ]));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
string ask_yangzhou()
{
          object me=this_player();
          if (me->query_temp("baituo/go_yz"))
          {
          	tell_object(me,"张二楞左右看了看，低声说道：既然我钱大哥已经打了招呼，我就送你回去吧！\n");
          	me->delete_temp("baituo/go_yz");
          	tell_object(me,"张二楞把你沿小路送回了扬州。\n");
          	me->move("/d/city/qianzhuang");
          	return "最近生意还真多啊！嘿嘿....\n";
          }
          else return "扬州很远啊！你得有白骆驼才能过得去。\n";
}
