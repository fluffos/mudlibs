#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "荒野");
        set("long", @LONG
再往南又是荒野了，李大娘的庄园就在镇边。太平镇八十三户人家，一半是武
镇山武三爷的，另一半就是这李大娘的。没有人知道大娘真名叫什么，也没人知道
她的来历，只知道她三年前买下了这座庄园。李家庄两边是三丈高墙，墙上倒插着
锋刃。西墙有扇铁门，门上挂着一把已经锈了一半的铜锁。
LONG
        );
        set("exits", ([ 
                "northwest": __DIR__"mroad8",
                "west": __DIR__"swamp1",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                "door": "一扇铁门，门上挂着一把已经绣了一半的铜锁。\n",
                "铁门": "一扇铁门，门上挂着一把已经绣了一半的铜锁。\n",
                "铜锁": "这把锁很奇怪，没有锁孔，只有一个小小的转盘。\n",  
                "lock": "这把锁很奇怪，没有锁孔，只有一个小小的转盘。\n",  
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_turn","turn");
}  
int do_turn(string arg){
        object me,room;
        me=this_player();
        
        if (arg=="转盘" || arg == "lock" || arg == "铜锁") {
                if (!me->query("parrot/甘老头的锁") && me->query("parrot/助三爷")!=1) {
                        message_vision("$N拿着铜锁左转右转，一点动静没有，许是没找到窍门。\n",me);
                        return 1;
                }
           tell_object(me,"你拿着铜锁左三转，右五转，再左七转。\n");
                tell_object(me,"铁门没有开，你的脚下似乎开始摇晃起来。\n");
                message_vision(HIR"土地竟忽然裂了开来，露出了个地洞。$N一个跟斗栽进了洞里。\n"NOR,me);
                room = find_object(__DIR__"pond");
                if(!objectp(room))
                        room = load_object(__DIR__"pond");
                me->move(room);
                return 1;
        }
        return 0;
}   
