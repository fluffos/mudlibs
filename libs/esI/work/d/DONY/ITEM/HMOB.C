#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "gonfu master","测试" );
        add ( "id", ({ "master","gonfu"}) );
        set_short("测试" );
        set("unit","位");
        set_long(@C_LONG
A test mob .
C_LONG
        );
        set("alignment",1200);
        set("wealth/silver",700);
        set("gender","male");
        set("race","human");
        set("hit_points",450);
        set("force_points",400);
        set("max_hp",450);
        set("weight",710);
        set_perm_stat("str",22);
        set_perm_stat("dex",18);
        set_perm_stat("int",10);
        set_perm_stat("kar",15);
        set_natural_weapon(30, 12, 25);
        set_natural_armor(20,20);
        set( "special_defense", ([ "all": 20, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":100,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",50 );
        set_skill("dodge",55);
        set_skill("parry",65);
//      set("tactic_func","my_attack");
}
int my_attack()
{
    object victim,wea1,wea2;
    
    if( !(victim = query_attacker()) ) return 0;

    if( random(30) < 2 ) { 
      tell_room( environment(this_object()),
          "项长老使出了『打狗棒法』之『□』字诀把"+
          victim->query("c_name")+"□倒了!!\n",victim);
      tell_object( victim,
          "项长老使出了『打狗棒法』之『□』字诀把你给□倒了!!\n");         
      victim->receive_damage(15);
      victim->block_attack(8);
      victim->set_temp("msg_stop_attack",
          "(  你被□倒了,瞬间无法攻击 !!  )\n");
      return 1;                     
    } else if ( random(30) < 4 ) {
        tell_room( environment(this_object()),
           "项长老使出了『打狗棒法』之『黏』字诀......\n");
           victim->receive_damage(10);
           wea1=victim->query("weapon1");
           wea2=victim->query("weapon2");
           if (wea1) wea1->unwield(1);
           if (wea2) wea2->unwield(1);
           return 1;
    } return 0;
}

