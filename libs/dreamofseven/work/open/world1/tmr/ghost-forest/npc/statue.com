#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me,object ob);
void end_war();

 string *ghost=({"ghost6","ghost9","ghost12","ghost4","dog"});

string *place=({"forest2","forest3","forest4","forest5",
        "forest6","forest7","forest8","forest9","forest10",
        "forest11","forest12","lea","shrine","tree_up"});

void create()
{
        set_name("邪鬼  無妄像",({"ghost statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
這是一尊長足有八尺的石像，刻痕已略見剝落，看來放置在此時日已
久。石像頭戴金黃羽盔，身披白銀戰甲，持一丈六銅棍，粗如兒臂。無妄
像眇一左目，眉目間給人極為自負的感覺。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","尊");
                set("no_get",1);
                set("no_sac",1);
                set("value",20000);
        }
        setup();
}

void init()
{
        add_action("do_kneel","kneel");
        add_action("do_blooding","blooding");
}

int do_kneel(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg !="statue") return 0;
        message_vision("$N恭恭敬敬朝無妄像跪了下去。\n",me);
        me->set_temp("kneel_ghost",1);
        return 1;
}

int do_blooding(string arg)
{
        object me,ob,ghost,blood;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="statue") return 0;
        if(!objectp(blood=present("dab-aqua blood",me) ) )
                return notify_fail("你身上沒有血塊之類的東西。\n");
        if(ob->query("open_war") )
                return notify_fail("鬼斷森林已經鬼眾肆虐了。\n");

     destruct(blood);
        message_vision("$N將一片血塊塗沫在無妄像上。\n",me);
        message_vision(CYN"\n一道光芒從無妄像兩眼直衝上天.....\n"NOR,me);
        ob->set("open_war",1);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        int i;
        object g;

        if(!ob->query("open_war") ) return;
        message("world:world1:vision",
HIW"\n    "+me->query("name") +HIW "解開了深寂已久的封印，整片天空忽然血雲彌佈.......\n\n"
HIC"            一陣陣暴雷聲響從森林深處的無妄像傳了開來.....\n\n\n"
HIR"整座鬼斷森林登時群鬼降臨，喊殺一片！！\n\n" NOR
,users() );
     //鬼王
          g=new(__DIR__+"ghostking" );
        g->move(TMR_PAST+"ghost-forest/shrine" );
        for(i=0;i<=12;i++)
        {
        g=new(__DIR__+ghost[random(sizeof(ghost) ) ] );
	g->move(TMR_PAST+"ghost-forest/"+place[random(sizeof(place))] );
        }

call_out("end_war",180);
        return;
}

void end_war()
{
        object ghost;

          if(objectp(ghost=find_living("ghost-forest-war-ghost") ) )
{
       if(!environment(ghost)) destruct(ghost);

                  call_out("end_war",30);
        }
        else {
                message("world:world1:vision",
HIY"\n\n                遠方的西邊射來一道金黃色光芒直衝鬼斷森林深處...\n\n"NOR
CYN"    凝聚在鬼斷森林上方的血雲散了開來，整座森林又回復平時的沉靜了.....\n\n" NOR
                ,users() );
                this_object()->set("open_war",0);
        }       
        return;
}
