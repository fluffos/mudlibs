#include <ansi.h>
inherit ROOM;
//inherit HARBOR;

void create()
{
        set("short", "海岸");
        set("long", @LONG
由于很少人来这，所以知道这是一个出海口的人很少。海边的
风光也不是很好，所以过往的人们也是不在意这个毫不起眼的地方。
向外望去是一望无际的大海(sea),南面就是泉州城的五里街，那里
还算是比较繁华的地方，岸边有一只小木船(boat)。岸的西边有一
座小木屋，木屋顶上一对白雕(diao)。原来这里是桃花岛为方便弟
子回岛而特意建起的。
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"wulijie1",
        ]));

        set("item_desc", ([
        "sea" : "近岸处有一只小船，想渡船也许得问一下岸边的船夫。\n",
        "boat" : "这是一只结实的小船，能够经得起一般的风浪。船用绳索"
                "拴着，似乎可以走进去看看。\n",
        "diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
                  "骑上(ride)就可以飞回桃花岛。\n",        
        ]));

        set("objects", ([
               __DIR__"npc/chuanfu" : 1,
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", 0);

        set("cost", 2);

        setup();
}
void init()
{
    add_action("do_ride", "ride");
    add_action("do_enter", "enter");
}
int do_ride(string arg)
{
        object me;
        object *inv;
        int i;
        me = this_player();

        if (arg=="diao")
        {
           if (me->query("family/family_name")!="桃花岛" && !wizardp(me))
           {
                 message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠......\n"
                      HIR "结果$N摔了个鼻青脸肿！\n" NOR
                     "看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n" , me ) ;
                 return 1;
           }
           else
           {
                inv=all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                                return notify_fail("你负重太大了，白雕恐怕载不动你。\n");
                }
               message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"
                   "但看一雕一人身形渐渐缩小，终至不见。\n" , me );
               tell_object(me, CYN  "\n你不断地飞呀飞，万水千山身下飘过 ......\n\n" NOR ) ;
               tell_object(me, "你终于飞到了桃花岛，白雕落了下来。\n\n");
               me->move("/d/taohuadao/haigang1");
                return 1;
            }
        }
        return 0;
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
         message_vision("船夫把踏脚板收起来，说了一声“坐稳喽”，船桨一点，小船向东海驶去。\n",me);     
         me->move("/d/taohuadao/boat") ;
         call_out("wait4", 5 , me );
         return 1 ;
}
void wait4(object me)
{
		if (!me) return;
        message_vision("船夫对$N说道：“到了，上岸吧。”，随即把一块踏脚板搭上堤岸。\n",me);
        message_vision("$N沿着踏板走了上去。\n",me);
        me->move ("/d/taohuadao/haigang1") ;
}


