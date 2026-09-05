// Zine Oct 16 2010
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
void create()
{
        set("short", HIR"天茗喜铺"NOR);
        set("long", @LONG
这是洛阳城里的一家喜亲铺，主营各种吉服。生意兴隆。
LONG
        );

        set("exits", ([
            "west" : __DIR__"huadian",
            "southeast" : __DIR__"xiaoshe2",
            
        ]));
        
        
        setup();
        call_out("gettime",1);
        
}

int gettime()
{
    mixed* timeinfos;
    int hour;
    int minute;
    int mday;
    int i;
    object* all;
    object huoji;
    timeinfos = localtime(time());
    hour = timeinfos[LT_HOUR];
    minute = timeinfos[LT_MIN];
    mday = timeinfos[LT_MDAY];
    if (hour==8)
    {
        if (!this_object()->query("huoji"))
        {
			huoji=new("/d/luoyang/npc/xiqingseller");
            huoji->move(this_object());
            CHANNEL_D->do_channel(this_object(), "bd", "喜铺伙计(Huo ji): 鄙铺开始营业了，欢迎新老顾客惠顾。", -1);
            this_object()->set("huoji",1);
        }
        else
        {
            CHANNEL_D->do_channel(this_object(), "bd", "喜铺伙计(Huo ji): 各种新娘新郎吉服，欢迎光临。", -1);
        }
    }
    if (hour==16)
    {
        all=all_inventory();
        for (i=0;i<sizeof(all);i++)
        {
            if (all[i]->query("xiseller")=="yes")
            {
                this_object()->delete("huoji");
                huoji=all[i];
                destruct(huoji);
                CHANNEL_D->do_channel(this_object(), "bd", "喜铺伙计(Huo ji): 鄙铺打烊了，明日请早。", -1);
            }
        }
        
    }
    
    remove_call_out("gettime");
    call_out("gettime",1200);
    return 1;
}


