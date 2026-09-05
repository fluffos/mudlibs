//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#include "/d/yingtianfu/neicheng/royal_area_access.h"
string look_bang();
#define NAME HIR"皇榜"HIY
#define NAME2 HIR"大明"HIY
#define HEADER HIY"┏━━━━━━━━━━━━━━━━"+NAME+"━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   HIY"┗━━━━━━━━━━━━━━━━"+NAME2+"━━━━━━━━━━━━━━━━┛\n"NOR

void create()
{
        set("short", HIY"奉天殿"NOR);
        set("long", 
"这里就是皇宫前的正殿——奉天殿。殿旁贴着一张皇榜(bang)，作为公示官员\n功绩之所在。\n"

        );
        set("item_desc", ([
		"bang" : (:look_bang:),
	    ]));
        set("exits", ([
                
              
                
                "north" : __DIR__"yudao5",
                "south" : __DIR__"fengtianmen",
                
                
                
        ]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

string look_bang()
{
    object me=this_player();
    string msg,per;
    if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
    {
        return "山野村夫也敢来到皇宫？\n";
    }
    else
    {
        if (me->query("mingpin"))
        {
            per=HIR+"   大明  "+chinese_number(me->query("mingpin"))+"品官员"+HIW+me->query("name")+HIR+"自加入大明后，累计功勋"+chinese_number(me->query("ming/credit"))+"点。\n"+NOR;
            msg="\n\n";
            msg+=HEADER;
           
            msg+=per;
            msg+=TAIL;
            return msg;
        }
        if (me->query("ming/tj/pin"))
        {
            per=HIR+"   大明  内廷"+chinese_number(me->query("ming/tj/pin"))+"品太监"+HIW+me->query("name")+HIR+"自入宫后，累计功勋"+chinese_number(me->query("ming/credit"))+"点。\n"+NOR;
            msg="\n\n";
            msg+=HEADER;
           
            msg+=per;
            msg+=TAIL;
            return msg;
        }
        else
        {
            return "山野村夫也敢来到皇宫？\n";
        }
    }
}

int yizhang(object me)
{
    if (me)
    {
        me->delete_temp("等仪仗");
    }
    return 1;
}

void init()
{
    object yizhang;
    object me=this_player();
    if (me->query_temp("mingtasks/sishe/task")==1&&!me->query_temp("mingtasks/sishe/yizhangout"))
    {
        if (random(100)>65 &&!me->query_temp("等仪仗"))
        {
            yizhang=new(__DIR__"obj/yizhang");
            yizhang->move(this_object());
            me->set_temp("mingtasks/sishe/yizhangout",1);
            tell_object(me,"皇帝的出行队伍到了，你赶紧跟上(join)吧。\n");
            return;
        }
        else
        {
            tell_object(me,"你左等右等并没有任何人过来，还是先去别的地方看看吧。\n");
            me->set_temp("等仪仗",1);
            remove_call_out("yizhang");
            call_out("yizhang",5,me);
            return;
        }
    }
    add_action("do_join","join");
}

int valid_leave(object me,string dir)
{  
    object* inv,guard;    
    int i;
    inv = deep_inventory(me);
	if (dir=="north")
    {
		for(i=sizeof(inv)-1; i>=0; i--)
		{
			if(userp(inv[i]))
			{
				me->unconcious();
				return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！\n"NOR);
			}
		}
        if (!me->query("mingpin")&&!me->query("ming/tj/pin")&& !present("entry permit",me))
        {
            return notify_fail("你不是大明官员也不是内廷官员，皇城岂可随意进入。\n");
        }
		if (forbid(me)==1&&!identification(me,"御前侍卫统领")&&!identification(me,"御林军统领"))
		{
			return notify_fail("此刻你被御林军统领禁止进入皇城！\n");
		}
		guard=present("yuqian shiwei",this_object());
        if (me->query("mingpin")>1||(me->query("ming/tj/pin")>4&&!me->query("ming/tj/zhuguan") && !me->query_temp("mingtasks/sishe/yizhangout")))
        {
			if (identification(me,"御前侍卫统领")||identification(me,"御林军统领"))
            {
				if (guard)
				guard->bow(me);
                return ::valid_leave(me, dir);
            }
			if (permit(me)==1)
			{
				for(i=sizeof(inv)-1; i>=0; i--)
				{
					if(userp(inv[i]))
					{
						me->unconcious();
						return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！”\n"NOR);
					}
				}
				if (guard)
				{
					guard->bow3(me);
				}
				return ::valid_leave(me,dir);
			}
            return notify_fail("天子近臣以及各监正官之外，无诏不得进入皇帝寝宫！\n");
        }
    }
	if (guard)
	guard->bow2(me);
	return ::valid_leave(me, dir);
}

