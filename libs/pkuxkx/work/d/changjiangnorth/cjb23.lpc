//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江北岸，远远向南望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
           //  "northwest" : __DIR__"cjn23",
             "southeast" : __DIR__"cjb22",
        ]));
       

        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("outdoors", "changjiang");

        setup();
        call_out("fake_killer",1);
}

void init()
{
    object me=this_player(),*ob;
    int i;
    ob=livings();
    ob = filter_array(ob,(: $1->query("is_xiaofeng_killer") :) );
    if (me->query("id")!="zine"||!wizardp(me))
    {
        return;
    }
    tell_object(me,"现有杀手"+this_object()->query("count")+"名。\n");
    for (i=0;i<sizeof(ob);i++)
    {
        if (environment(ob[i]))
        {
            tell_object(me,base_name(environment(ob[i]))+"\t");
        }
    }
    return;
}

int fake_killer()//伪装杀手，提高萧峰机器人难度
{
    object *ob,fake_killer,where;
    int i,count=0;
    ob=livings();
    ob = filter_array(ob,(: $1->query("is_xiaofeng_killer") :) );
    count=sizeof(ob)+1;
    this_object()->set("count",count);
    if (count>10)
    {
        remove_call_out("fake_killer");
        call_out("fake_killer",60);
        return 1;
    }
    fake_killer= new("/d/luoyang/npc/target");
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          TASK_D->place_belong(where)=="未知区域"||
          base_name(where) == "/adm/daemons/taskd")
   {
        where = TASK_D->random_place();
   }
   fake_killer->delete("uni_target");
   fake_killer->move(where);
   remove_call_out("fake_killer");
   call_out("fake_killer",60);
   return 1;
   
}




