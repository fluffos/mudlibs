//gift十强赛

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIW"大白兔"NOR,({"da baitu","gift"}));
        set("long","一颗大白兔奶糖，糖纸上印着一只胖胖的大白兔子，看起来一定很好吃！\n"
        );
        set("value",0);
        set_weight(10);
        set("no_store",1);
        set("no_sell",1);        
		set("unit","块");
        setup();
}

void init()
{
		if(environment(this_object())==this_player())
                add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object me=this_player();
        int i,oldlevel,addlevel;
        string *sname;
        mapping skill_status;
        
        if(!arg) return 0;
        if(arg!="da baitu"&&arg!="gift") return 0;
        if (me->query("gift/200661") > 1)
        	return notify_fail("你已经吃过了两次大白兔或者粽子了，吃多了对身体不好！\n");
        message_vision(HIC"过六一了，$N的节日到了，$N高高兴兴地拿出梦想已久的六一节礼物－"HIW"大白兔"HIC"，一口吞了下去。\n"NOR,me);
        if (random(50)==1)
        {
        	shout(HIR + me->name() + "吃到了" + HIW + "精品大白兔"+ HIR + "，人品增加一点！\n");
        	me->add("kar",1);
        	me->add("xiantian/kar/200661",1);
        }
        me->add("combat_exp",2000+random(500));
        me->add("potential",200+random(100));
        if ( mapp(skill_status = me->query_skills()) ) {
        	skill_status = me->query_skills();
        	if (sizeof(skill_status) !=0)
        	{
	        	sname  = keys(skill_status);
	
				i = random(sizeof(sname));
				oldlevel = me->query_skill(sname[i],1);
				addlevel = random(5) + 1;
				me->set_skill(sname[i], oldlevel + addlevel,1);
		    	tell_object(me,HIR"你的" + to_chinese(sname[i]) + "增加了" + to_chinese(addlevel) + "级！\n"+NOR);
	        }
		} 
    	tell_object(me,HIW"你的经验增加了！\n"HIM"你的潜能增加了！\n"NOR);
    	me->add("gift/200661",1);
        me->save();
        destruct(this_object());
        return 1;
}
