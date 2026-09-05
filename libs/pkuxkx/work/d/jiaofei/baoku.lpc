inherit ROOM;
#include <ansi.h>
#include <title.h>
string *specialsk=({
    "corporeity","ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","spirituality","athanasy","intellect","constitution","perceive","lucky",   
    });      
    
string *specialsk_cn=({
    "固本培元","铜皮铁骨","气息悠长","聚精会神","金蝉脱壳","长袖善舞","饕餮之力","身轻如燕",
    "力大无穷","灵气逼人","凤凰涅磐","聪明睿智","镇蕴七星","传音搜魂","洪福齐天",   
    });      
        
string random_special(object who);

void create()
{
	set("short", "宝库");
	set("long", @LONG
匪帮的藏宝库，遍地都是珍宝！令人目不暇接，有些人已经开始蠢蠢欲动了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		  "south" : __DIR__"zshanding",
		]));
	set("no_clean_up",1);
	set("no_reset",1);
}

int isbaoku()
{
    return 1;
}

void init()
{
    object me = this_player();
    string respect_name;
    string special_skill,special_skill_cn;
    string bakname,bakid;
    
	add_action("do_get","get");

	// 增加限制，6天内已经进过宝库的，不执行后面的代码（会增加完成次数）
	// 防止同一次剿匪期间来回进出宝库而累积计算多次完成次数。by lordstar 20171117
	if ( time() - (int)me->query("jiaofei/last_time") < 6*3600*24 )
		return ;

	//如果是剿匪成功进入，给他增加成功次数
    if(me->query_temp("jiaofei/hero")==1)
    {
        JIAOFEI_D->announce(sprintf("%s忠肝义胆，神功盖世，直捣黄龙，杀入铁掌帮宝库！",me->query("name")), "bd");
        me->add("jiaofei/succ_times",1);
        if(me->query_temp("jiaofei/difficulty") >= 100)
        {
            me->add("jiaofei/succ_times_1",1);
            if(me->query_temp("jiaofei/difficulty") >= 150)
            {
                me->add("jiaofei/succ_times_2",1);
                if(me->query_temp("jiaofei/difficulty") >= 200)
                {
                    me->add("jiaofei/succ_times_3",1);
                }
            }
        }
        me->delete_temp("jiaofei/hero");
        me->delete_temp("jiaofei/difficulty");
		// 增加一个进宝库的时间戳。by lordstar 20171117
		me->set("jiaofei/last_time", time());
    }
    
    if(me->query("jiaofei/succ_times_1") >= 100 && !me->query("jiaofei/enter100_1"))
    {
        special_skill = random_special(me);
        special_skill_cn = specialsk_cn[member_array(special_skill,specialsk)];
                         
        if(me->query("gender") == "女性") respect_name = "侠女";
        else if(me->query("gender") == "男性") respect_name = "侠客";
        else respect_name = "公公";
        message_vision(HIW"一名须发皆白的老者蓦然出现在$N面前，面含赞许之色：这位"+respect_name+"英雄了得，命格不凡，来日定可领袖武林，可堪栽培！\n"NOR,me);        
        message_vision(HIW"老者在$N身上各处大穴飞指疾点，一阵紫气沿着$N的奇经八脉飞速流转，转瞬间居然突破阴阳经脉的隔阂，$N全身都笼罩在紫气当中。\n"NOR,me);
        message_vision(HIW"$N身躯猛然一震，吐气发音，长啸之下，内力雄浑无比，显然境界有了重大突破！\n"NOR,me);
        message_vision(HIW"老者说道，老夫今日再传$N"+special_skill_cn+"之术！望$N好生运用。从今往后，$N就以【"+HIY"一代真龙"NOR+HIW"】的名号行走江湖吧。\n"NOR,me);
        me->set("jiaofei/enter100_1",1);
		//奖励cut by yhzzyahoo,由各5 cut到3,3,4,5
        me->add("str",random(3)+1);
        me->add("int",random(3)+1);
        me->add("con",random(4)+1);
        me->add("dex",random(5)+1);
        me->add("kar",random(5)+1);
        me->add("spi",random(5)+1);
        me->set("title",HIY"一代真龙"NOR);
		//title系统记录玩家title by seagate@pkuxkx
		me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIY"一代真龙"NOR);
        me->set("yidaizhenlong",1);

        me->uncover_mask();
        bakname = me->query("name");
        bakid = me->query("id");
        
        me->set("name","天下第一");
        me->set("id","The Master");
        CHANNEL_D->do_channel(me, "bd", HIY"一代真龙"NOR+bakname+"，乃老夫亲传弟子，号令天下，不从者，杀。");
        me->set("name",bakname);
        me->set("id",bakid);
        CHANNEL_D->do_channel(me, "bd", HIY"一代真龙"NOR+"出，万雄莫争鸣。");        
        tell_object(me,"你的声望提高了一百万！\n");
        me->add("repute",1000000);    
        tell_object(me,"你的潜能提高了一百万！\n");
        me->add("potential",1000000); 
        tell_object(me,"你的经验提高了一千万！\n");
        me->add("combat_exp",10000000);
        tell_object(me,"你学会了"+special_skill_cn+"！\n");        
        me->set("special_skill/"+special_skill,1);
    }
}

int do_get()
{
	object me = this_player();
	if(me->query_temp("jiaofei/score") <= 0)
	{
		write("你感觉周围人的目光一下都落在了你的身上：一个土匪没杀也好意思拿这里的宝物吗？\r\n");
		return 1;
	}
	return 0;
}

string random_special(object who)
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
