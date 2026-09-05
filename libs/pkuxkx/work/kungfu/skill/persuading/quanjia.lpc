// quanjia.c
// 峨嵋的劝架
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
        int sp,dp;      
        int damage;
        string msg;
         object ob; 
        object obj; 
        mapping myfam, vtfam;                
        object where = environment(me);
        
        seteuid(getuid());

        if ((!(myfam = me->query("family"))||myfam["family_name"] != "峨嵋派"))
        return notify_fail("只有峨嵋派才能用渡世济人！\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("这里没有人打斗！\n");

        if( me->query_temp("dushi") )
                return notify_fail("你已经在劝人家罢斗了！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("你想找的对象不在这里。\n");
        if (me == target)
            return notify_fail("你总不能劝自己不打架吧，也不看看........\n");
            
        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("( 你不是在忙着吗，还有空劝架？。)\n");
        
        if( me->is_fighting() )
                return notify_fail("你自己还在打斗居然还要去劝别人不打架？你真是虚伪到家了！\n");
                                
        if( !living(target) || !objectp(target))
                return notify_fail("你要劝谁罢斗？\n");

        if( !target->is_fighting() )
                return notify_fail("人家没在打斗啊？\n");
                
        if ((vtfam = target->query("family")) && vtfam["family_name"] == "峨嵋派" )
                return notify_fail("你不能向本派的使用渡世济人！\n");

        if( !wizardp(me) && wizardp(target) )
                return notify_fail("玩家不能劝巫师罢斗。\n");
                    
        sp = (int)me->query_skill("persuading",1) + (int)me->query("int") * 5;
        
        if( sp < 1 ) sp = 1;
        dp = (int)target->query("jing");

        tell_object(me, "你摇摇了头，慢慢地向" + target->name() + "走过去，双手合十，开始念诵佛经"
                        + "...\n\n");
        tell_object(target, me->name() + "摇摇了头向你慢慢走过来，双手合十，说道：我佛慈悲普度渡众生, 还请" + RANK_D->query_respect(target) + "罢斗, 免增罪孽吧 ...！\n\n");

        message("vision", "只见" + me->name() + "摇摇了头，慢慢地向" 
                + target->name() + "走过去，\n出双手合十，说道: 请"
                + RANK_D->query_respect(target) + "，停手吧 ...\n\n", environment(me), ({ me, target }) );

        me->set_temp("dushi", 1);
        call_out( "compelete_dushi", 3, me, target, ob, sp, dp);

        return 1;
}

protected void compelete_dushi(object me, object target, object ob, int sp, int dp)
{
        int amount;
        object ob1;
        object where = environment(me);

        me->delete_temp("dushi");

        if( environment(target) != environment(me) ) {
                tell_object(me, "太可惜了，你要找的人已经走了。\n");
                return;
        }

        if( living(target) && (random(sp+dp) > dp) ) 
        {
                target ->remove_all_enemy();
                tell_object(me, target->name() + "低头想了一会，又看了看你，摇摇头，叹了口气，停止了打斗。\n");
                tell_object(target, "你听了之后，心中不觉一紧，不再想继续打下去了。\n");

                me->improve_skill("persuading", 2 * random(me->query("int")));
                if(((int)me->query("learned_points") + 120) > (int)me->query("potential"))
                me->add("potential",2);
                me->add("combat_exp",5);
                me->start_busy(3);
        } 
        else 
        {
                if( random(sp) > dp/2 ) {
                        message_vision(target->name() + "狠狠地瞪了$N一眼，喝道：我都快让人给打死了，能罢斗吗! $N叹了口气转身走开了。\n", me);
                        return;
                }
        
                tell_object(me, target->name() + "扭过头去，对你理都不理。\n");
                tell_object(target, "你扭过头去，对" + me->name() + "理都不理。\n");
                message("vision", target->name() + "扭过头去，对" + me->name() + "理都不理。\n", 
                        environment(me), ({ me, target }) );

        }
}
