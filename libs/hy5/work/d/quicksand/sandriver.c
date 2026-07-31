#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "沙河底");
        set("long", @LONG
原来这里是一道暗河，冰冷的水让你忘却了身在沙漠，周围一片昏暗，都是迷
迷蒙蒙的沙水，你可以感觉到水中的沙子轻轻地摩擦着你的面颊，屏住一口气，你
微微睁眼向四周望去，斜上方好像有个洞口，透出微微红光。 
LONG
        );
        set("exits", ([ 
                "southup" : __DIR__"sandriver1",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 
int valid_enter(object me) {
        me->set_temp("in_river", time());
        tell_object(me, "\n突然间，压力减轻了，四周的流沙也不见了，你从高处落下，扑通一声掉到了水里。\n\n");
        message("vision", "\n扑通一声，" + me->name() + "掉到了你身旁的水中。\n", this_object(), me);
        this_player()->set_temp("marks/水时", 0);
        call_out("airing", 5, this_player());
        return 1;
}  
int airing(object ob)
{
        int i, htime, ntime;
    
        if( environment(ob) == this_object())    {
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
                } else if( ntime > (htime - 15) )
                                message_vision(HIR "$N已经憋成半昏迷状态，再不赶快出水，就会憋死在这儿。\n"NOR, ob);
                  else if( ntime > (htime - 30) )
                                message_vision(HIR "$N已经憋得面红耳赤，半分钟之内再不出水，恐怕会憋死在这儿。\n"NOR, ob);
                  else 
                                message_vision(HIB "$N觉得胸口越来越闷，大概在水里已呆不了很久。\n"NOR, ob);
        call_out("airing",5, ob);
    }
    return 1;
}   
int valid_leave(object me, string dir) {
        if (dir=="southup") {
                message_vision(HIB"\n$N屏住气，摸索着向前游去。\n"NOR, me);     
        } else this_player()->set_temp("marks/水时", 0);
        return 1;
}       
