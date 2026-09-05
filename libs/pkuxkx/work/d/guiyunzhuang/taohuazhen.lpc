// Zine TH newbiejob
#include <ansi.h>
#include "/d/guiyunzhuang/bonus.h"
inherit ROOM;

void create()
{
    set("short", HIM"桃花阵"NOR);
    set("long", @LONG
这里是一大片的桃花阵，隐含八卦九宫位置。如果没有办法破解，你也可以
选择离开(leave)。
LONG
    );
     set("no_task",1);
     set("exits", ([
	        "west" : __DIR__"taohuazhen",
            "east" : __DIR__"taohuazhen",
            "south" : __DIR__"taohuazhen",
            "north" : __DIR__"taohuazhen",
            "northwest" : __DIR__"taohuazhen",
            "southwest" : __DIR__"taohuazhen",
            "southeast" : __DIR__"taohuazhen",
            "northeast" : __DIR__"taohuazhen",
	  ]));
                                                    
    set("real_dark",1);
    setup();
}

void init()
{
    add_action("do_leave","leave");
}

int do_leave()
{
    object me=this_player();
    object rm=load_object("/d/guiyunzhuang/houhuayuan");
    tell_object(me,"你莫名其妙地走出了桃花阵。\n");
    me->move(rm);
    message("vision",me->name()+"精神恍惚地走了过来。\n",environment(me),({me}));
    return 1;
}


int valid_leave(object me,string dir)
{
    string * tian=({"east","northeast","west","south",});
    string * ze=({"north","southwest","northwest","south"});
    string * huo=({"south","north","southeast","northwest"});
    string * lei=({"west","southeast","north","north"});
    string * feng=({"southeast","east","south","southwest"});
    string * shui=({"northeast","north","southwest","northwest"});
    string * shan=({"southwest","west","west","south"});
    string * di=({"northwest","northwest","south","east"});
    object killer;
    if (me->query("combat_exp")>=40000&&!random(9)&&!me->query_temp("thnewbiejob/killerappear"))
    {
        killer=new(__DIR__"npc/killer");
        killer->do_copy(me);
        killer->move(this_object());
        killer->kill_ob(me);
        me->set_temp("thnewbiejob/killerappear",1);
        tell_object(me,"一个女飞贼冲了出来，似乎来意不善。\n");
    }
    if (!me->query_temp("thnewbiejob/taolin/gua"))
    {
        me->delete_temp("thnewbiejob/taolin/step1");
        me->delete_temp("thnewbiejob/taolin/step2");
        me->delete_temp("thnewbiejob/taolin/step3");
        me->delete_temp("thnewbiejob/taolin/step4");
        return 1;
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==1)
    {
        me->set_temp("thnewbiejob/taolin/step1",tian[0]);
        me->set_temp("thnewbiejob/taolin/step2",tian[1]);
        me->set_temp("thnewbiejob/taolin/step3",tian[2]);
        me->set_temp("thnewbiejob/taolin/step4",tian[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==2)
    {
        me->set_temp("thnewbiejob/taolin/step1",ze[0]);
        me->set_temp("thnewbiejob/taolin/step2",ze[1]);
        me->set_temp("thnewbiejob/taolin/step3",ze[2]);
        me->set_temp("thnewbiejob/taolin/step4",ze[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==3)
    {
        me->set_temp("thnewbiejob/taolin/step1",huo[0]);
        me->set_temp("thnewbiejob/taolin/step2",huo[1]);
        me->set_temp("thnewbiejob/taolin/step3",huo[2]);
        me->set_temp("thnewbiejob/taolin/step4",huo[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==4)
    {
        me->set_temp("thnewbiejob/taolin/step1",lei[0]);
        me->set_temp("thnewbiejob/taolin/step2",lei[1]);
        me->set_temp("thnewbiejob/taolin/step3",lei[2]);
        me->set_temp("thnewbiejob/taolin/step4",lei[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==5)
    {
        me->set_temp("thnewbiejob/taolin/step1",feng[0]);
        me->set_temp("thnewbiejob/taolin/step2",feng[1]);
        me->set_temp("thnewbiejob/taolin/step3",feng[2]);
        me->set_temp("thnewbiejob/taolin/step4",feng[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==6)
    {
        me->set_temp("thnewbiejob/taolin/step1",shui[0]);
        me->set_temp("thnewbiejob/taolin/step2",shui[1]);
        me->set_temp("thnewbiejob/taolin/step3",shui[2]);
        me->set_temp("thnewbiejob/taolin/step4",shui[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==7)
    {
        me->set_temp("thnewbiejob/taolin/step1",shan[0]);
        me->set_temp("thnewbiejob/taolin/step2",shan[1]);
        me->set_temp("thnewbiejob/taolin/step3",shan[2]);
        me->set_temp("thnewbiejob/taolin/step4",shan[3]);
    }
    if (me->query_temp("thnewbiejob/taolin/gua")==8)
    {
        me->set_temp("thnewbiejob/taolin/step1",di[0]);
        me->set_temp("thnewbiejob/taolin/step2",di[1]);
        me->set_temp("thnewbiejob/taolin/step3",di[2]);
        me->set_temp("thnewbiejob/taolin/step4",di[3]);
    }
    if (me->is_busy())
    {
        return notify_fail("你仔细观察着桃花阵。\n");
    }
    if (me->query_temp("thnewbiejob/taolin/killer"))
    {
        killer=find_living(me->query_temp("thnewbiejob/taolin/killer"));
    }
    if (killer&&present(killer->query("id"),environment(me))&&killer->query("owner")==me->query("id"))
    {
        return notify_fail("不解决了"+killer->name()+"，你恐怕很难离开。\n");
    }
    if (!me->query_temp("thnewbiejob/taolin/pass")&&dir==me->query_temp("thnewbiejob/taolin/step1"))
    {
        me->add_temp("thnewbiejob/taolin/pass",1);
        tell_object(me,"你充满自信的向前走去，桃花阵看来也不在话下。\n");
        me->add_busy(2);
        return ::valid_leave(me,dir);
    }
    if (me->query_temp("thnewbiejob/taolin/pass")==1&&dir==me->query_temp("thnewbiejob/taolin/step2"))
    {
        me->add_temp("thnewbiejob/taolin/pass",1);
        tell_object(me,"你充满自信的向前走去，桃花阵看来也不在话下。\n");
        me->add_busy(2);
        return ::valid_leave(me,dir);
    }
    if (me->query_temp("thnewbiejob/taolin/pass")==2&&dir==me->query_temp("thnewbiejob/taolin/step3"))
    {
        me->add_temp("thnewbiejob/taolin/pass",1);
        tell_object(me,"你充满自信的向前走去，桃花阵看来也不在话下。\n");
        me->add_busy(2);
        return ::valid_leave(me,dir);
    }
    if (me->query_temp("thnewbiejob/taolin/pass")==3&&dir==me->query_temp("thnewbiejob/taolin/step4"))
    {
        me->set_temp("thnewbiejob/taolin/pass",0);
        bonus(me,"taohuazhen");
        me->add_busy(2);
        return ::valid_leave(me,dir);
    }
    else
    {
        me->set_temp("thnewbiejob/taolin/pass",0);
        tell_object(me,"你胡乱走着，像个没头苍蝇一样，有个声音冷笑：桃花阵岂是浪得虚名。\n");
        me->add_busy(2);
        return ::valid_leave(me,dir);
    }
	return ::valid_leave(me,dir);
}

