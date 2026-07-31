#include <ansi.h>
inherit ROOM;
string* obj = ({
       BINGQI_D("gangzhang"),
       BINGQI_D("feihuangshi"),
       MISC_D("fire"),
       BINGQI_D("changbian"),
       ARMOR_D("armor"),
       BINGQI_D("gangjian"),
       BINGQI_D("tiegun"),
       FOOD_D("hulu"),
       BINGQI_D("blade"),
       ARMOR_D("changpao"),
       __DIR__"obj/shezhang",
       __DIR__"obj/book1",
       __DIR__"obj/book2",
       __DIR__"obj/book3",
       __DIR__"obj/book5",
       __DIR__"obj/shepi",
       __DIR__"obj/yao",
       __DIR__"obj/yao1",
       __DIR__"obj/yao2",       
});

void create()
{
        set("short", "储藏室");
        set("long", @LONG
你一进门便闻到一股霉味，在门外射进来的阳光的照耀下，你看见这
里满屋的灰尘，成堆成堆的物品快堆满了整间房间。你很是奇怪为什么仆
役们离开时不把这些物品也带走。
LONG);
        set("exits", ([
              "east" : __DIR__"kongdi",
        ]));
        setup(); 
}

void init()
{
        add_action("do_find", "find");
        add_action("do_find", "zhao");
        add_action("do_find", "fan");
}

int found(object me)
{
        object ob = new( obj[random(sizeof(obj))] );
if (ob) {
 ob->move(me);
        message_vision("$N翻了半天，找到了" + ob->query("name") + "。\n", me);
        me->set_temp("baituo_find", 1);
}
        return 1;
}

int do_find()
{
       object me = this_player();
       if( (int)me->query_temp("baituo_find") ) 
                return notify_fail("你已经拿了东西了，走吧。\n");
       if (me->query_skill("hamagong", 1) && 
           me->query_skill("poison", 1) > 30){
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                found(me);    
                }
       else if (me->query_skill("poison", 1) > 50){
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                if(random((int)me->query("kar")) < 15){
                     write("你吸了口气，突然觉得头中一阵眩晕。\n");
                     me->unconcious();
                     }
                else found(me);    
                }
       else { 
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                write("你吸了口气，突然觉得头中一阵眩晕。。。不好！你中毒了！\n");
                me->apply_condition("snake_poison", me->query_condition("snake_poison")+22);
                me->unconcious();
                }
       return 1; 
}
