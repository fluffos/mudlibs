#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", "海港");
        set("long", @LONG
这是桃花岛的出海口，南面是海，向西是光秃秃的岩石，
东面北面是花树，五色缤纷，不见尽头，只看得头昏眼花。海
边有一艘小木船(boat)。 岸边有一对白雕(diao)。
LONG
        );

        set("outdoors", "taohua");
        set("exits", ([
                       "north"  : __DIR__"taolin1",
        ]));

        set("item_desc", ([
        "boat" : "这是一艘小木船。船虽小，但是依然可以承受得了一般的风浪。出海就靠这条船了。",
        "diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，骑上(ride)就可以飞回中原。\n",  
        ]));

        set("objects", ([
        ]));
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
               tell_object(me, "你终于飞到了中原，白雕落了下来。\n\n");
               me->move("/d/taohuadao/haian");
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
        me->move ("/d/taohuadao/haian") ;
}


