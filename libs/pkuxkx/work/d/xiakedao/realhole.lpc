#include <command.h>
inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG

   奔入石洞中，但觉酷热全消，迎面吹来一阵寒风。越往里走寒风更烈，
呼啸之声，连绵不绝。这寒风的呼啸，听来竞犹如战场上的杀戮之声一般，
使得这阴森幽暗的洞窟之中，充满了恐怖与杀机。
LONG
        );
        
        set("exits", ([ 
                "northup" :__DIR__"windhole",
                "enter"   :__DIR__"study_room",
 ]));
        set("objects", ([
        
                        ]) );

     

        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;

        if ( dir == "enter" ) {
                 if ( me->query("xkx/can_not_in") )
                {
                    return notify_fail("你以为这里是旅馆呀，怎么能够几次三番的进呢？\n");
                }
                inv = all_inventory(me);
                for(int i=0; i<sizeof(inv); i++) {
                        if( (string)inv[i]->query("id") != "cloth" || userp(inv[i]) )
                                DROP_CMD->do_drop(me, inv[i]);
                }
                me->save();
        }
                
        return ::valid_leave(me, dir);
}

