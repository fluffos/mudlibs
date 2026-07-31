// mg1.c 迷宫大门
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN "高昌迷宫" NOR);
        set("long", @LONG
你走进迷宫，门内是条黑沈沈的长甬道，黑洞洞不知前面有什么。
身后是两扇铁铸的大门(gate)。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "north" : __DIR__"mg2",
        ]));    
        set("item_desc",([
                "gate" : "铁门上铁锈斑驳，显是历时已久的旧物。有个环(huan)你可以拉(turn)动。\n",
           ]));
        setup(); 
}

void init()
{
	 add_action("do_turn", "turn");
}

int do_turn(string arg)
{  
        object room, me;
        me = this_player();        
        if (query("exits/out"))
		  return notify_fail("铁已经是打开了。\n");
        if (!arg || arg == "")  return 0;
        if (arg == "huan"){
          if (!me->query_temp("turned")){
             message_vision("$N使劲转动着铁环，发出吱吱的响声，铁门却始终打不开。\n", me);
             me->set_temp("turned", 1);
             return 1;
             }
           message_vision("$N再向左转动铁环，突然铁门轰的一声打开了。\n$N一没留神，差点滚出去。\n", me);
           set("exits/out", __DIR__"mg-door");
           me->delete_temp("turned");
         if( room = load_object(__DIR__"mg-door") ) {
             room->set("exits/enter", __FILE__);
             message("vision", "里面传来一阵吱吱的响声，铁门被人推开了。\n",room );
             } 
           remove_call_out("close_door");
           call_out("close_door", 8);
           return 1;
           }
}

void close_door()
{
        object room;

        if( !query("exits/out") ) return;
        message("vision","轰的一声，铁门又自己合上了。\n", this_object() );
        if( room = load_object(__DIR__"mg-door") ) {
                room->delete("exits/enter");
                message("vision", "铁门又自己合上了。\n", room );
                  }
        delete("exits/out");
}

int valid_leave(object me)
{        
       me->delete_temp("turned");       
       return ::valid_leave(me);
}