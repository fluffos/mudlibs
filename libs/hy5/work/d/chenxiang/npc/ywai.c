 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("贾员外", ({ "jia" }) );
        set("gender", "男性" );
        set("title","一毛不拔");
        set("age", 47);
        set("long", "贾员外生性极其小气，他的卧龙馆内院从来就不肯让人进入，
生怕别人偷他的东西。贾员外体态臃肿，肚子上就象是扣了锅盖似的。
他背部很高，好象有点驼背。\n");
        set("combat_exp", 10000);
        setup();
        carry_object(__DIR__"obj/jcloth")->wear();
} 
int cure_arong(object me)
{
        if (query("cured")){
                command("say 我没灾没病，你瞎忙乎什么？");
                return 1;
        }
        if (me->query_temp("marks/cured_jia")) {
                command("say 自从你上次替我治过后，我已经好多了。");
                return 1;
        }
        
        if (!me->query_temp("marks/cured_monk")) {
                        message_vision("贾员外说：“慢来慢来，你这个东西灵不灵啊，别把我当试验品！”\n",this_object());
                        tell_object(me,"贾员外不愿意让你治疗。\n");
                        return 1;
        }
        tell_object(me,"贾员外背部上的大瘤子越来越小，慢慢消失了．．．\n");
        tell_object(me,"贾员外高兴地道：太好了，你真是我的大恩人呀！\n");
        me->set_temp("marks/cured_jia",1);
        tell_object(me,"贾员外道：今天我破例让你到我家的内院去玩玩！\n\n\n");
        set("long","贾员外生性极其小气，他的卧龙馆内院从来就不肯让人进入，
生怕别人偷他的东西。贾员外体态臃肿，肚子上就象是扣了锅盖似的。\n");
        set("cured",1);
   return 1; 
}
