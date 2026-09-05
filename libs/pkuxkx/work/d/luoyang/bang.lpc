#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
这里是洛阳西门外一处空场，官府设立了各种排行榜以彰武林义士。
LONG
        );

        set("exits", ([
               "west" : __DIR__"bang1", 
               "east" : __DIR__"bang2",            
               "north" : __DIR__"ximen",
               "south" : __DIR__"bang3",
               "southwest" : __DIR__"bang4",
               "southeast" : __DIR__"bang5",
        ]));
        
        set("no_fight",1);
	      set("no_perform", 1);
	      set("no_steal", 1);
	      set("no_sleep_room", 1);
		set("no_task",1);
        set("outdoors", "luoyang");
        setup();
      //  call_out("adv",60+random(60));
      //  call_out("clean",60);
}

int valid_leave(object me,string dir)
{  
	if (dir!="north"&&!userp(me))
    {
        return notify_fail("你老兄哪能出去呀？\n");
    }
	return ::valid_leave(me, dir);
}

int adv()
{
    CHANNEL_D->do_channel(this_object(), "jh","洛阳城西门南面增加了几处排行榜，武林人士可去尝试，一旦成功，则可上榜以彰其效率。", -1);
    remove_call_out("adv");
    call_out("adv",7200+random(7200));
    return 1;
}

int clean_room(object room)
{
    object *ob=all_inventory(room);
    int i,flag=0;
    string ob_name;
    for (i=0;i<sizeof(ob);i++)
    {
        if (!ob[i]->is_character())
        {
            ob_name=ob[i]->query("name");
            destruct(ob[i]);
            flag=1;
        }
    }
    if (flag==1)
    {
        tell_room(room,"巡场的小吏把丢弃在地的"+ob_name+"等物给收走了。\n");
    }
    return 1;
}

int clean()
{
    object ob;
    int times=this_object()->query("update_times");
    times=times%600;
    ob=load_object(__DIR__"bang1");
    clean_room(ob);
    if (times==1)
    ob->AI_add_in();
    ob=load_object(__DIR__"bang2");
    clean_room(ob);
    if (times==2||times==302)
    ob->AI_add_in();
    ob=load_object(__DIR__"bang3");
    clean_room(ob);
    if (times==3||times==203||times==403)
    ob->AI_add_in();
    ob=load_object(__DIR__"bang4");
    clean_room(ob);
    if (times==4||times==154||times==304||times==454)
    ob->AI_add_in();
    ob=load_object(__DIR__"bang5");
    clean_room(ob);
    if (times==5||times==105||times==205||times==305||times==405||times==505)
    ob->AI_add_in();
    this_object()->add("update_times",1);
    remove_call_out("clean");
    call_out("clean",60);
    return 1;
}