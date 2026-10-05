#include <../under.h>
 
#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name")
#define BANDAGED(x)  x->query_temp("bandaged")
 
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(18);
        set_name( "Doctor Hwa", "牧马关军医 华驼" );
        add ("id", ({ "hwa" }) );
        set_short( "牧马关军医 华驼" );
        set_long( @C_LONG
华驼是个驼背的老头子，年纪虽大，两眼却炯炯有神，瞪得你有些心寒。他现在是
牧马关的军医，每天照顾在操练和工事中受伤的士兵，虽然很忙碌，他却工作的十
分愉快。如果你跟他熟的话，也许他会愿意帮你包扎。
C_LONG
        );
    set( "alignment",3000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
    set_perm_stat( "dex", 20 );
    set_perm_stat( "str", 15 );
    set_perm_stat( "int", 25 );
    set_perm_stat( "con", 25 );
    set_perm_stat( "kar", 25 );
    set_perm_stat( "pie", 25 );
    set_skill("dagger",90);
    set_skill( "bandage",95);
    set_skill("anatomlogy",100);
    set ("max_hp", 1000);
    set ("hit_points",1000);
    set ("wealth", ([ "gold": 500 ]) );
    set_natural_weapon( 38, 25, 35 );
    set_natural_armor( 68, 62 );
    set ("aim_difficulty", ([ "critical":75, "weakest":75, "ganglion":75,"vascular":75]));
    set ("special_defense", ([ "all":50 ]) );
    set ("stun_difficulty",50);
    set ("weight", 400);
    set ("exp_reward",28000 );
    wield_weapon(OBJS"needle");
    equip_armor(OBJS"ribbon");
    equip_armor(OBJS"armband");
    equip_armor(OBJS"robe02");
    set( "inquiry", ([ "bandage":"@@ask_bandage" ]) );
    set( "tactic_func", "my_tactic" );
}
 
void init()
{
   npc::init();
   add_action( "kill_killer", "kill" );
}
 
int kill_killer(string arg)
{
   object killer;
 
   killer = this_player();
   if( arg && present(arg,environment(this_object()))
   && arg != "hwa" )
   {
         if(killer) {
            kill_ob(killer);
            killer->kill_ob(this_object());
            tell_object(killer,
         "华驼狠狠地瞪你一眼，说道: 喂，你竟敢在这里撒野？\n");
            tell_room(  environment(killer),
         "华驼突然拿起手中的匕首刺向"+killer->query("c_name")+
        "......!\n", killer );
     }
   }
}
 
void ask_bandage( object asker )
{
     object ob1;
     if ( (int)asker->query_quest_level("mumar_cooker") < 1 ) {
        tell_object( asker ,
        "华驼说道:你是谁啊, 我为何要帮你包扎咧？\n");
        return ;
     }
     if ( asker==query_attacker() ) {
        tell_object( asker ,
        "华驼怒道:等我再多给你几道伤口，再帮你包扎...\n");
        return ;
     }
     if( !present( "bandage",this_object() ) ) {
        tell_object( asker ,
        "华驼说道:伙夫头跟我提过你，不过我这里的绷带早就用完还没补给呢。\n");
        return ;
     }
     if ( HP(asker)==MAX_HP(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "华驼抬头瞪了你一眼说道:你好好的嘛，耍我啊。\n");
        return ;
     }
     if ( BANDAGED(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "华驼说道: 你想包成木乃伊吗？\n");
        return ;
     }
     command( "bandage "+NAME(asker) );
     command( "pat "+NAME(asker) );
     return ;
}
 
int my_tactic()
{
     object victim;
     int select;
 
     if (!(victim= query_attacker())) return 0;
     select=random(10);
     if ( select > 6 ) set("aiming_loc","critical");
     else if ( select > 4 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
        if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
        else set("aiming_loc","vascular");
     }
     return 0;
}
