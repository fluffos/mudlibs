// diaoyuchi.c
inherit ROOM;
void create()
{
        set("short", "钓鱼池");
        set("long", @LONG
这里是一个小小的水池，旁边有不少的人正在垂钓，哇！你身
边的老哥居然钓上来一条几斤重的大鲤鱼啊。还发什么呆啊，你旁
边还放着几根钓鱼杆，快点钓（fish）吧。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"path5",
]));
        set("roomlevel","1");setup();
}
void init()
{
        add_action("do_fish", "fish");
}

int do_fish()
{
        object me;
        //, fish;
        int i, kar, cps, bb;
        me = this_player();
        if(me->is_busy())
             return notify_fail("你还是等鱼饵换好了在放杆吧！\n");
        if(me->query("qi")<10)
             return notify_fail("你还是先休息一下吧，生命是第一位的。\n");
         if (me->query("combat_exp") > 35000)
             return notify_fail("你已经不能通过钓鱼增加经验了。 \n");
        me->start_busy(2);
//        call_out("fliping",1,me);
        message_vision("$N拿起一根钓鱼杆坐在大石头上钓起鱼来……\n", me);
        for (i=0; i<200000; i++) ;
        message_vision("$N只见鱼漂猛然一动，急忙提杆…\n",me);
        kar = me->query("kar");
        cps = me->query("cps");
        if (random(kar+cps)>((kar+cps)/10)*9) {
                message_vision("$N钓到一条红鳟鱼\n", me);
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N得到了0点经验\n",me);  
                }
                else
                {
                 bb=(int)me->query("combat_exp");
                 me->set("combat_exp",3+bb);
                 message_vision("$N得到了3点经验\n",me);  
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000 )
                {
                 message_vision("$N得到了0点潜能\n",me);
                }
                else
                {
                 me->set("potential",bb+3);
                 message_vision("$N得到了3点潜能\n",me);
                }
//              fish = new("/u/c/ckj/npc/obj/fish1");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/5)*3) {
                message_vision("$N钓到一条白鲳鱼\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>40000 )
                {
                 message_vision("$N得到了0点经验\n",me);
                }
                else
                {
                 me->set("combat_exp",2+bb);
                 message_vision("$N得到了2点经验\n",me);
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N得到了0点潜能\n",me);
                }
                else
                {
                 me->set("potential",bb+2);
                 message_vision("$N得到了2点潜能\n",me);
                }
//           // fish = new("/u/c/ckj/npc/obj/fish2");
//           // fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/3)*2) {
                message_vision("$N钓到一条大鲤鱼\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N得到了0点经验\n",me);
                }
                else
                {
                 message_vision("$N得到了1点经验\n",me);
                 me->set("combat_exp",1+bb);
                } 
                me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>40000)
                {
                 message_vision("$N得到了0点潜能\n",me);
                }
                else
                {
                 me->set("potential",bb+1);
                 message_vision("$N得到了1点潜能\n",me);
                }
//           // fish = new("/u/c/ckj/npc/obj/fish2");
//           // fish->move(me);
                return 1;
        }
         else
               me->receive_damage("qi", 10);  
               message_vision("$N什么也没钓到。\n",me );
        return 1;}