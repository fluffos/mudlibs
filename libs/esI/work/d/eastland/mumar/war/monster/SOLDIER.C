#include <mudlib.h>

inherit "/d/eastland/mumar/war/mwar";

void create()
{
        ::create();
        set_level(8);
        set_name( "Tuss Soldier", "突斯士兵" );
	add( "id", ({ "soldier", "tuss soldier" }) );
        set_short( "突斯士兵" );
        set_long( @LONG
一个突斯族的小兵，□牙咧嘴地向你冲过来。
LONG        );
        set( "unit", "名" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -300 );
        set( "wealth/silver", 50 );
        set( "aggressive", 1 );
	set( "mumarscore", 50 );
        set( "pursuing", 1 );
        set( "moving", 1 );
	set( "killer", 1 );
        set( "speed", 30 );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 10 );
        set_skill( "shortblade", 50 );
        set_skill( "parry", 30 );
        set_skill( "defend", 40 );
//        set( "chat_chance", 20 );
//        set( "att_chat_output", ({
//       }) );
	wield_weapon( "/d/eastland/mumar/war/obj/shortsword" );
	equip_armor( "/d/eastland/mumar/war/obj/plate" );
//	equip_armor( "/d/eastland/mumar/war/obj/cape" );	
	equip_armor( "/d/eastland/mumar/war/obj/helmet" );
//	equip_armor( "/d/eastland/mumar/war/obj/ring" );
//	equip_armor( "/d/eastland/mumar/war/obj/gauntlets" );
}