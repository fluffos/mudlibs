#include <../under.h>

inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(19);
        set_name( "goldeater", "食金兽" );
        add ("id", ({ "goldeater","dragon" }) );
        set_short( "食金兽" );
        set_long( @C_LONG
你眼前的食金兽是一只可爱的全身鳞片泛著淡淡红光的龙......
C_LONG
        );
    set( "gender", "male" );
    set( "killer", 1 );
    set( "race", "dragon" );
    set( "unit", "只" );
    set ("weight", 5000);
    set( "alignment",10000 );
    set_perm_stat( "dex", 20 );
    set_perm_stat( "str", 30 );
    set_perm_stat( "int", 30 );
    set_perm_stat( "con", 30 );
    set_perm_stat( "kar", 25 );
    set_perm_stat( "pie", 30 );
    set ("max_hp", 500);
    set ("hit_points",500);
    set ("max_sp", 50000);
    set ("spell_points",50000);
    set_natural_weapon( 70, 40, 60 );
    set_natural_armor( 120, 60 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":100,"ganglion":100,"vascular":100]));
    set ("special_defense", ([ "all":80, "none":80 ]) );
    set ("exp_reward",50000 );
    set_skill("dodge",100);
}

void die()
{
	object killer;
       tell_room(environment(),
         "食金兽口吐鲜血倒在地上．死了!\n"
         "突然间一道白影从食金兽的尸体上飘起来，冷漠看了你一眼，然后变成明亮的光离子消失在空气中。\n"
	"一阵不祥的感觉划过你的心头......\n"
	 "无数道金黄的光线由元神内窜出，有如无数的刀剑般穿过你的身躯......\n"
	"当一切回复原状，你觉得整座牧马关的雄伟灵气似乎随著那些光线而消逝。\n\n",
            this_object() );
       killer=query("last_attacker");
        find_object_or_load("/d/eastland/mumar/war/war")->start_war();
        ::die(1);
}

