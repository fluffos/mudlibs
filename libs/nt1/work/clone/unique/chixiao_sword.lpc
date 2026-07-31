// Copyright (C) 2003, by Xlz. All rights reserved.  
// This software can not be used, copied, or modified   
// in any form without the written permission from authors.  
// chi-sword.c 赤
// for only one object in mud   

#include <ansi.h>   
#include <weapon.h>   
inherit SWORD;   
inherit F_UNIQUE;   
void create()   
{ 
        set_name(HIR "赤霄剑" NOR, ({"chixiao sword", "chixiao", "sword"}));   
        set_weight(15000); 
        if (clonep())   
                set_default_object(__FILE__);   
        else {
                set("unit", "把");   
                set("long", sort_msg(HIR"秦朝时，有这样一个没有出息、浑身都是毛病的青年。他"
                                     "懒，从来不干家里的农活。好酒，常常醉成一滩烂泥。他好色"
                                     "，见着漂亮姑娘就迈不开腿。他没有礼貌，对官对都大大咧咧"
                                     "。最可气的是他好撒谎，好吹牛。他经常让人看他左腿上的七"
                                     "十二个黑痣，他不说这是皮肤病而说是天相图。他经常遥望咸"
                                     "阳，摇头叹气：嗟乎，大丈夫当如此也。他撒谎越来越离谱。"
                                     "他不知从哪儿弄来一根生锈的铁棍，告诉乡里人说这是一把从"
                                     "南仙人那里得来的宝剑，名字叫：赤霄。他把它奉为至宝，整"
                                     "日“剑”不离身。他还说他己不是人而是天上的一条赤龙。他"
                                     "的牛越吹越大。他说他早就认识始皇帝，始皇帝是龙，他还说"
                                     "始皇帝不如他，因为他是法力更高的赤龙，他将来要取而代之"
                                     "也做皇帝。还说他知道始皇帝的元气已化为一条白蛇最近一段"
                                     "时间正在丰西泽附近游弋。他说他斩去这条白蛇，他边说还边"
                                     "用捡来的铁棍比划了一下。人们都把他的话当笑话、大话没有"
                                     "人相信。可是，在一个晚上，一切都变了。这天晚上，乡里几"
                                     "十个结伴去县里学做工的青年走到了丰西泽，这个青年也在其"
                                     "中，但他不是去做工而是凑热闹，他一边一边掏出酒壶喝酒。"
                                     "这帮人走到丰西泽时停住了脚步，说来也怪，最近，去县城学"
                                     "徒工的人经常有人莫名其妙地消失在丰西泽附近，所以，为保"
                                     "险起见，大家派了一个身敏捷的青年先走几步前去打探，过了"
                                     "一会儿，探子吓得面无人色逃了回来，他说他走了一段路，闻"
                                     "到前面隐隐有腥气，于是爬上一棵大树了望，看见一条硕大的"
                                     "凶恶的白蛇正挡道路中间，象在等待什么。人群大惊失色，再"
                                     "也不敢向前。这时，这个青年分开众人前走去，他说那条白蛇"
                                     "在等他，他要斩了它。他一边说一边拔出铁棍，脚步踉踉跄跄"
                                     "，看来他喝了一路，到现在已经喝醉了。人们屏住呼吸看着他"
                                     "歪歪扭扭远去的背影，心都在说：这个傻小子，一夜过去，这"
                                     "个青年也没有回来，人们知道他一定成了蛇的美餐。云开雾散"
                                     "，大家继续前行。走了一段路，突然，他们看见一条硕大的白"
                                     "蛇，被斩为两段扔在路边。再向前走了几里地，发现这个青年"
                                     "正躺在路边呼呼大睡，他的身体上方有团云气笼罩，云中有条"
                                     "赤龙正在懒懒洋洋地飞来飞去。而手中的那根铁棍不见了，盯"
                                     "睛一看，是一把饰有七彩珠、九华玉的寒光逼人、刃如霜雪的"
                                     "宝剑，剑身上清晰镌刻着两个字：赤霄。这一刻，人们都相信"
                                     "了这个青年原来说的话都是真的。这个青年就是刘邦，这把剑"
                                     "就是斩蛇起义的赤霄剑。赤霄剑是一把帝道之剑。\n"NOR));
        set("value", 100000);  
        set("material", "steel");  
        set("no_sell", "我的天…你…你知道这是啥么？这你也敢拿来卖？");   
        set("unique", 1);     
        set("rigidity", 500);   
        set("replica_ob", "/clone/weapon/changjian");  
        set("no_put",1);
        set("no_steal",1); 
        set("wield_msg",HIR"$N[噌]的一声抽出一把赤剑，忽然从旁边跳出一条赤龙，围着$N转。\n"NOR);   
        set("unwield_msg",HIR"$N把手中的赤剑插入剑鞘，赤龙化做长虹飞到天空，消失了。\n"NOR);    
        } 
        init_sword(900);   
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)  
{ 
        victim->receive_damage("jing", me->query("str") * 2, me);  
        victim->receive_wound("jing", me->query("str") * 2, me);  
        return HIR "赤剑[叮]一声响，霎那，那条赤龙张口就咬$n"  
               HIR "，$n只能冷冷做怕。\n" NOR; 
}
