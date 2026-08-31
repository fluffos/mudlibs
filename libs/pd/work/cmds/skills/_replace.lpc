//      _replace.c
//      Cleric ability for replacing lost limbs
//      created 02 November 1992 by Descartes of Borg

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();

int add_limb(object ob, string limb);

string type() { return "healing"; }

int cmd_replace(string str) {
    string who, limb;
    string *missing;
    string *limbs;
    int healing;
    int cost;
    object tp, ob;

    if (!spell())
    {
        write("What?\n");
        return 1;
    }

    tp = this_player();

    if( tp->query_ghost() )
        return notify_fail("You cannot do that in your immaterial state.\n");
    
    if( !str )
        return notify_fail("Replace what?\n");
    
    if( sscanf(str, "%s %s", who, limb) != 2 )
        return notify_fail("Correct syntax: <replace [player] [limb]>\n");
    
    ob = present(who, environment(tp));
    
    if( !ob )
        return notify_fail(capitalize(who) + " is not here.\n");
    
    if( ob->query_ghost() )
        return notify_fail("You cannot help the dead in that way.\n");
    
    if( !living(ob) )
        return notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    
    limbs = (string *)ob->query_limbs();
    missing = (string *)ob->query_severed_limbs();
    
    if( !missing )
    {
        if( ob == tp )
            return notify_fail("You are not missing any limbs!\n");
        else
            return notify_fail(ob->query_cap_name()+" is not missing any limbs.\n");
    }
    
    if( member_array(limb, missing) == -1 || member_array(limb, limbs) != -1)
    {
        if( tp == ob )
            return notify_fail("You are not missing that limb!\n");
        else
            return notify_fail(ob->query_cap_name()+" is not missing that limb!\n");
    }

    this_player()->set_magic_round();
    healing = (int)tp->query_skill("healing")/2;
    healing += tp->query_skill("faith")/3;
    healing += tp->query_skill("belief")/3;
    healing -= random(76);
    
    if( tp == ob )
        cost = 175 + random(76);
    else
        cost = 250 + random(51);
    
    if( (int)tp->query_mp() < cost )
        return notify_fail("Too low on magic power.\n");
    
    tp->add_mp(-cost);
    
    if( healing < 1 )
    {
        message("info", "Your concentration is simply too weak.", tp);
        message("info", tp->query_cap_name() + " loses " +
                tp->query_possessive() + " concentration while in " +
                "prayer.", environment(tp), tp);
        tp->add_skill_points("healing", 10);
        return 1;
    }

    if( !add_limb(ob, limb) )
         return 0;

    if( tp == ob )
    {
        message("info", "Your " + limb + " regenerates through prayer!", tp);
        message("info", tp->query_cap_name() + "'s " + limb + " regenerates " +
                "through prayer!", environment(tp), tp);
        tp->add_skill_points("healing", to_int((healing / 3) + random(healing * 2 / 3)));
        tp->add_exp(to_int((healing / 3) + random(healing * 2 / 3)));
    }
    else
    {
        message("info", "You regenerate " + ob->query_cap_name() + "'s " +
                limb + " through prayer!", tp);
        message("info", tp->query_cap_name() + " regenerates your " + limb +
                " through prayer!", ob);
        message("info", tp->query_cap_name() + " says a prayer that " +
                "regenerates " + ob->query_cap_name() + "'s " + limb + ".",
                environment(tp), ({ tp, ob }) );
        tp->add_skill_points("healing", to_int((healing * 2 / 3) + random(healing / 3)));
        tp->add_exp(to_int((healing * 2 / 3) + random(healing / 3)));
        tp->add_alignment(to_int((healing * 2 / 3) + random(healing / 3)));
    }
    return 1;
}

int add_limb(object ob, string limb) {
    string* limbs;
    string* all_limbs;
    int x;
    mapping limb_info;
    
    if( !ob || !limb || limb == "" )
        return notify_fail("An error occured. Please tell an admin.\n");
    
    /*
    limbs = ({ "right foot", "left foot", "right hand", "left hand",
            "right leg", "left leg", "right arm", "left arm",
            "right wing", "left wing", "right horn", "left horn",
            "front right claw", "back right claw", "front left claw", "back left claw",
            "front right leg", "back right leg", "front left leg", "back left leg", "tail",
            "first arm", "second arm", "third arm", "fourth arm",
            "first hand", "second hand", "third hand", "fourth hand",
            "right foreleg", "left foreleg", "right rear leg", "left rear leg",
            "right fore hoof", "left fore hoof", "right rear hoof", "left rear hoof" });
    // */
    
    all_limbs = RACE_D->query_limbs(ob->query_race());
    limbs = ob->query_limbs();
    limb_info = RACE_D->query_limb_info(limb, ob->query_race());
    
    if( !all_limbs || !limb_info )
        return notify_fail(ob->query_cap_name() + " doesn't need any limbs restored.\n");
    
    if( member_array(limb, all_limbs) == -1 || member_array(limb, limbs) != -1 )
        return notify_fail(ob->query_cap_name() + " doesn't need that limb restored.\n");;
    
    if(limb_info["attach"] != "0" &&  member_array(limb_info["attach"], limbs) == -1 )
        return notify_fail(ob->query_cap_name() + " needs a " +
                limb_info["attach"] + " for that limb to be restored.\n");
    
    ob->add_limb(limb, limb_info["ref"], ob->query_max_hp() / limb_info["max"], 0, 0);
    
    limbs = RACE_D->query_wielding_limbs(ob->query_race());
    
    if( limbs && member_array(limb, limbs) != -1)
        ob->add_wielding_limb(limb);
    
    return 1;
}

void help() {
    write("Syntax: <replace [player] [limb]>\n\n"+
      "A prayer to regenerate the missing limb of a player.\n");
}

int spell() {
    object o;
    o = this_player();
    if (o && o->query_level() >= 19 &&
        (o->query_subclass() == "cleric" || o->query_subcass() == "druid"))
          return 1;
    return 0;
}


