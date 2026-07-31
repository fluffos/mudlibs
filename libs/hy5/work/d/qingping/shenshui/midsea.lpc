 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM; 
int room_check(object room); 
void create()
{
        set("short", "海水中");
        set("long", @LONG
水流平稳了许多，这里的水呈半透明的蔚蓝色，令人很难想象水面上恶浪滔天
的情景。水在你身边温柔的流动，不时游过的小鱼在你身旁擦身而过，似乎对你的
存在无动于衷。
LONG
        );
        set("exits", ([
                "up" : __DIR__"yadi",
                "down": __DIR__"botsea",
        ]) );
        set("objects",([
                __DIR__"npc/octopus":   1,
        ]) );
        set("no_fly", 1);
        set("coor/x",190);
        set("coor/y",12310);
        set("coor/z",-70);
        setup();
} 
void init(){
        object me, obj;
        int htime,ntime;
        
        add_action("do_dive", "dive");
        me = this_player();
        if(userp(me) && !me->query_temp("appy/use_under_water")){
                 htime = me->query_str() + me->query_kar();
                if(!(ntime = me->query_temp("marks/水时")))   
                        ntime = 5;
                else 
                        ntime = ntime + 5;
                me->set_temp("marks/水时", ntime);
                call_out("airing", 5, this_player());
           }
}  
int do_dive(){
        object me, obj, room,octopus;
        me = this_player();
        obj = me->query_temp("armor/mask");
        
        if (octopus=present("octopus",this_object()))
                return notify_fail("大章鱼八爪翻飞，挡住了你的去路。\n");
        
        if(obj && obj->query("避水")) {
                message_vision("$N继续向下潜去。\n", me);
                room = find_object(__DIR__"botsea");
                if(!objectp(room)){
                    room = load_object(__DIR__"botsea");
                }
                if (room_check(room)) {
                        tell_object(me,"下面好像有人，潜不下去耶。\n");
                        return 1;
                }  else 
                        room->reset();
                me->move(room);
                this_object()->reset();
                message("vision", me->name() + "潜到你身边的水中。\n", environment(me), me);
        } else {
            tell_object(me, "你觉得胸口越来越憋闷，必须尽快换口气了。\n");
    }
    return 1;
} 
int airing(object ob)
{
        int i, htime, ntime;
    
        if(ob->query_temp("apply/use_under_water")){
                return 1;
        }
        if(environment(ob) == this_object()){
        htime = (int)ob->query_str() + (int)ob->query_kar();
        if(!(ntime = (int)ob->query_temp("marks/水时"))) {  
                ntime = 5;
        } else {
                ntime = ntime + 5;
        }
        ob->set_temp("marks/水时", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/水时", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N已经憋得成半昏迷状态，再不出赶快出水，就会憋死在这儿。\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N已经憋得面红耳赤，半分中之内再不出水，恐怕会憋死在这儿。\n"NOR, ob);
        else 
            message_vision(HIB "$N觉得胸口越来越闷，大概在水里已呆不了很久。\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
} 
int valid_leave(object me,string dir){
        
        if (dir=="down"){
                tell_object(me,"水流湍急，你得使劲潜（ｄｉｖｅ）下去才行。\n");
                return notify_fail("");
        }
        if(dir == "up") {
                me->delete_temp("marks/水时");
                message_vision("$N蹬了蹬腿向上游去。\n", me);
                return 1;
        }
}  
int room_check(object room) {
        int i;
        object *inv;
        
        inv=all_inventory(room);
        for (i=0;i<sizeof(inv);i++){
                if (userp(inv[i])) return 1;
        }
        return 0;
}   
