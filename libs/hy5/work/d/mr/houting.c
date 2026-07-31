// /u/beyond/mr/houting.c
// this is made by beyond
// last update 1997/JULY/5

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIW"后厅"NOR);
         set("long", @LONG
这里是慕容家里商议事情的地方，不是慕容弟子最好不要到这里来。在
后堂正中摆放着一个香案，上面摆放着一个灵位牌子(paizi)，在正中墙上挂
着一幅百鸟朝奉图，边墙上挂着一口宝剑。东西两面各是一间厢房，南面是
内堂。
LONG
    );
         set("item_desc",([
             "paizi" : "慕容世代祖先灵位\n",  
             "sword" : "那是一口玲珑般的宝剑，透着碧玉色。\n",
             "baojian" : "那是一口玲珑般的宝剑，透着碧玉色。\n",
]));
         set("exits",([
             "east" : __DIR__"xiangfang2",
             "west" : __DIR__"xiangfang3",                    
             "south" : __DIR__"neitang",
             "north" : __DIR__"dating",
]));

         setup();
//         replace_program(ROOM);
}
             
void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_ketou", "拜祭");
}             

int do_ketou()
{
    mapping fam; 
    object me, ob, sword;

    me = this_player();
    ob = this_object();    
        if ( !present("douzhuan xingyi",me) || 
             !(fam = me->query("family")) || 
             fam["family_name"] != "姑苏慕容" ||
             me->query("combat_exp") < 100000 )
             return 0;
           
        if ( me->query_temp("慕容/ketou") == 20 ) {    
             sword = new("/d/mr/obj/biyu-jian");                          
                if(!clonep(sword)) {
                        message("vision","你不经意望见灵牌似乎已被打开过。\n", me);
                        me->delete_temp("慕容/ketou");
                        return 1;
                        }
                if (clonep(sword) && sword->violate_unique()){ 
                        destruct(sword);   
                        message("vision","你不经意望见灵牌似乎已被打开过了。\n", me);
                        me->delete_temp("慕容/ketou");
                        return 1;
                        }  
                message("vision","只听见铛的一声，灵牌里掉下一把寒光闪闪的宝剑。\n",me);
                        sword->move(ob);
                        destruct(present("douzhuan xingyi",me));
                        me->delete_temp("慕容/ketou");
                        return 1;
         }
        else {
                me->add_temp("慕容/ketou", random(2));
                message_vision("$N恭恭敬敬地在灵牌前磕了个响头。\n", me);
                return 1;
                }
}       
