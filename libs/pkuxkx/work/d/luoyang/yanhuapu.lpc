// Zine Oct 16 2010
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
void create()
{
        set("short", "烟花铺");
        set("long", @LONG
这是洛阳城里的一家烟花铺，主营各种喜庆烟花。生意兴隆，主人却只在每
日晚间营业。
LONG
        );

        set("exits", ([
            "west" : __DIR__"hutong4",
            "east" : __DIR__"tongrentang",
            "north" : __DIR__"qianzhuang",
            "south" : __DIR__"nirenpu",
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
    if (hour==18)
    {
        if (!this_object()->query("huoji"))
        {
			huoji=new("/d/luoyang/npc/yanhuaseller");
            huoji->move(this_object());
            CHANNEL_D->do_channel(this_object(), "bd", "烟花店伙计(Huo ji): 鄙铺又开始营业了，欢迎新老顾客惠顾。", -1);
            this_object()->set("huoji",1);
        }
        else
        {
            CHANNEL_D->do_channel(this_object(), "bd", "烟花店伙计(Huo ji): 新进各种烟花，种类各异。", -1);
        }
    }
    if (hour==23)
    {
        all=all_inventory();
        for (i=0;i<sizeof(all);i++)
        {
            if (all[i]->query("yanhuaseller")=="yes")
            {
                this_object()->delete("huoji");
                huoji=all[i];
                destruct(huoji);
                CHANNEL_D->do_channel(this_object(), "bd", "烟花店伙计(Huo ji): 鄙铺打烊了，明日请早。", -1);
            }
        }
    }
    
    remove_call_out("gettime");
    call_out("gettime",1200);
    return 1;
}


