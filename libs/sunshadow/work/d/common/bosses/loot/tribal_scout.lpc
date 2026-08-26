/*
  tribal_scout.c
  
  Medium armor meant for druid. Does extra force damage to attacks made while stealth or invisible.
  
  -- Tlaloc --
*/

#include <std.h>

inherit ARMOUR;

string owner;

void create()
{
    ::create();
    set_name("tribal scout");
    set_short("%^RESET%^%^C144%^The %^RESET%^%^C094%^D%^C136%^e%^C220%^s%^C226%^e%^C136%^r%^C094%^t %^RESET%^%^C094%^G%^C136%^u%^C220%^a%^C226%^r%^C227%^d%^C220%^i%^C136%^a%^C094%^n%^CRST%^");
    set_obvious_short("%^RESET%^%^C144%^Thick hide armor dusted in sand");
    set_long("%^RESET%^%^C144%^This %^RESET%^%^C094%^h%^C130%^i%^C136%^d%^C094%^e %^RESET%^%^C094%^a%^C130%^r%^C136%^m%^C130%^o%^C094%^r %^RESET%^%^C144%^is unusally %^RESET%^%^C039%^b%^C045%^r%^C051%^e%^C087%^a%^C159%^t%^C123%^h%^C087%^a%^C051%^b%^C045%^l%^C039%^e %^RESET%^%^C144%^for it's thickness. Soft %^RESET%^%^C094%^g%^C178%^o%^C220%^l%^C226%^d%^C178%^e%^C094%^n %^RESET%^%^C094%^f%^C220%^u%^C226%^r%^RESET%^%^C094%^s %^RESET%^%^C144%^dusted with %^RESET%^%^C136%^sand %^RESET%^%^C144%^are bound together with fine stips of %^RESET%^%^C094%^leather%^RESET%^%^C144%^, barely concealing the hardier %^RESET%^%^C220%^s%^C226%^c%^C227%^a%^C228%^l%^C226%^e%^C220%^s %^RESET%^%^C144%^beneath. Long sleeves end in cuffs adorned with the thick %^RESET%^%^C244%^c%^C245%^l%^C246%^a%^C245%^w%^C244%^s %^RESET%^%^C144%^of a %^RESET%^%^C094%^d%^C136%^e%^C220%^s%^C226%^e%^C136%^r%^C094%^t %^RESET%^%^C094%^w%^C136%^y%^C220%^v%^C226%^e%^C136%^r%^C094%^n%^RESET%^%^C144%^. %^RESET%^%^C136%^Sand %^RESET%^%^C144%^falls from the armor twisting and writhing around it as if caught in the %^RESET%^%^C136%^desert %^RESET%^%^C051%^w%^C087%^i%^C123%^n%^C051%^d%^RESET%^%^C144%^, apparent %^RESET%^%^C088%^w%^C124%^a%^C160%^v%^C124%^e%^C088%^s of %^RESET%^%^C088%^h%^C124%^e%^C160%^a%^C088%^t %^RESET%^%^C144%^blend with the %^RESET%^%^C136%^sand %^RESET%^%^C144%^and in the briefest moments create the %^RESET%^%^C035%^m%^C036%^i%^C037%^r%^C038%^a%^C039%^g%^C033%^e %^RESET%^%^C144%^of eyes surveying the area.%^CRST%^");
    set_lore("In ages past the desert was even more inhospitible. A massive sand elemental raged against any it all creatures it could find. Many tried to hide in the ground or flee to the sky but it was as if the elemental could see through the grains of sand as if they were it's own eyes. A nomadic druid plead to the creatures of the desert to assist her in binding the elemental and restore harmony to the broken sands. The creatures gathered, each offering up one of their own for her own for the cause. When the elemental struck each of the creatures sacrificed themselves as the spell was woven. The sands tore at her flesh as she wound the creatures together, binding the elemental in chains of blood and soul. When the sandstorm calmed none of the participants could be found, their names lost to the sands. A piece of each still remains and their legacy the desert guardian endures.");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);   
    set_flag_required("boss avatar");
    set_max_dex_bonus(10);
    set_ac(7);
    set_weight(30);
    set_value(10000);
    set_armor_prof("medium");
    set_type("leather");
    set_property("repairtype", ({ "leatherworker" }));
    set_limbs( ({ "torso" }) );
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
    set_struck( (: this_object(), "strike_fun" :) );
    
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    
    set_property("enchantment", 7);    
    set_item_bonus("damage resistance", 10);
    set_item_bonus("athletics", 7);    
    
}

int is_metal() { return 0; }

int wear_fun()
{   
    if(!this_player()->is_class("druid"))
    {
        tell_object(this_player(), "Only a druid may wear this armor!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "%^RESET%^%^C144%^You swear you hear the distant sound of the %^RESET%^%^C136%^desert %^RESET%^%^C051%^w%^C087%^i%^C123%^n%^RESET%^%^C087%^d%^C051%^s %^RESET%^%^C144%^ as the armor binds to you.%^CRST%^");
    }
    else
    {
        if(owner != this_player()->query_name())
        {
            tell_object(this_player(), "This is not your armor!");
            return 0;
        }
    }
    
    this_player()->set_property("additional stealth damage", ({ "force" }));
    tell_object(this_player(), "%^RESET%^%^C144%^You feel a comforting %^RESET%^%^C088%^w%^C124%^a%^C160%^r%^C196%^m%^C124%^t%^C088%^h %^RESET%^%^C144%^as you don the hide armor.%^CRST%^");
    
    return 1;
}

int remove_fun()
{
    tell_object(this_player(), "%^RESET%^%^C144%^You already miss the %^RESET%^%^C088%^w%^C124%^a%^C160%^r%^C196%^m%^C124%^t%^C088%^h %^RESET%^%^C144%^of the hide armor.%^CRST%^");
    this_player()->remove_property_value("additional stealth damage", ({ "force" }));
    return 1;
}

int strike_fun(int x, object wep, object attacker)
{
    int damage;
    object wearer, room;
    
    if(!random(3))
    {
        wearer = environment(this_object());
        wearer && room = environment(wearer);
        
        tell_object(attacker, "%^RESET%^%^C136%^Desert sands %^RESET%^%^C051%^w%^C087%^h%^C123%^i%^C087%^r%^C051%^l %^RESET%^%^C136%^around (wearer), violently %^C088%^w%^C124%^h%^C160%^i%^C196%^pp%^C160%^i%^C124%^n%^C088%^g %^RESET%^%^C136%^you!%^CRST%^");
        tell_object(wearer, "%^RESET%^%^C136%^Desert sands %^RESET%^%^C051%^w%^C087%^h%^C123%^i%^C087%^r%^C051%^l %^RESET%^%^C136%^around you, violently %^C088%^w%^C124%^h%^C160%^i%^C196%^pp%^C160%^i%^C124%^n%^C088%^g %^RESET%^%^C136%^(attacker)!%^CRST%^");
        tell_room(room, "%^RESET%^%^C136%^Desert sands %^RESET%^%^C051%^w%^C087%^h%^C123%^i%^C087%^r%^C051%^l %^RESET%^%^C136%^around (wearer), violently %^RESET%^%^C088%^w%^C124%^h%^C160%^i%^C196%^pp%^C160%^i%^C124%^n%^C088%^g %^RESET%^%^C136%^(attacker)!%^CRST%^", ({ attacker, wearer }));
        
        damage = roll_dice(1 + wearer->query_base_character_level() / 5, 6);
        attacker->cause_typed_damage(attacker, attacker->return_target_limb(), damage, "piercing");
    }
    
    return x;
}       