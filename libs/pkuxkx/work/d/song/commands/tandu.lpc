// tandu.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "special_permit.h"
int help(object me);
int main(object me,string arg)
{
    object room=environment(me);
    object baoshi;
    string gem;
    int i,repute,lv;
    string need="tanlan";
    if (arg=="-h")
	return help(me);
	if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (time()-me->query("song/specialtandu")<3600*6)
    {
        tell_object(me,"虽然贪污不会被问斩，频繁使用贪渎还是不好。\n");
        return 1;
    }
    if (me->query("repute")<=300000)
    {
        tell_object(me,"你的声望太低了，这时候再行贪墨之事，当心被朝廷革职查办。\n");
        return 1;
    }
    else
    {
        
            i = random(20);
			if (i < 3) gem = "yan";
			else if (i < 6) gem = "mu";
			else if (i < 9) gem = "sui";
			else if (i < 12) gem = "jin";
			else if (i < 15) gem = "bing";
			else if (i < 16) gem = "gu";
			else if (i < 17) gem = "yu";
			else if (i < 18) gem = "jiao";
			else gem = "jia";
            baoshi = new("/obj/gem/gem");
            baoshi->set_level(7990,9999,gem);
            lv=baoshi->query("level");
            if (lv==1)
            {
                repute=100;
            }
            if (lv==2)
            {
                repute=300;
            }
            if (lv==3)
            {
                repute=900;
            }
            if (lv==4)
            {
                repute=2700;
            }
            if (lv==5)
            {
                repute=8100-random(1000);
            }
            if (lv==6)
            {
                repute=24300-random(4000);
            }
            if (lv==7)
            {
                repute=72900-random(10000);
            }
            if (lv==8)
            {
                repute=218700-random(35000);
            }
            if (me->query("repute")>repute)
            {
                baoshi->move(me);
                me->add("repute",-repute);
                message_vision("$N任上大力搜刮民脂民膏，获得"+baoshi->query("name")+"一枚，其人声望大幅下降。\n",me);
                tell_object(me,"你搜刮到了一枚"+baoshi->query("name")+"。\n");
                tell_object(me,"因为搜刮民脂民膏的行为，你的声望下降了"+chinese_number(repute)+"点。\n");
                me->set("song/specialtandu",time());
                return 1;
            }
		    if (me->query("repute")<=repute)
            {
                repute=me->query("repute")*10;
                me->set("repute",0);
                MONEY_D->pay_player(me,repute);
                tell_object(me,"你吩咐下属搜刮来的钱财已经全部打入你的账上，可惜你的声名变得一塌糊涂。\n");
                me->set("song/specialtandu",time());
                return 1;
            }
            
        }
        return 1;
    
}
int help(object me)
{
    write("
指令格式 : song tandu
贪渎搜刮民脂民膏，需要大宋特技贪婪。
"    );
    return 1;
}
