// Petrarch
// Merentha Lib 1.0
// <fireball>  sample magic attack spell

int command() {
    object at;
    int dam;

    if(this_player()->query_class()!="mage") return notify_fail("Only mages can cast fireballs.\n");
    at=this_player()->query_current_attacker();
    message("magic", "You summon up the magic to cast a giant ball of fire.", this_player());
    message("magic", this_player()->query_cap_name()+" concentrates on a magic spell.",environment(this_player()),({this_player(),at}));
    if(at) {
        if(random(this_player()->query_skill_level("attack"))<random(at->query_skill_level("defense"))) dam=0;
        else dam=this_player()->query_skill_level("attack magic");
        this_player()->set_casting(2);
        this_player()->set_casting_damage(dam);
        this_player()->set_magic_casting(({
            "Your fireball his "+at->query_cap_name()+".", 
            "A fireball from "+this_player()->query_cap_name()+" burns you badly.",
            this_player()->query_cap_name()+" hits "+at->query_cap_name()+" with a ball of fire."
          }));
                if (dam>0) {
                   this_player()->use_skill("attack magic",(dam<100?dam/2:50));
                } else {
                   at->use_skill("defense", 10);
                }
    } else {
        message("magic", "You release a ball of fire into the sky.", this_player());
        message("magic", this_player()->query_cap_name()+" releases a ball of fire into the sky.",environment(this_player()),({this_player(),at}));
        message("magic", "A magistic fireball flies overhead.", users());
    }
    return 1;
}

string help() {
    return "Syntax: fireball\n\nThis powerful command of the magi allows the caster to create and fire off a magical ball of fire.  When used in combat the fireball will be directed at the enemy.";
}

