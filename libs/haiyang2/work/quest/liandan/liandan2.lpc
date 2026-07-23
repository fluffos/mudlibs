// liandan2.c 炼丹房
// 星星lywin 2000/6/15 

#include <ansi.h>
inherit ROOM;
int do_liandan(string arg);
int do_hc(string arg);
int do_put(string arg);


string *dan1 = ({"/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust"});
string *dan2 = ({"/clone/misc/yangjing","/clone/misc/xiaohuan-dan"});
string *dan3 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng"});
string *dan4 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua"});
string *dan5 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua","/d/shenlong/obj/baihua","/d/city/npc/obj/shouwu","/d/quanzhen/npc/obj/gao"});
string *dan6 = ({"/clone/misc/kongquedan","/clone/misc/hedinghong","/clone/misc/bicanfeng","/clone/misc/dahuan-dan","/clone/misc/zhujingchan","/clone/misc/wuchangdan",
"/clone/misc/jiuhua","/d/shenlong/obj/baihua","/d/city/npc/obj/shouwu","/d/quanzhen/npc/obj/gao","/d/xiakedao/obj/zhou","/quest/feizei/lingzhi"
,"/quest/liandan/dan/ngdan1","/quest/liandan/dan/ngdan2","/quest/liandan/dan/ngdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/ngdan5","/quest/liandan/dan/ngdan6","/quest/liandan/dan/ngdan7","/quest/liandan/dan/ngdan8","/quest/liandan/dan/ngdan9"});
string *dan7 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan"});
string *dan8 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5"
,"/quest/liandan/dan/nbdan1","/quest/liandan/dan/nbdan2","/quest/liandan/dan/nbdan3"});
string *dan9 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/ndan1","/quest/liandan/dan/ndan2","/quest/liandan/dan/ndan3","/quest/liandan/dan/ndan4","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5"
,"/quest/liandan/dan/nxdan1","/quest/liandan/dan/nxdan2","/quest/liandan/dan/nxdan3","/quest/liandan/dan/nxdan4","/quest/liandan/dan/nxdan5","/quest/liandan/dan/nxdan6","/quest/liandan/dan/nxdan7","/quest/liandan/dan/nxdan8","/quest/liandan/dan/nxdan9"});
string *dan10 = ({"/quest/liandan/dan/z-dan","/quest/liandan/dan/n-dan","/clone/misc/yangjing","/clone/misc/xiaohuan-dan","/clone/misc/jinchuang","/clone/misc/gaoyao","/clone/misc/dust","/quest/liandan/dan/ndan1","/quest/liandan/dan/ndan2","/quest/liandan/dan/ndan3","/quest/liandan/dan/ndan4","/quest/liandan/dan/bdan1","/quest/liandan/dan/bdan2","/quest/liandan/dan/bdan3","/quest/liandan/dan/bdan4","/quest/liandan/dan/bdan5","/quest/liandan/dan/gdan1","/quest/liandan/dan/gdan2","/quest/liandan/dan/gdan3","/quest/liandan/dan/gdan4","/quest/liandan/dan/gdan5"
,"/quest/liandan/dan/ngdan1","/quest/liandan/dan/ngdan2","/quest/liandan/dan/ngdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/ngdan5","/quest/liandan/dan/ngdan6","/quest/liandan/dan/ngdan7","/quest/liandan/dan/ngdan8","/quest/liandan/dan/ngdan9"
,"/quest/liandan/dan/nxdan1","/quest/liandan/dan/nxdan2","/quest/liandan/dan/nxdan3","/quest/liandan/dan/ngdan4","/quest/liandan/dan/nxdan5","/quest/liandan/dan/nxdan6","/quest/liandan/dan/nxdan7","/quest/liandan/dan/nxdan8","/quest/liandan/dan/nxdan9"
});

 void create()
{
        set("short", "炼丹房");
        set("long", @LONG
这是平一指平时练丹的地方，他把从四处收集来的草药拿到这儿来练
成各种丹药，一般都只能练出些很平常的药！但是有时也会练出很利害的
灵药来。你可以把一些常见的草药放进(putinto)  药炉进行合成(hecheng) 。
LONG
        );

        set("exits", ([
                "east" : "/quest/liandan/liandan1",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_put","putinto");
        add_action("do_hc","hecheng");
        add_action("do_liandan","liandan"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_liandan(object ob)
{
        object me=this_player(); 
 
        if (!(ob = present("yao cao", this_player())))
                return notify_fail("你身上没有药草，炼得了什么？。\n");
                 
        if ( (int)me->query("jing")<50)
                return notify_fail("你的精力不足，无法炼丹。\n");

        if ( (int)me->query("qi")<50)
                return notify_fail("你的体不足，无法炼丹。\n");

        if ( (int)me->query("neili")<100)
                return notify_fail("你的内力不足，无法炼丹。\n");
    
    	if( me->is_busy() )
		return notify_fail("你正在忙呢!\n");
        
        if ( ob->query("lev") == 1 )
        {
        message_vision(HIY"$N将普通药草放进炉中，盘腿做下，点起火炉开始炼丹。\n"NOR,me); 
        destruct(ob);
        me->add("jing",-30);
        me->add("qi",-30);
        me->add("neili",-50);
        me->start_busy(9); 
       	call_out("liandan1",6,me);
        return 1;
        }
        else
        if ( ob->query("lev") == 2 )
        {
        message_vision(HIR"$N将珍贵药草放进炉中，盘腿做下，点起火炉开始炼丹。\n"NOR,me); 
        destruct(ob);
        me->add("jing",-50);
        me->add("qi",-50);
        me->add("neili",-100);
        me->start_busy(11); 
       	call_out("liandan2",8,me);
        return 1;
        }
}

int liandan1(object me)
{
        object ob;
        if ((int)me->query_skill("liandan", 1) < 30 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan1[random(3)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 150 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan10[random(39)]);
           ob->move(me);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 120 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan9[random(25)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 80 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan8[random(15)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 59 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan7[random(2)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 29 )
        {
           message_vision(HIY"$N对炼丹已有不少经验，不慌不忙的将内力注入炉中。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan2[random(2)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }       
} 

int liandan2(object me)
{
        object ob; 
        if ((int)me->query_skill("liandan", 1) < 30 )
        {
           message_vision(HIR"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIR"但这药草难炼之极，火势仍是不足，$N只好又一次逼入内力。\n"NOR,me); 
           message_vision(HIR"终于练成灵丹，$N不禁松了一口气。\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan3[random(3)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 199 )
        {
           message_vision(HIW"$N对于炼丹之术早已是天人和一。\n"NOR,me); 
           message_vision(HIW"虽然这药草非常难炼，$N也不不紧张，稳健地将内力注入炉中。\n"NOR,me); 
           message_vision(HIW"$N终于炼出了一颗足以名震天下的奇药。\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan6[random(21)]);
           ob->move(me);       
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 150 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan10[random(39)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else
        if ((int)me->query_skill("liandan", 1) > 100 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan9[random(25)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
        else  
        if ((int)me->query_skill("liandan", 1) > 80 )
        {
           message_vision(HIW"$N对于炼丹之术早已是非常精通。\n"NOR,me); 
           message_vision(HIW"虽然这药草非常难炼，$N也不不紧张，稳健地将内力注入炉中。\n"NOR,me); 
           message_vision(HIW"不一会儿就大功告成。\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan5[random(10)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }
        else 
        if ((int)me->query_skill("liandan", 1) > 60 )
        {
           message_vision(HIR"$N对于炼丹之术早已是轻车熟路。\n"NOR,me); 
           message_vision(HIR"虽然这药草非常难炼，$N也不不紧张，稳健地将内力注入炉中。\n"NOR,me); 
           message_vision(HIR"不一会儿就大功告成。\n"NOR,me);
           me->add("combat_exp",50+random(30));
           me->add("potential",25+random(10));
           ob=new(dan4[random(7)]);
           ob->move(me);       
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));  
           return 1;
        }       
        else
        if ((int)me->query_skill("liandan", 1) > 30 )
        {
           message_vision(HIY"只见炉中火气似乎不足，$N连忙将内功逼入炉中助火。\n"NOR,me); 
           message_vision(HIY"不一会儿灵丹已成。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan8[random(15)]);
           ob->move(me);
           ob->set("yaocao",1);
           me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
           return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的炼丹吧！\n");
        return 1;
}


int do_put(string arg)
{
	mixed no_drop;
 object obj;object me;
 me=this_player();
	if(!arg) return notify_fail("你要放什么东西到药炉中？\n");
		if( !objectp(obj = present(arg, me)) )
			return notify_fail("你身上没有这样东西。\n");

	if( me->is_busy() )
		return notify_fail("你正在忙呢!\n");

	
	if( obj->query_temp("is_rided_by") == me)
		return notify_fail( obj->name() + "不是正被你骑着。\n");
	if( !obj->query("yaocao") )
		return notify_fail( obj->name() + "这样东西不能合成丹药。\n");

	if( userp(obj) )
		return notify_fail( obj->name() + "这样东西不能合成丹药。\n");

    me->add_temp("liandanyc",1);
        message_vision("$N将"+obj->query("name")+"放进炉中。\n"NOR,me); 
        me->start_busy(2); 
   	destruct(obj);    
		return 1;
}


int do_hc(object ob)
{
        object me=this_player(); 
 
        if (!me->query_temp("liandanyc"))
                return notify_fail("你没有放入药材，合成什么啊？。\n");
        	if( me->is_busy() )
		return notify_fail("你正在忙呢!\n");
		         
        if ( (int)me->query("jing")<50)
                return notify_fail("你的精力不足，无法合成。\n");

        if ( (int)me->query("qi")<50)
                return notify_fail("你的体不足，无法合成。\n");

        if ( (int)me->query("neili")<100)
                return notify_fail("你的内力不足，无法合成。\n");
        message_vision(HIY"$N打足精神 盘腿做下，点起火炉开始炼丹。\n"NOR,me); 

        message_vision(HIY"$N盘腿做下，点起火炉开始合成丹药。\n"NOR,me); 
        destruct(ob);
        me->add("jing",-30);
        me->add("qi",-30);
        me->add("neili",-50);
        me->start_busy(9); 
       	call_out("liandan3",6,me);
        return 1;


}




int liandan3(object me)
{
        object ob;
string file;
string *roomlines;
string location;
file = read_file("/clone/medicine/yc2ok");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           message_vision(HIY"$N对不慌不忙的将内力注入炉中,开始合成丹药。\n"NOR,me); 
           message_vision(HIY"不一会儿药炉中的丹药已经成形。\n"NOR,me);
           me->add("combat_exp",40+random(20));
           me->add("potential",20+random(5));
           ob=new(dan2[random(2)]);
           ob = new(location);
           //message_vision(HIY"$N"+(int)me->query_temp("liandanyc")+","+(int)ob->query("lev")+"。\n"NOR,me); 

if ((int)me->query_temp("liandanyc") >= (int)ob->query("lev"))
{
           ob->move(me);
           ob->set("yaocao",1);
           message_vision(HIY"$N合成得到了"+ob->query("name")+"。\n"NOR,me); 
me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
}
else
{
message_vision(HIR"$N放入的药材过少，合成失败了!\n"NOR,me); 
destruct(ob);
}           	

if ((int)me->query_skill("poison",1) >= 80 || (int)me->query_skill("duji",1) >= 80)
{
if (random(6)==0) 
{
file = read_file("/clone/medicine/yc2du");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];	
           ob = new(location);
if ((int)me->query_temp("liandanyc") >= (int)ob->query("lev"))
{
           ob->move(me);
           ob->set("yaocao",1);
           message_vision(HIY"$N使用毒技合成得到了"+ob->query("name")+"。\n"NOR,me); 
me->improve_skill("liandan", (int)me->query_skill("liandan", 1));       
}
else
{
message_vision(HIR"$N放入的药材过少，合成失败了!\n"NOR,me); 
destruct(ob);
}           	



}
}

           me->set_temp("liandanyc",0);
           me->delete_temp("liandanyc");
           
           return 1;
} 
