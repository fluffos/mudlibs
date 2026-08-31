#include <lib.h>
#include <rounds.h>

inherit LIB_DAEMON;

void eventInventory();

mixed cmd(string args) {
    if( this_player()->GetInCombat() )
        this_player()->SetAttack(0, (: eventInventory :), ROUND_OTHER);
    else eventInventory();
    return 1;
}

void eventInventory() {
    object *weapons = filter(all_inventory(this_player()), (: $1->GetWielded() :) );
    string *all_limbs = this_player()->GetLimbs();
    object *armors = filter(all_inventory(this_player()), 
            (: $1->GetWorn() && !($1->GetWielded()) :) );
    string ret = "You are using: \n";
    
    foreach(object weapon in weapons){
        string tmp = "";
        string *limbs = ({});
        foreach(string limb in weapon->GetWorn()){
            limbs += ({ limb });
        }
        if(sizeof(limbs) > 1) {
            tmp += "<wielded in both hands> ";
        } else {
            tmp += "<wielded in "+item_list(limbs)+"> ";
        }
        tmp += capitalize(weapon->GetShort())+".\n";
        ret += tmp+"\n";
    }
    
    foreach(object armor in armors){
        string tmp = "<worn on "+item_list(armor->GetWorn())+"> "+capitalize(armor->GetShort())+".\n";
        ret += tmp;
    }

    foreach(string limb in all_limbs){
        if(!sizeof(this_player()->GetWorn(limb))){
            ret += "<worn on "+limb+"> nothing.\n";
        }
    }

    write(ret);
}

string GetHelp(){
    return ("Syntax: equipment\n\n"
            "Lists all items you are currently wearing or wielding. "
            "This command "
            "will take up one round of combat if you happen to be in "
            "combat.");
}
