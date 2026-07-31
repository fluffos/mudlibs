#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "地洞");
        set("long", @LONG
这条小小的地道大约有七八尺，然后，里面就是个小小的洞，最多也
不过只有七八尺见方。但这洞里，却早巳铺好了四五床棉被，还有两缸水，
一坛酒，和一大堆咸肉、香肠、糯米糕，居然还有十几本书。
LONG
        );
        set("exits", ([ 
                                ]));
        set("objects", ([
                __DIR__"obj/barrel" : 1,
        ]) );
        set("resource/water", 1);
        set("liquid/container", "水缸");  
        set("objects", ([
               __DIR__"obj/ricecake" : 1,
               __DIR__"obj/meat" : 1,
        ]) );
        set("item_desc", ([
                "地": "地面高低不平，在角落里的一处更是陷下一块，也许可以挖(dig)一下。\n",
                "地面": "地面高低不平，在角落里的一处更是陷下一块，也许可以挖(dig)一下。\n",
                "ground": "地面高低不平，在角落里的一处更是陷下一块，也许可以挖(dig)一下。\n",
                "floor": "地面高低不平，在角落里的一处更是陷下一块，也许可以挖(dig)一下。\n",
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dig", "dig");
} 
int do_dig(string arg)
{
        object room, *inv;
        object me, weapon, ob;
        int i;
        me = this_player();
        room = find_object(__DIR__"center");
        if(!objectp(room)) 
                room = load_object(__DIR__"center"); 
        if (weapon=me->query_temp("weapon"))
                message_vision(YEL"$N拿起"+weapon->query("name")+YEL"，在地上拼命地挖了起来！\n"NOR,me);
                else message_vision(YEL"$N撸起袖子，在地上拼命地挖了起来！\n"NOR,me);
        message_vision(HIR"突然，砰的一响，像是木板碎裂的声音，地上裂了一个大洞。\n"NOR,me);
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (!userp(ob))continue;
                message_vision(HIR"一声惊叫，$N向洞里直坠下去。\n"NOR,ob);
                message("vision",HIR"扑通一声，上面摔下个人来。\n"NOR,room);
                ob->move(room);
        }
        return 1;
} 
