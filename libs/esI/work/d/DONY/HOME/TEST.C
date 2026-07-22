#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dragon King of Well", "井龙王" );
	add ("id", ({ "king", "dragon", }) );
	set_short( "井龙王" );
	set_long(
    "  井龙王原是北海龙王，因为在儿子闯出大祸之後，得罪了玉帝，才被贬到凡间，\n"
    "他其实是很有智慧的人，且由於曾经过万年的修□，胆识及统御能力皆不同凡响。\n"
	);

        set( "alignment",1600);
        set( "gender", "male" );
        set( "race", "dragon" );
        set( "unit", "位" );
        set( "likefish",1);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 20);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
	set("special_defense", (["all":60,"none":60]) );
        set ("aim_difficulty", ([ "critical":30, "vascular":30, "weakest":30, "ganglion":30 ]) );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
        set ("max_sp", 2000);
        set ("spell_points",2000);
	set ("wealth", ([ "gold": 500 ]) );
	set_natural_weapon( 5, 5, 10 );
	set_natural_armor( 50, 41 );
        set ("weight", 400);
        set ("unbleeding",1);
	set ("att_chat_output", ({
	    "龙王说：你们这些小老百姓，是不可能击败我的。\n"
	    }) );
	wield_weapon("/u/d/dony/item/feather");
}

void die()
{
   int i ;
   object *sword,*tmp, dragon_sword;
   
   tmp = children("/u/d/dony/item/feather");
/*
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
   {
      if(!environment(tmp[i])) continue ;
          else sword=sword+({tmp[i]}) ;
   }
*/   
   if( sizeof(tmp)>1 ){
     dragon_sword = present( "feather", this_object() );  
     tell_room(environment(this_object()),
  " 龙王挣扎的说：宝剑一生只有一次．．．．．．\n龙王用尽最後的力量将龙剑粉碎！\n",this_object() );
   dragon_sword->remove();
   }
 ::die();
}

