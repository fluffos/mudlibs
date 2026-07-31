 inherit ROOM;
#include <ansi.h>; 
void create()
{
    object con, bot; 
        set("short", "荒坟"); 
        set("long", @LONG
这里孤零零的有一座荒冢，四周尽是树木，遮地这几乎暗无天日，时不时还闪
烁着几撮飘忽不定的鬼火，寒风吹过时，一阵死灰色的冷雾似乎从荒冢上升起，远
处不时传来一声声野狗的哀鸣，就像是鬼哭。若是仔细的看，坟头似乎还端端正正
摆放着一个青色的瓷瓶。
LONG); 
        set("get_ciping",1);
        set("be_ambushed",1);
        set("type","street");
        set("outdoors", "fugui");
        set("exits",([
                "east":__DIR__"tomb2",
        ]) );
        set("objects", ([
                __DIR__"npc/hong" : 1,
                __DIR__"npc/cui" : 1,
                __DIR__"obj/fentou": 1,
        ]) ); 
        set("coor/x",-650);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_get","get");
} 
void reset()
{
        object *inv;
        object item, fentou;
        ::reset();
        set("be_ambushed",1);
        fentou = present("fentou", this_object());
   inv = all_inventory(fentou);
        if( !sizeof(inv)) 
        {
                item = new(__DIR__"obj/ciping");
                item->move(fentou);
        }
} 
int do_get(string arg)
{
        object chi, wu;
        object me;
        int kee,sen,gin;
        string what,where;
        me = this_player();
        if(!arg) return 0;
        if(sscanf(arg,"%s from %s",what, where) !=2) 
                return 0;
        if((where == "fentou" || where == "坟头" ))
        {
                if (query("be_ambushed"))
                {
                        kee = (int) me->query("max_qi")/4;
                        gin = (int) me->query("max_jing")/4;
                        sen = (int) me->query("max_jing")/4;
                        message_vision(HIR"$N将手伸向坟头，准备拿东西。\n\n突然....................\n\n"NOR, me);
                        message_vision(HIR"一双手突然从坟墓里伸出来，点中了$N膝盖上的“环跳穴”，另一双\n手同时从积雪中伸出来，挥手射出两颗寒星射入$N的足踝。\n\n"NOR, me);
                        if (me->query("combat_exp")<400000) {
                                me->die();
                        message_vision(HIR"两双手无声无息地又缩回了坟墓里。\n"NOR, me);
                                return 1;
                        }
                        me->receive_wound("qi", kee);
                        me->receive_wound("jing", gin);
                        me->receive_wound("jing", sen);
                        me->apply_condition("redsnake",5+random(10));
                        set("be_ambushed",0);
                        me->start_busy(2);
                        chi = new(__DIR__"npc/chi");
                        wu = new(__DIR__"npc/wu");
                        chi->move(this_object());
                   wu->move(this_object());
                        chi->kill_ob(this_player());
                        wu->kill_ob(this_player());
                        return 1;     
                }
                return 0;
        }
        return 0;
}      
