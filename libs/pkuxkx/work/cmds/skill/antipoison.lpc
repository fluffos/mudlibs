// 祛毒 by whuan@pkuxkx
#include <ansi.h>
inherit F_CLEAN_UP;

mapping *poisons = ({
        ([  "name": "s_poison",    "cname":"断肠散之毒  ",     "base_amount":1 ]),    //断肠散之毒
        ([  "name": "bt_poison",   "cname":"白驼蛇毒    ",     "base_amount":1 ]),    //白驼蛇毒
        ([  "name": "rose_poison", "cname":"火玫瑰之毒  ",     "base_amount":2 ]),    //火玫瑰之毒
        ([  "name": "san_poison",  "cname":"断肠散之毒  ",     "base_amount":2 ]),    //断肠散之毒 
        ([  "name": "snake_poison","cname":"蛇毒        ",     "base_amount":1 ]),    //蛇毒 
        ([  "name": "sanxiao_poison","cname":"三笑逍遥散",     "base_amount":3 ]),    //三笑逍遥散
        ([  "name": "slumber_drug","cname":"蒙汗药      ",     "base_amount":1 ]),	  //蒙汗药
        ([  "name": "fs_poison",   "cname":"腐尸之毒    ",     "base_amount":3 ]),    //腐尸之毒
        ([  "name": "bing_poison", "cname":"冰魄银针    ",     "base_amount":1 ]),    //冰魄银针
        ([  "name": "ss_poison",   "cname":"生死符      ",     "base_amount":2 ]),    //生死符
        ([  "name": "xxx_poison",  "cname":"冰魄寒毒    ",     "base_amount":2 ]),    //冰魄寒毒
        ([  "name": "xx_poison",   "cname":"星宿毒掌之毒",     "base_amount":2 ]),    //星宿毒掌
        ([  "name": "yf_condition","cname":"玉蜂针之毒  ",     "base_amount":2 ]),    //玉蜂针
        ([  "name": "anran_poison","cname":"情毒        ",     "base_amount":3 ]),    //情毒 
        ([  "name": "qishang",     "cname":"七伤拳伤心脉",     "base_amount":30]),    //情毒                                                                                            
        ([  "name": "nx_zhua",     "cname":"凝血神爪之毒",     "base_amount":3 ]),    //凝血神爪之毒
         });

int main(object me)
{
        int i,total,duration,amount;
        mapping poison;
        
        if ((int)me->query("special_skill/energy")<1 && !wizardp(me))
            return notify_fail("你似乎没有这项能力！\n");
            
        if (me->is_busy())
        	  return notify_fail("你忙着呢！\n");    

	      if( (int)me->query("neili") < 150 )
		        return notify_fail("你的真气不够。\n");

	      if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
		        return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");   
		             	      
        if(!wizardp(me) && time()-me->query_temp("qudu_time") < 30)
                return notify_fail("你刚刚祛过毒，真气尚未恢复。\n");
        me->set_temp("qudu_time",time());
                	  
        total=0;
        for(i=0;i<sizeof(poisons);i++) 
        {
            poison=poisons[i];
            duration=me->query_condition(poison["name"]);
            if(duration>0) 
            {
                    amount=poison["base_amount"];
                    total+=amount;
            }       
        }
        if (total==0 )
        	 if (!me->update_condition())
        	 return notify_fail("你根本就没有中毒！\n"); 
        	 else
        	 return notify_fail("你也许中了一种很奇怪的毒，是你无法解的。\n");
        
        //运功开始的描述
        message_vision("$N紧闭双目默运玄功，深吸一口长气，当下脸白如纸，一股真力由丹田缓缓发出搜向各大经脉，开始驱除毒素。\n",me); 
        //解毒代码
        for(i=0;i<sizeof(poisons);i++) 
        {
                poison=poisons[i];
                duration=me->query_condition(poison["name"]);
                if(duration>0) 
                {
                        me->apply_condition(poison["name"], 0);
                }
        }        
        //解毒完成     
        message_vision(HIY"$N忽地睁开双目，脸色由白转金，从金做赤，突然大张其口，几块斑斓血块喷在地下。\n"NOR,me);
        me->start_busy(2);
        tell_object(me,CYN"你神清气爽,一身轻松,看来所染毒素已经驱除干净了。\n"NOR); 
        return 1;
}
int help()
{
        write(@LONG
指令格式：antipoison/qudu 

运功祛毒，需要有特定的特技。
LONG
        );
        return 1;
}
