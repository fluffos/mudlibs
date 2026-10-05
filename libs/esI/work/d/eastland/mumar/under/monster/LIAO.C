#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(18);
        set_name( "General Liao Hwa", "牧马先锋 廖划" );
        add ("id", ({ "general", "liao","hwa" }) );
        set_short( "牧马先锋 廖划" );
        set_long( @C_LONG
 
你眼前站著一个高大的壮汉，他就是牧马关的步卒先锋廖划，在牧马关里，他的地
位仅次於节度使和将军，是个厉害人物。不过，他虽力可拔山河，却著实是个暴虎
冯河，有勇无谋的家伙。他现在正在巡视密道内的各个守卫的卫哨勤务。
C_LONG
        );
    set( "alignment",1000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
    set_perm_stat( "dex", 20 );
    set_perm_stat( "str", 25 );
    set_perm_stat( "int", 10 );
    set_perm_stat( "con", 20 );
    set_perm_stat( "kar", 20 );
    set_perm_stat( "pie", 20 );
    set ("max_hp", 800);
    set ("hit_points",800);
    set ("wealth", ([ "gold": 100 ]) );
    set_natural_weapon( 20, 5, 15 );
    set_natural_armor( 66, 48 );
    set ("aim_difficulty", ([ "critical":50, "weakest":50, "ganglion":50,"vascular":50]));
    set ("weight", 400);
    set_skill("axe",95);
    set_skill("parry",95);
    set_skill("block",95);
    wield_weapon(OBJS"axe");
    equip_armor(OBJS"helmet02");
    equip_armor(OBJS"mail01");
    equip_armor(OBJS"shield");
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
   && arg != "laio" )
   {
         if(killer) {
            kill_ob(killer);
            killer->kill_ob(this_object());
            tell_object(killer,
         "廖划狠狠地瞪你一眼，说道: 喂，你竟敢在这里撒野？\n");
            tell_room(  environment(killer),
         "廖划铜铃般的大眼一瞪，举起手中的大斧砍向"+killer->query("c_name")+
        "......!\n", killer );
     }
   }
}
