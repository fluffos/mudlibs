//cool 98.4.18
#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_ti(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
	set("short", "西练武场");
	set("long", @LONG
这是间大大的房子，十分宽阔，不少人在这里汗流浃背的苦练着功夫，
地上有一些练武用的工具，墙角挂着一排大大的沙袋（shadai)，一些人正
在用沙袋练功。
LONG);
        set("outdoors", "武馆");
	set("exits", ([
	       "south" : __DIR__"wuchang1",
	       "north" : __DIR__"lang3",
        ]));
        set("item_desc", ([
	     "shadai"  :  "一个大沙袋，挂在柱子上，好象有很多用途，几个人在那里拍打(da)。\n",
	]));
        set("objects", ([
           __DIR__"npc/nvdz" : 1,
        ]));
	setup();
}

void init()
{
        add_action("do_da", "da");
}
int do_da(string arg)
{
        object me;
        int costj, costq;

        me = this_player();
        if (me->is_busy()) return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心练功！\n");
        if ( !living(me)) return notify_fail("你发疯了? \n");
        if( objectp( me->query_temp("weapon")) ) return notify_fail("只有空手才能打沙袋。\n");
        if ( !arg || arg != "shadai" ){    
            message_vision("$N伸出手指在空中乱戳乱比一通，好象在鬼画符！\n",me);
            return 1;
            }
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
             message_vision("$N用力过猛，一个不小心，头碰到了墙上！\n",me);
             me->unconcious();
             return 1;
             }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$N摆了个马步，运运气，然后一招向沙袋打去。\n", me);
        if (random(10)>6 ){
             write(HIM"沙袋左右摇晃，你不知不觉中领悟了些基本武功！\n"NOR);  
             switch(random(4)){
                case 0: me->improve_skill("finger", (int)(me->query("int") / 10));
                case 1: me->improve_skill("leg", (int)(me->query("int") / 10));
                case 2: me->improve_skill("claw", (int)(me->query("int") / 10));
                case 3: me->improve_skill("strike", (int)(me->query("int") / 10));
                }
             }
        if ( (int)me->query("combat_exp") < 30000) {
        if ( (int)me->query("potential") <  10000) {
	     me->add("potential",random(2));
             }           
             me->add("combat_exp",random((int)(me->query("str") / 10)));
             }
        return 1;
}
