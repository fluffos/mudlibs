#include <../under.h>
#include <daemons.h>
inherit MONSTER;
inherit DAEMON;
 
void create ()
{
        ::create();
        set_level(19);
        set_name( "General Zhao", "牧马关战将 赵子扬" );
        add ("id", ({ "general", "zhao", }) );
        set_short( "牧马关战将 赵子扬" );
        set_long( @C_LONG
你眼前是一位神态庄严威武的中年男子。他原本是东方大国的大将军，只因犯了皇
上身边的宠宦邓公公，而被贬为牧马关守将。不过他并不为意，依然为国效力，夙夜匪
懈。他现在正在此处监工，以其此工程早日完工。
C_LONG
        );
    set( "alignment",6000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "str", 30 );
    set_perm_stat( "int", 20 );
    set_perm_stat( "con", 25 );
    set_perm_stat( "kar", 25 );
    set_perm_stat( "pie", 25 );
    set ("max_hp", 1500);
    set ("hit_points",1500);
    set ("max_sp", 2000);
    set ("spell_points",2000);
    set ("wealth", ([ "gold": 800 ]) );
    set_natural_weapon( 38, 24, 14 );
    set_natural_armor( 72, 48 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":85, "weakest":85, "ganglion":85,"vascular":85]));
    set ("special_defense", ([ "all":50, "fire":50,"none":50 ]) );
    set ("weight", 400);
    set ("exp_reward",50000 );
    set_skill("polearm",100);
    set_skill("parry",100);
    set_skill("riding",100);
    set_skill("dodge",100);
    set_skill("concentrate",100);
    set ("stun_difficulty",80);
    set ("c_death_msg","\n赵子扬长叹一声：国之将亡～～必有妖孽～～\n\n");
    set ("tactic_func","my_tactic");
    wield_weapon(OBJS"sword");
    equip_armor(OBJS"helmet01");
    equip_armor(OBJS"arm01");
    equip_armor(OBJS"robe01");
    equip_armor(OBJS"mirror01");
}
 
int my_tactic()
{
     object victim;
     int select;
 
     if (!(victim= query_attacker())) return 0;
     if ( victim->query_temp("leader") && random(10) > 8 ) {
        tell_object( victim,set_color(
  "\n赵子扬大喝一声：想我在战场上以一敌百，就凭你们这种烂队伍也想打败我吗!!\n"+
  "赵子扬突发神力，把你的队伍队型打得乱七八糟\n\n","HIR") );
        PARTY_D->disband_party(victim);
     }
     return 0;
}