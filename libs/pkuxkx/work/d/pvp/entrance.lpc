#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"地下格斗场"NOR );
        set("long", @LONG
这里就是地下格斗场入口了，一个白发老头儿坐在门口诡异的盯着你看。
LONG);
        set("objects", ([
        "/d/pvp/npc/chonger": 1,
        ]));
        set("exits", ([
                "east" : "/d/pvp/pkroom1",
                "west" : "/d/pvp/pkroom2",
                "up" : "/d/wizard/biwuchang",
        ]));
        set("no_fight", 1);
        set("outdoors", "xx" );
        setup();
}
int valid_leave(object me, string dir)
{
        object ob,gem;
        object* inv = deep_inventory(this_player());
        int i;
        if( dir =="up" )
                {
                return ::valid_leave(me, dir);
                }        
        for(i=sizeof(inv)-1; i>=0; i--)
                {
                        if(inv[i]->is_character())
                                return notify_fail(HIR"虫二"NOR"拦住你说：“把身上的人放下先！”\n");
                }
        if( dir =="east" &&  !objectp(gem = present("gem", this_player())) )
                {
                message_vision(HIR"虫二"NOR"哼了一声，一把将$N揪住：没带宝石也想往进闯？\n",this_player());
                return notify_fail("你灰头土脸的退了回来。\n");
                }
        if(objectp(gem) && !gem->is_gem()) 
                {
                message_vision(HIR"虫二"NOR"哼了一声，说道：“假宝石骗得了我，骗得了无欢么”？\n",this_player());
                return notify_fail("你灰头土脸的退了回来。\n");
                } 
        if (this_player()->query("id") == "hao mao")
                return 1; 
        if( dir =="west" )
                {
                return notify_fail(HIR"虫二"NOR"拦住你说：“不好意思，群殴室暂未开放。”\n");
                }
        if( dir =="east" &&  objectp(gem = present("gem", this_player())) ) 
                {
                message_vision("$N打着哆嗦被"HIR"虫二"NOR"领进了单挑室。\n",this_player());
                return ::valid_leave(me, dir);
                }
        return ::valid_leave(me, dir);
}
