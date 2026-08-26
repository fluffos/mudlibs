// Petrarch
// Merentha Lib 1.0
// <swing>  skill command for swords only

int command() {
    object *obj;
    object at;
    int i, dam;

    i=sizeof(obj=this_player()->query_wielding());
    if(!i) return notify_fail("You must be wielding a sword to swing.\n");
    while (i--) {
        if(obj[i]->query_type()=="sword") {
            at=this_player()->query_current_attacker();
            message("skill", "You take a wild swing with your "+obj[i]->query_name()+".", this_player());
            message("skill", this_player()->query_cap_name()+" takes a wild swing with "+this_player()->query_his_her()+" "+obj[i]->query_name()+".",environment(this_player()),({this_player(), at}));
            if(at) {
                message("skill", "You swing at "+at->query_cap_name()+".", this_player());
                message("skill", this_player()->query_cap_name()+" takes a wild swing at you with "+this_player()->query_his_her()+" "+obj[i]->query_name()+".", at);
                if(random(this_player()->query_skill_level("attack"))<random(at->query_skill_level("defense"))) dam=0;
                else dam=obj[i]->query_wc();
                this_player()->set_special(1);
                this_player()->set_special_damage(dam);
                this_player()->set_combat_special(({
                    "You take a wild swing and hit "+at->query_cap_name()+".", 
                    "You get hit with a wild swing from "+this_player()->query_cap_name()+".",
                    this_player()->query_cap_name()+" hits with "+this_player()->query_his_her()+" swing."
                  }));
                if (dam>0) {
                   this_player()->use_skill("sword",(dam<100?dam/4:25));
                   this_player()->use_skill("attack",(dam<100?dam/4:25));
                } else {
                   at->use_skill("defense", 10);
                }
            }
            return 1;
        }
    }
    return notify_fail("You must be wielding a sword to swing.\n");
}

string help() {
    return "Syntax: swing\n\nThis skill command allows the user (when wielding a sword and in combat) to take a wild swing at his or her enemy.";
}

