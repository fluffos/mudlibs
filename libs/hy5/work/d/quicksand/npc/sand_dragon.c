#include <ansi.h>
int dragon_attack();
int dragonstun();
int dragonclaw();
int dragonbreath ();
int dragonblow (); 
 inherit NPC;
void create()
{
        set_name("沙海蛰龙", ({ "hibernating dragon", "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("long", "这本是一条在海底修炼的神龙。因为沧海桑田的变迁，原来的翰海变成
了沙漠。它在这里蛰伏下来，也不知道有几千几万年了。 \n");
        set("limbs", ({ "龙头", "龙身", "龙尾", "龙爪","龙角", "龙须","龙背" }) );
        set("verbs", ({ "dragonbite","dragonslash","dragonswing","dragonthrow","dragonbreath","dragonpoke" }) );
        
        set("combat_exp", 15000000);
        
        set("cor", 80);
        set("cps", 80);
        set("con",40);
        set("fle",40);
        set("dur",40);
        set("agi",40);
        set("int",80);
        set("age",10000000);
        set("no_curse",1);
        set("str",90);
        set("boss",1);
        
        set("max_qi", 500000);
        set("max_jing", 300000);
        set("max_neili", 300000);
          set("combat_exp", 19000000+random(2000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 900+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),
 (: perform_action, "unarmed.yaoyao" :),
 
    (: perform_action, "unarmed.tuwu" :),

 }) );
       
        
        set_temp("apply/attack",360);
        set_temp("apply/damage",300);
        set_temp("apply/armor", 340);
        set_temp("apply/dodge",360); 


        
        set("chat_chance",1);
        set("chat_msg",({
        }) );   
        set_temp("apply/attack", 800);
        set_temp("apply/armor",  200);
        set_temp("apply/dodge",  600);
        set_temp("apply/damage", 50);
        setup();
}  
int dragon_attack(){
        if (random(2)) dragonstun();
        else if (time()>query("dragon/breath")+10) dragonbreath();
        return 1;
}  
int dragonbreath ()     {
        message_vision(HIR"\n\n$N身上忽然发出淡淡的红光，转瞬间，光芒越来越强烈。。。\n\n"NOR,
                        this_object());
        call_out("hurting",8);
        set("dragon/breath",time());
        return 1;
} 
int hurting()   {
        int i,dam;
        object *inv;
        message_vision(HIR"\n\n$N一张嘴，无数道烈焰迎面向你扑来，闪无可闪，避无可避。\n\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
                if( living(inv[i]))
                if( inv[i]!= this_object()){
                        dam = 2000+random(3000);
                        inv[i]->receive_wound("qi",dam);
                        COMBAT_D->report_status(inv[i]);
                }
        return 1;
}  
int dragonblow()   {
}  
int dragonstun()        {
        int i,dam;
        object *inv;
        message_vision(HIW"\n\n$N忽直立而起，又重重跃下，天摇地动，沙穴震颤。。。。\n\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
                if( living(inv[i]))
                if( inv[i]!= this_object()){
                        if (random(this_object()->query("combat_exp"))*5<inv[i]->query("combat_exp"))
                                continue;
                        if (inv[i]->query_busy()<4) inv[i]->start_busy(4);
                        message_vision(YEL"$N只觉心胆俱裂，目瞪口呆，动弹不得。\n"NOR,inv[i]);
                }
        return 1;
}  
int dragonclaw()        {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        ob->set("bite_time",time());
        enemy=ob->query_enemy();
        me=enemy[random(sizeof(enemy))];
        message_vision(HIG"\n$N举起巨灵般的前爪，挟风雷之势，迅急地向$n的头部一抓。\n"NOR,ob,me);
        me->receive_wound("qi",2000+random(2000));
        COMBAT_D->report_status(me);
        if (ob->query_busy()<3) ob->start_busy(2);
        return 1;
}  
void die()
{
        object rstone, me,owner,money_reward,skin;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        environment(this_object())->set("dragon_death",time());
   if(objectp(me)) { 
                if(!me->query("m_success/蛰龙赤丹")){
                        CHANNEL_D->do_sys_channel("info","一个新的武林神话的诞生。。。。");
                        CHANNEL_D->do_sys_channel("info",sprintf("%s，%s于%s%s%s。", NATURE_D->game_time(),
                                me->query("name"), environment(this_object())->query("short"),"斩杀", name())); 
                        me->set("m_success/蛰龙赤丹",1);
                        me->add("score",300);
                        me->add("combat_exp",50000);
                        me->add("potential", 10000);
                        money_reward = new("/clone/money/gold");
                        money_reward->set_amount(300);
                        money_reward ->move(me);
                        tell_object(me,WHT"恭喜你杀死了沙海蛰龙，你被奖励了!!!\n"NOR);
                        tell_object(me,WHT"\n你的智慧和勇敢将在武林中传颂。\n\n"NOR);
                }
                rstone = new(__DIR__"obj/rstone");
                skin= new(__DIR__"obj/skin");
                if (objectp(rstone)) {
                        message_vision(HIR"\n一点红光从沙海蛰龙双目间落下刚好掉入$n手中。\n"NOR, this_object(), me);
                        rstone->move(me);
                        skin->move(this_object());
                        me->set("stone_mark/rstone", 1);
                        
                }
        } 
        environment(this_object())->tell_exit();        
        ::die();
}    
