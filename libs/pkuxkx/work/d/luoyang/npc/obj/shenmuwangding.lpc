// baohe.c 
//by skywolf 2009-2-4 for bingcan-cloth
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("神木王鼎", ({"shenmu wangding","wangding","ding"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"这是星宿派的至宝，点燃（dian）之后可以吸引周围的毒虫，若想修习毒掌，
非他莫属。\n");
                set("unit", "只");
                set_weight( 300);
				set("no_sell",1);
                set("no_beg",1);
        }
}

void init()
{
        add_action("do_dian","dian");
}

int do_dian()
{
	object me = this_player();
	int t;
	if (me->query_temp("bingcan/dian"))
	{
		tell_object(me,"神木王鼎现在正点着呢，再点就烧了！\n");
        return 1;
	}
	message_vision(HIC"$N从怀中取出一个小小布包，打了开来，里面是几块黄色、黑色、紫色的香料。"NOR +"\n",me);
	message_vision(HIC"$N从每一块香料上捏了少许，放于鼎中，用火刀、火石打着了火，烧了起来，然后合起鼎盖，躲在一旁。"NOR +"\n",me);
    me->set_temp("bingcan/dian",1);
	if (!me->query_temp("bingcan/bingcan"))
    {
		tell_object(me,"你等了半天一点动静也没有，看来这不是个能招毒物的地方！\n");
        return 1;
    }
	if (me->query_temp("bingcan/findcan"))
	{
		tell_object(me,"冰蚕都出来了，这地方看来再也没什么毒虫了！\n");
		me->delete_temp("bingcan/dian");
        return 1;
	}
	t=5+random(5)*5;
	me->start_busy(t);
	message_vision("$N摒息凝神，紧张的看着神木王鼎。\n",me);
	call_out("end_dian",5,me);
	return 1;
}
int end_dian(object me)
{
	 if (!objectp(me)) return 1;
     if(me->is_busy())
     {
		message_vision("$N等了半天也不见动静，不由得暗暗心焦！\n",me);
        call_out("end_dian",5,me);
        return 1;
     }
	 else
	{
		message_vision(HIC"直等了一个多时辰，才听得草丛中瑟瑟声响，似有什么蛇虫过来。你连忙伏下身来，只听得声响大作，颇异寻常。\n"NOR,me);
		call_out("show_she",5,me);
		return 1;
	 }
}
int show_she(object me)
{
	message_vision(RED"异声中夹杂着一股中人欲呕的腥臭，你屏息不动，只见长草分开，一条白身黑章的大蟒蛇蜿蜒游至，蟒蛇头作
三角形，头顶上高高生了一个凹凹凸凸的肉瘤。北方蛇虫本少，这蟒昆如些异状，更是众所未见。蟒蛇游到木鼎之旁，
绕鼎团团转动，这蟒蛇身长二丈，粗逾手臂，如何钻得进木鼎之中？但闻到香料及木鼎气息，一颗巨头住用去撞那鼎。\n"NOR,me);
	call_out("show_bingcan",5,me);
	return 1;    
}
int show_bingcan(object me)
{
	message_vision(HIW"便在此时，你忽觉得一阵寒风袭体，只见西角上一条火线烧了过来，顷刻间便浇到了面前。一到近处，看得清楚
原来不是火线，却是草丛中有什么东西爬过来，青草遇到，立变枯焦，同时寒气越来越盛。你退后了几步，只见草丛
枯焦的黄线移向木鼎，却是一条蚕虫。这蚕虫纯白如玉，微带青色，比寻常蚕儿大了一倍有余，便似一条蚯蚓，身子
透明直如水晶,那蟒蛇本来气势汹汹，这时却似乎怕得要命，尽力将一颗三角大头缩到身下面藏了起来。那水晶蚕儿迅
速异常的爬上蟒蛇身子，一路向上爬行，便如一条炽热的炭火一般，在蟒蛇的脊梁上子上烧出了一条焦线，爬到蛇头
时，蟒蛇的长身从中裂而为二，那蚕儿钻入蟒蛇头旁的毒囊，吮吸毒液，顷刻间身子便胀大了不少，远远瞧去，就像
是一个水晶瓶中装满了青紫色的汁液。
\n"NOR,me);
	call_out("escape_bingcan",5,me);
	return 1;
}
int escape_bingcan(object me)
{
	message_vision(HIR"那蚕儿绕着木鼎游了一圈，向鼎上爬去，所经之处，鼎上也刻下了一条焦痕。蚕儿似通灵一般，在鼎上爬了一圈，
似知倘若钻入鼎中，有死无手生，竟不似其余毒物一般入鼎中，又从鼎上爬了下来，向东南而去。 \n"NOR,me);
	me->set_temp("bingcan/findcan",1);
	me->delete_temp("bingcan/dian");
	remove_call_out("del_findcan");
	call_out("del_findcan",3600,me); //一小时后失效
	return 1;
}
int del_findcan(object me)
{
	me->delete_temp("bingcan/findcan");
	return 1;
}