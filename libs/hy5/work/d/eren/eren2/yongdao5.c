 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "白石道");
        set("long", @LONG
白玉般晶莹光滑的石道上竟留着一行脚印，每隔三尺，就有一个，就算是用尺
量着画上去的，也没有如此规律整齐。石道和两壁一样，平滑坚实，用刀来刻也十
分不容易。但这人的脚印竟比刀刻的还清楚。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao7",
                "westup" : __DIR__"yongdao4",
        ]));
        set("item_desc", ([
                "脚印": "脚印陷入石中约有寸许，当今世上，何人有此功力？\n",
                "footprint": "脚印陷入石中约有寸许，当今世上，何人有此功力？\n",
                "print": "脚印陷入石中约有寸许，当今世上，何人有此功力？\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me,string dir)
{
        object alert_room,trap_room;
                
        if(userp(me) && dir == "northdown")     {
                alert_room = find_object(__DIR__"yongdao3a");
                if(!objectp(alert_room))
                        alert_room = load_object(__DIR__"yongdao3a");
                if (alert_room->query("trap")) {
                        message_vision(HIR"只听警铃大作，$N脚下突然出现了一个大洞。\n"NOR, me);
                        message_vision(YEL"$N一个跟斗向洞里栽了下去。\n"NOR,me);
                        trap_room = find_object(__DIR__"trap1");
                        if(!objectp(trap_room))
                                trap_room = load_object(__DIR__"trap1");
           me->move(trap_room);
                me-> unconcious();
                return 1;
                }       
        }
        return 1;
}  
void init(){
        add_action("do_step", "step");
} 
int do_step(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "footprint" && arg != "脚印")) {
                return 0;
        }
        message_vision("$N试着到地上的脚印里踩了踩，大小差远了。\n",me);
        tell_object(me,"不服不行啊！\n");
        return 1;
}     
