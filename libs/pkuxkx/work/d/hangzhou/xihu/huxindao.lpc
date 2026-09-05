// Room: /hangzhou/huxindao.c
// hubo 2008/4/19

inherit ROOM;
void create()
{
        set("short", "湖心岛岸边");
        set("long", @LONG
这是西湖的湖心岛岸边，南北有曲桥相通，东西以土堤相连桥堤呈“十”字
形交叉，将岛上水面一分为四水面外围是环形堤埂。从空中俯瞰，岛上陆地形如
一个特大的“田”字，呈现出湖中有岛，岛中有湖，水景称胜的特色在西湖十景中
独具一格，为江南水上园林的经典之作。目前，据说已被红花会所占据。  
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "west" : __DIR__"zhulin1",
       
]));
          
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
        me->move (__DIR__"anbian") ;
}
