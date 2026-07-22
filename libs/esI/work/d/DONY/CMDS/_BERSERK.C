#include <mudlib.h>

inherit DAEMON;

int check_conditions(object obj)
{
    int med,max,percent;
    med = (int)obj->query("medication_resistance");
    max = (int)obj->query("critical_med_res");
    if( !max || max < 0 ) max = 1000;
       percent = 100 * med / max;
    if( percent > 80 ) return 1;
    else return 0;
}                                        
int cmd_berserk(string str)
{
    object target,player;
    int level;        
    player=this_player();
    /*
    if ( player->query_skill("berserk") < 60 ) {
       tell_object(player,"你低微的技巧无法施展那狂暴奥密！\n");
       return 1;    
    }
    if ( check_conditions(player) ) {
       tell_object(player,"你现在身体状况很差，最好不要做狂暴攻击！\n");
       return 1;        
    }
    if ( player->query_temp("berserk",1) ) {
       tell_object(player,"你早已准备好狂暴攻击的架式了！\n");
       return 1;
    }
    */
    if ( !target=player->query_attacker() ) {
       tell_object(player,"你不在战斗中无法做出狂暴攻击！\n");
       return 1;
    }
    level=3*(int)player->query_level();
    if ( player->query("spell_points") < level ) {
       tell_object(player,"你精神力不够，无法运用狂暴攻击！\n");
       return 1;
    }
    tell_room(environment(player),set_color(sprintf(
       "%s做出了狂暴攻击的架式！\n",player->query("c_name")),"HIW"),player);
    tell_object(player,set_color("你扎好马步准备做出狂暴攻击的架式！\n","HIY"));
 //   player->set_temp("berserk",1);
 //   player->add("spell_points",-level);
 //   call_out("delay", 1, 0 );                            
    call_out("delay",1);
    return 1 ;
}
int delay(int count)
{
    object env,target,player;
    string pname;
    int skill,i,bonus;
    bonus=10;
    player=this_player();
    env=environment(player);
    pname=player->query("c_name");
  /*
    if ( count < 8 ) {
       if ( !player->query_attacker() ) {             
          tell_object(player,"唉呀，你的敌人跑掉了！\n");
          player->set_temp("berserk",0);
          player->set_temp("berserk_reduce",bonus);
          return 1;
       }
       call_out("delay",1,count+1);
       return 1;
    }
    skill=((int)player->query_skill("berserk"))/10;
    if ( player->query("weapon2") )
        skill=skill/2;
    bonus=skill-(int)random(3);
    player->set_temp("berserk",0);
    player->set_temp("berserk_reduce",bonus);
*/
    tell_room(env,set_color(sprintf("%s开始疯狂地攻击著敌人！\n",
       pname),"HIW"),({player}));
    tell_object(player,set_color(
      "\n你开始对著敌人做出一连串绵密的攻击！\n","HIR"));
    for (i=0;i<bonus;i++) {
      player->continue_attack();
  //    player->add("medication_resistance",3);
    }
    tell_room(env,set_color(sprintf("%s的攻击迟缓了下来！\n",
        pname),"HIW"),({player}));
    tell_object(player,set_color(
        "你的攻击迟缓了下来！\n\n","HIY"));
 //   player->set_temp("berserk_reduce",0);
    return 1;          
}
int help() {
	write (@HELP
Usage: berserk(狂暴攻击) 
       
狂暴攻击可以让你对於敌人作多次的攻击，
当攻击完之後会有若干的疲劳。

HELP
	       );
    return 1 ;
}
