#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "三清宫");
        set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙
飞凤舞地写着＂三清宫＂三个大字。门的两侧各有一座铜狮。
使人感到庄严的气份笼罩着这个地方。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"grassland2",
]));
        set("item_desc", ([
                "door": "铜钉的大门，门上有门环，你可以敲(knock)门。\n",
                "门": "铜钉的大门，门上有门环，你可以敲(knock)门。\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2090);
        set("coor/z",80);
        setup();
} 
void init()
{
//      add_action("do_break", "break");
        add_action("do_knock", "knock");
} 
void wantopen(object me)
{
        object  waiter, tao1, tao2, tao3;
        object  room;  
        seteuid(geteuid());
        room = find_object(__DIR__"da_yuan"); 
        message("vision", "\n吱的一声，门向里开了。\n", this_object());
    if(present("taoist fighter", this_object())){
        return;
    }
        waiter = new(__DIR__"npc/waiter_taoist");
    message("vision", waiter->name()+ "走了过来。\n", this_object());
        if( room )  message("vision", waiter->name() + "吱的一声把门打开，走了出去。\n", room);
        waiter->move(this_object());
        message("vision", "孙天灭说道：这位"+ RANK_D->query_respect(me) + 
                "请进。\n", this_object());
        call_out("closedoor", 10, me);
}
/*
void wantbreak(object me)
{
        object  waiter, tao1, tao2, tao3;
        object  room; 
        seteuid(geteuid());
        room = find_object(__DIR__"da_yuan");
        waiter = new(__DIR__"npc/waiter_taoist");
        message("vision", waiter->name()+ "走了过来。\n", this_object());
        waiter->move(this_object());
        message("vision", "\n孙天灭厉声喝道：哪里来的"+ RANK_D->query_rude(me) + 
                "，敢到三清宫撒野，把命留下来！\n", this_object());
        this_object()->set("blocks", ([
                "north" : "fighter",
        ]));
        tao1 = new(__DIR__"npc/up_taoist");
        tao1->move(this_object());
        tao2 = new(__DIR__"npc/reg_taoist");
        tao2->move(this_object());
        tao3 = new(__DIR__"npc/reg_taoist");
        tao3->move(this_object());
        message_vision(HIB "\n从道观里跑出了三个道人，二话没说就和$N打了起来。\n\n"NOR, me);
        tao1->kill_ob(me);
        tao2->kill_ob(me);
        tao3->kill_ob(me);
        me->kill_ob(tao1);
        me->kill_ob(tao2);
        me->kill_ob(tao3);
        call_out("closedoor", 20, me);
} 
int do_break(string arg)
{
        object room, me; 
        if( arg=="door" || arg == "门") {
                me = this_player();
                if(query("exits/north")) {
                        message_vision(HIB "$N在开着的大门上，狠狠地踢了一脚！\n"NOR, me);
                        message_vision(HIB "这一下用力太大，痛得$N直咧嘴！\n"NOR, me);
                } else if(present("taoist guard", this_object()) || present("taoist fighter", this_object()) 
                                || present("taoist", this_object())){
                        tell_object(me, "有人在还是不要乱踹门的为好。\n");
                        message("vision", me->name()+"抬腿犹豫了一下又放了下来。\n", environment(me), me);
                } else {
                message_vision(HIB "$N用力一脚，咣的一声，把大门踢了开来！\n"NOR, me);
                set("long", @LONG
铜钉大门已被人踢开，门的上方挂着一块金匾，匾上龙
飞凤舞地写着＂三清宫＂三个大字。门的两侧各有一座铜狮。
使人感到庄严的气份笼罩着这个地方。
LONG
        );
                set("exits/north", __DIR__"da_yuan");
                if( room = find_object(__DIR__"da_yuan") ) {
                        message("vision", HIB "咣的一声，大门被人踢了开来！\n"NOR, room);
                        room->set("exits/south", __FILE__);
                        room->set("item_desc", ([
                                "door": "铜钉的大门，门是开着的。\n",
                                "门": "铜钉的大门，门是开着的。\n",
                        ]) );
                }
                me->start_busy(2);
                call_out("wantbreak", 2, me);
                }
        }
        else {
                 write("你要踢什么？\n");
        }
        return 1;
}
*/
int do_knock(string arg)
{
        object room, me, thisroom; 
        if( arg=="door" || arg == "门") {
           me = this_player();
                if(query("exits/north")) {
                        message_vision(HIB "门是开着的，敲什么？\n"NOR, me);
                        return 1;
                }
                message_vision(HIB "$N走到门前，轻轻地用门环敲了两下。\n"NOR, me);
                set("long", @LONG
铜钉大门敞开着，门的上方挂着一块金匾，匾上龙飞凤
舞地写着＂三清宫＂三个大字。门的两侧各有一座铜狮。使
人感到庄严的气份笼罩着这个地方。
LONG
        );
                set("exits/north", __DIR__"da_yuan");
                if( room = find_object(__DIR__"da_yuan") ) {
                        message("vision", HIB "你听到当当两声，有人在门外敲门。\n"NOR, room);
                        room->set("exits/south", __FILE__);
                        room->set("item_desc", ([
                                "door": "铜钉的大门，门是开着的。\n",
                                "门": "铜钉的大门，门是开着的。\n",
                        ]) );
                }
                me->start_busy(2);
                call_out("wantopen", 2, me);
                
        }
        else {
                write("你要敲什么？\n");
        }
                return 1;
} 
void closedoor(object me)
{
        object obj, room, troom; 
        troom = this_object();
        if(environment(me) != troom) {
                room = find_object(__DIR__"da_yuan");
                obj = present("guard", troom);
                if(obj) {
                        message("vision",obj->name() + "走进了道观。\n", troom);
                        destruct(obj);
           }
                obj = present("taoist", troom);
                if(obj) {
                        message("vision", obj->name() + "走进了道观。\n", troom);
                        destruct(obj);
                }
                obj = present("taoist", troom);
                if(obj) {
                        message("vision", obj->name() + "走进了道观。\n", troom);
                        destruct(obj);
                }
                obj = present("fighter", troom);
                if(obj) {
                        message("vision", obj->name() + "走进道观，轻轻地把门关上了。\n", troom);
                        destruct(obj); 
                        }
                        if(room) {
                                room->delete("exits/south");
                                room->set("item_desc", ([
                        "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                        "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                                ]) );
                        delete("exits/north");
                        
        set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙
飞凤舞地写着＂三清宫＂三个大字。门的两侧各有一座铜狮。
使人感到庄严的气份笼罩着这个地方。
LONG
        );
                }
        } else {
                call_out("closedoor", 15, me);
        }
}  
void reset(){
        object room;
        ::reset();
        if(query("exits/north")){
                set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙
飞凤舞地写着＂三清宫＂三个大字。门的两侧各有一座铜狮。
使人感到庄严的气份笼罩着这个地方。
LONG
                );      
                room = find_object(__DIR__"da_yuan");
                if(objectp(room) && room->query("exits/south")){
                        room->delete("exits/south");
                }
                delete("exits/north");
        }
}       
