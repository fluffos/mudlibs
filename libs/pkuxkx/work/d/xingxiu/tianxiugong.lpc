// 天秀宫
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
void create()
{
	set("short", HIM"天秀宫"NOR);
	set("long", @LONG
这里是星宿老仙丁春秋的住处，虽然老仙平时并不在，但没事还是不要擅闯为妙。
LONG
	);
    set("normaldesc", @LONG
这里是星宿老仙丁春秋的住处，虽然老仙平时并不在，但没事还是不要擅闯为妙。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"yanzhiguan",
        "north" : __DIR__"huoranxuan",
        "enter" : __DIR__"neidian",
     
        
		
    ]));
	set("objects", ([(__DIR__"npc/xxdizi") : 1,
    ]));
	setup();
    remove_call_out("change_night_desc");
    call_out("change_night_desc",1);
	::create();
}

void init()
{
    int i,count=0;
    object *ob=all_inventory(this_object());
    for (i=0;i<sizeof(ob);i++)
    {
        if (!userp(ob[i])&&ob[i]->query("xingxiu_chuangong_dizi"))
        {
            count+=1;
        }
        if (count>=2)
        {
            destruct(ob[i]);
        }
    }
    ::init();
}

int change_night_desc()
{
    object room;
    
    if (NATURE_D->get_current_day_phase() =="晚上" || NATURE_D->get_current_day_phase() =="午夜")
    {
        
        room=load_object(__DIR__"grass");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass1");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass2");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass3");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass4");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass5");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass6");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass7");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"乱葬岗"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"xiaoshanpo");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room->set("short",WHT"土坟头"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"xiaohu");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room=load_object(__DIR__"suishilu");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room=load_object(__DIR__"suishilu1");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room=load_object(__DIR__"suishilu2");
        room->set("long","这里黑漆漆一片，安静地可怕，你只能听见自己心跳的声音。\n");
        room=load_object(__DIR__"shanlin");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin1");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin2");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin3");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin4");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin5");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin6");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin7");
        room->set("long",room->query("normaldesc"));
        room->delete("day");
        room=load_object(__DIR__"shanlin8");
        room->set("long",room->query("normaldesc"));
        room->delete("day");

    }
    else
    {
        
        room=load_object(__DIR__"grass");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass1");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass2");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass3");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass4");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass5");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass6");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"grass7");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"草地"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"xiaoshanpo");
        room->set("long",room->query("normaldesc"));
        room->set("short",HIG"小山坡"NOR);
        room->delete("realmap");
        room=load_object(__DIR__"xiaohu");
        room->set("long",room->query("normaldesc"));
        room=load_object(__DIR__"suishilu");
        room->set("long",room->query("normaldesc"));
        room=load_object(__DIR__"suishilu1");
        room->set("long",room->query("normaldesc"));
        room=load_object(__DIR__"suishilu2");
        room->set("long",room->query("normaldesc"));
        room=load_object(__DIR__"shanlin");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin1");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin2");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin3");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。往西面走(west)通向谷底。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin4");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin5");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin6");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin7");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
        room=load_object(__DIR__"shanlin8");
        room->set("long","山林间雾气缭绕，似乎蕴有剧毒。\n");
        room->set("day",1);
    }
    remove_call_out("change_night_desc");
    call_out("change_night_desc",60);
    return 1;
}

