// Chernobog (6/9/22)
// Rework to Reward Command

#include <std.h>
#include <daemons.h>
#include <new_exp_table.h>

#define DELAY 60 * 60

int cmd_reward(string str){
    object player, target;
    string player_reward, cooldown_name;

    if(!str){
        tell_object(player, "You need to pick a target to reward for their roleplay.");
        return 1;
    }
    
    player = this_player();
    player_reward = player->query_name()+"_reward";
    
    if(!userp(player)) return 0;
    if(!objectp(target = present(str, environment(player)))){
        tell_object(player, "You don't see that here.");
        return 1;
    }
    if(!userp(target) || avatarp(target)){
        tell_object(player, "You have to select a player.");
        return 1;
    }
    if(player == target) {
        tell_object(player, "You cannot reward yourself.");
        return 1;
    }
    if(target->query("no_reward")) {
        tell_object(player, "That player is not accepting rewards.");
        return 1;
    }
    if(target->query_property(player_reward) > time()){
        tell_object(player, "You have already rewarded them recently, please wait awhile.");
        return 1;
    }

    {
        int expdelta;
        int thelevel = target->query_adjusted_character_level();

        expdelta = abs(EXP_NEEDED[thelevel + 1] - EXP_NEEDED[thelevel]) / 8;
        expdelta = WORLD_EVENTS_D->check_exp_events(expdelta, this_object());

        target->set_property("ignore tax", 1);
        target->add_general_exp(target->query_classes()[0], expdelta);
        target->remove_property("ignore tax");

        tell_object(player, "%^CYAN%^%^BOLD%^You have rewarded "+target->query_cap_name()+" with some experience.");
        tell_object(target, "%^CYAN%^%^BOLD%^You feel enlightened as your powers grow.");
        cooldown_name = "reward - "+capitalize(str);
        this_player()->add_cooldown(cooldown_name, DELAY);
        target->remove_property(player_reward);
        target->set_property(player_reward, time() + 3600);
    }

    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

reward - reward someone with exp

%^CYAN%^SYNOPSIS%^RESET%^

reward %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to reward anyone with 12.5% of exp towards their next level. The reason for doing so is left to your discretion. The player won't know who rewarded them, but will see the message about the reward. They also must be present in the room with you. You can do it only once per hour per target.

Players may opt out from receiving rewards with the noreward setting in %^ORANGE%^<set>%^RESET%^ command. If they did so, your attempt to reward them won't count.

%^CYAN%^SEE ALSO%^RESET%^

set, score, who, chfn
"
        );
}

