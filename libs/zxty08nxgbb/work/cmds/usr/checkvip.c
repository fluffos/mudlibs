#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        int lvl;
        int n;


         if (!me->query("vipshop"))
               return notify_fail("你所有装备都未开光,请及时开光!news 499！\n");
        if (me->query("vipshop/jiasha")){
                tell_object(me, HIG "你的圣僧袈裟(Jia sha)已经开光过了。\n"); }
        if (me->query("vipshop/yuyi")){
                tell_object(me, HIG "你的风彩羽衣(Fengcai cloth)已经开光过了。\n"); }
        if (me->query("vipshop/ring")){
                tell_object(me, HIG "你的逍遥指(Xiaoyao ring)已经开光过了。\n"); }
        if (me->query("vipshop/shoe")){
                tell_object(me, HIG "你的千里靴(Qianli shoes)已经开光过了。\n"); }
        if (me->query("vipshop/jiasha")){
                tell_object(me, HIG "你的圣僧袈裟(Jia sha)已经开光过了。\n"); }
        if (me->query("vipshop/yaodai")){
                tell_object(me, HIG "你的黄金腰带(Huangjin yaodai)已经开光过了。\n"); }
        if (me->query("vipshop/toukui")){
                tell_object(me, HIG "你的狮王头盔(Shiwang toukui)已经开光过了。\n"); }
        if (me->query("vipshop/xianglian")){
                tell_object(me, HIG "你的法藤项圈(Fateng necklace)已经开光过了。\n"); }
        if (me->query("vipshop/huwan")){
                tell_object(me, HIG "你的真龙护腕(Wrists)已经开光过了。\n"); }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : checkvip

查询装备是否已经开光!
 
HELP );
        return 1;
}


