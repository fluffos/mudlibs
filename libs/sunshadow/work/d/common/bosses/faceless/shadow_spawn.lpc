//Used for slicing shadows

#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("shadow spawn");
   set_short("A shadow spawn");
   set_id(({"shadow", "spawn", "shadow spawn"}));
   set_long("");
   set_property("magic",1);
   set_hd(60,6);
   set_level(60);
   set_mlevel("fighter", 60);
   set_hp(3500);
   set_base_damage_type("void");
   set_gender("none");
   set_race("shadow");
   add_limb("whiplike whorl","",0,0,0);
   add_limb("shadow tendril","",0,0,0);
   set_attack_limbs(({"whiplike whorl","shadow tendril"}));
   set_attacks_num(3);
   set_property("damage resistance", 20);
   set_property("spell damage resistance", 20);
   set_property("void resistance percent", 50);
   set_property("radiant resistance percent", -50);
   set_overall_ac(-70);
   set_hit_funcs((["whiplike whorl":(:TO,"killem":),"shadow tendril":(:TO,"killem":)]));
   set_monster_feats( ({ "evasion", "dodge", "scramble" }) );
}

void die()
{
    object *targets;
    tell_room(environment(this_object()), "%^BLACK%^BOLD%^The shadow emits a high-pitched scream as it dissipates!%^RESET%^");
    
    targets = all_living(environment(this_object()));
    
    foreach(object ob in targets)
    {
        if(!living(ob))
            continue;
        
        if(avatarp(ob))
            continue;
        
        if(ob->query_name() == "puppeteer")
            continue;
        
        ob->cause_typed_damage(ob, "head", 175, "sonic");
    }
    
    ::die();
}

int killem(object targ)
{
   if(!objectp(targ)) return 0;

   //tell_room(ETO,"%^BOLD%^%^BLACK%^The whiplike tendrils of shadow strike with uncanny precision.%^RESET%^");
   return roll_dice(2, 8);
}
