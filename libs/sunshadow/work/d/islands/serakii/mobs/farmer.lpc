#include <std.h>
#include "../serakii.h"

inherit MONSTER;

int level;
object ob;

void create() 
{

    :: create();
    set_name("corrupted farmer");
    set_id(({"farmer", "corrupted farmer", "monster", "fell farmer"}));
    set_short("%^C060%^co%^C129%^r%^C060%^rup%^C164%^t%^C060%^ed farm%^C164%^e%^C060%^r%^CRST%^");
    set_long("%^C059%^This used to be a "+
	"%^C095%^farmer%^C059%^, and is still "+
	"dressed in the %^C186%^clothing%^C059%^ "+
	"of a %^C094%^farmer %^C059%^and wielding "+
	"the %^C254%^tools %^C059%^of one, but "+
	"its humanity is obviously far gone. "+
	"Its %^C173%^skin %^C059%^has been %^C001%^"+
	"sliced %^C059%^and hangs so loose that "+
	"you can see %^C251%^gray flesh%^C059%^ "+
	"underneath. %^C055%^Fe%^C063%^l%^C055%^l m%^C063%^"+
	"i%^C055%^asma%^C059%^ seems to pour from "+
	"the %^C088%^wounds %^C059%^and the poor "+
	"soul's eyes %^C163%^glow softly%^C059%^ "+
	"with an otherworldly %^C251%^light%^C059%^. "+
	"Its movements are slow and shambling until "+
	"it sees something to kill when it leaps into "+
	"action.\n%^CRST%^");
    
    set_gender(random(2)?"male":"female");
    set_race("human");
    set_class("ranger");
    level = 32 + random(9);
    set_guild_level("ranger",level);
    set_mlevel("ranger",level);
    set_max_hp(level * 20);
    set_hp(query_max_hp());
    set_size(2);
    set_property("magic",1);
    set_overall_ac(-30);
    add_attack_bonus(roll_dice(3,6));
    add_damage_bonus(roll_dice(3,3));
    set_mob_magic_resistance("average");
    set_new_exp(level, "normal");
    set_body_type("humanoid");
    set_race("human");
    set("aggressive",50);

   set_alignment(9);
        
    set_property("full attacks",1);

    add_money("gold",random(1800)+600);      
        
    
    set_speed(50);
    set_moving(1);
    
set_nogo(({ROAD"4"}));
    
    set_property("add kits",20);
    
    set_stats("strength",19);
    set_stats("dexterity",19);
    set_stats("constitution",22);
    set_stats("intelligence",1);
    set_stats("wisdom",1);
    set_stats("charisma",1);
    
    add_attack_bonus(roll_dice(1,10));
    add_damage_bonus(roll_dice(1,6));
    
    set_monster_feats(({
      "shatter",
      "ambidexterity",
      "sunder",
      "whirl"
    }));
    set_funcs(({
	   "insane_blows", 
       "push_em",
       "insane_blows",
       "insane_blows",
       "insane_blows",
       "push_em",
	}));
    set_func_chance(35);   
	
	switch(random(2)){
	
    case 0:
	    ob = new("/d/common/obj/weapon/sickle");
        ob->set_property("enchantment",7);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
	    ob = new("/d/common/obj/weapon/sickle");
        ob->set_property("enchantment",7);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield sickle");
		command("wield sickle 2");
	break;
	case 1:
	    ob = new("/d/common/obj/weapon/scythe");
        ob->set_property("enchantment",7);
        ob->set_property("monsterweapon",1);
        ob->move(TO);
		command("wield scythe");
	break;		
    }
}

void insane_blows(object targ) 
{
    object storm;
    string me;
    int hits;

    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    if(!objectp(ETO)) { return; }
    me = TO->query_short();
    tell_object(targ, me +"%^C077%^ flails its arms and runs towards you!%^CRST%^");
    
    tell_room(ETO, me +"%^C077%^ runs wildly at "+targ->QCN+"%^C077%^!%^CRST%^", targ);
    hits = 2 + random(5);
    if(targ->reflex_save(60))
    {
        tell_object(targ, "%^C173%^You jump out of the way of "+
        me+"%^C173%^'s flailing weapons!");
        
        tell_room(ETO, targ->QCN+" %^C173%^is able to jump out of the way of "+
        me+"%^C173%^'s weapons!%^CRST%^", targ);
        
        targ->cause_typed_damage(targ, targ->return_target_limb(), (roll_dice((hits*3),8)/2),"slashing");
    }
    else
    {
        tell_object(targ, "%^C111%^You are unable to jump out of the way and "+
        me+" %^C111%^slashes both weapons along you!%^CRST%^");
        
        tell_room(ETO, targ->QCN+" %^C111%^is unable to get out of the way and "+
        me+" %^C111%^slashes "+targ->QO+"%^C111%^!%^CRST%^", targ);
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice((hits*3),8),"slashing");
    }
    return;
   
}

void push_em(object targ)
{    
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    
    tell_object(targ, me +" %^C196%^charges at you!%^CRST%^");
    
    tell_room(ETO, me +" %^C196%^charges at "+targ->QCN+", %^C196%^while mumbling%^CRST%^", targ);
    
    if(targ->reflex_save(60))
    {
        tell_object(targ, "%^C196%^You step out of the way just in time and "+me+
        " %^C196%^charges past you!%^CRST%^");
        
        tell_room(ETO, targ->QCN+"%^C196%^ steps out of the way just in time and "+me+
        " %^C196%^charges past "+targ->QO+"!", targ);
        return;
    }
    tell_object(targ, me+"%^C093%^slams into you and knocks you to the ground!%^CRST%^");
    
    tell_room(ETO, me+"%^C093%^ slams into "+targ->QCN+"%^C093%^, knocking "+targ->QO+
    "%^C093%^ to the ground!%^CRST%^", targ);
    
    targ->set_tripped(2, "%^C205%^You are still trying to get up!%^CRST%^");
    return;   
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    
    ::init();
    if(TP->query_true_invis()) return;
    if(!userp(TP)) return;
    command("emoteat "+TPQN+ "%^C241%^ turns and glares at $N!%^C205%^");
    command("shatter "+TPQN); 
}
