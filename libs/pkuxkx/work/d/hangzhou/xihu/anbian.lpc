// /d/hangzhou/anbian
//  by hubo

#include <ansi.h>
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";

void create()
{
        set("short", "西湖岸边");
        set("long", @LONG
这里是西湖的一个小码头，岸边停靠着一只小船(boat)，从这里坐船可以到
湖中心的小岛，据说这里就属于红花会的领地了。凡事都要小心呀。
LONG
        );

        set("outdoors", "hangzhou");
        set("exits", ([
                "west" : __DIR__"suti2",
				"east" : __DIR__"xihu",
        ]));

        set("item_desc", ([
        "boat" : "这是一只结实的小船，能够经得起一般的风浪。船用绳索"
                "拴着，似乎可以走进去看看。\n",       
        ]));

      //  set("objects", ([
      //         __DIR__"npc/chuanfu" : 1,
      //  ]));

        set("navigate/locx", 0);
        set("navigate/locy", 0);

        set("cost", 2);

        setup();
}
void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object me;
    object *inv;
    int i;
    me = this_player () ;

        if(arg!="boat") {       return 0;       }
                inv=all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                                return notify_fail("你负重太大了，小舟恐怕载不动你。\n");
                }
         message_vision("$N从踏板上走上了船。\n",me);
         message_vision("船夫把踏脚板收起来，说了一声“坐稳喽”，船桨一点，小船向湖心驶去。\n",me);
         me->move(__DIR__"boat") ;
         call_out("wait4", 5 , me );
         return 1 ;
}
void wait4(object me)
{

		if (base_name(environment(me)) != __DIR__"boat") return;
        message_vision("船夫对$N说道：“到了，上岸吧。”，随即把一块踏脚板搭上堤岸。\n",me);
        message_vision("$N沿着踏板走了上去。\n",me);
        me->move (__DIR__"huxindao") ;
}
