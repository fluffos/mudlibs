// yhzzyahoo 2015.6.17 
#include <ansi.h>
inherit ITEM;
string *specialsk=({
    "corporeity","ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","spirituality","athanasy","intellect","constitution","perceive","lucky",   
    });      
    
/*string *specialsk_cn=({
    "固本培元","铜皮铁骨","气息悠长","聚精会神","金蝉脱壳","长袖善舞","饕餮之力","身轻如燕",
    "力大无穷","灵气逼人","凤凰涅磐","聪明睿智","镇蕴七星","传音搜魂","洪福齐天",   
    });      

string random_special(object who);
*/
void init()
{
	add_action("do_tunfu", "tunfu");
}

void create()
{
	set_name(HIR"特质洗炼丹"NOR, ({ "tezhi xiliandan"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一颗黑黝黝的丹药(据说是北侠神秘人物所炼)，散发着一阵阵恶臭味，你真的想要吞服(tunfu)它?\n");
			set("unit", "颗");
		}
}

int do_tunfu(string arg)
{
   int i,s_lv,lv_point;//

    object me=this_player();
    if (! id(arg))
          return notify_fail("你要吞服什么？\n");


    /*if (this_object()->query("owner")!=me->query("id"))
    {
		me->set("food",0);
        tell_object(me,"你好不容易吞下了这颗丹药。\n你感到一阵恶心，哇哇吐了起来。别人的东西你也敢吃，不怕被毒死啊！\n");
		destruct(this_object());
		return 1;
    }*/
   // tell_object(me,"你准备新添一个特技了！\n"); 
   if (sizeof(me->query("special_skill"))>10)
   {
		return notify_fail("你的特技太多了，导致服务器计算混乱，没法洗点了。\n");
   }
   lv_point=0;
	tell_object(me,"你忍着恶臭吞下了丹药。\n你肚中一阵翻滚，再也忍受不住，哇哇狂吐了起来。\n吐完以后你发现身上轻松了很多，感到从未有过的清爽。\n");
	for (i=0;i<15;i++)
	{	s_lv=me->query("special_level/"+specialsk[i]);
		if (s_lv>1)
		{
			lv_point+=s_lv-1;
			me->set("special_level/"+specialsk[i],1);
			tell_object(me,"你的"+HIG+specialsk[i]+NOR+"特技等级被置一了。\n");		
		}
	}
	me->set("food",0);
	me->add("special/levelup_point",lv_point);
	tell_object(me,"你现在有特技升级点数"+me->query("special/levelup_point")+"点。\n");
	me->save();
    CHANNEL_D->do_channel(this_object(), "jh", "小道消息："+me->query("name")+"服食某位大神特制神丹,欲仙欲死。\n",-1);
	destruct(this_object());
	return 1;
}

/*string random_special(object who)
{
        string msg;
        while(1)
        {
         msg=specialsk[random(sizeof(specialsk))];
         if(who->query("special_skill/"+msg)) continue;
         break;
        } 
        return msg;    
}
*/
