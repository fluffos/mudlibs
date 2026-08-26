/**
 * Shadow to keep players in thrall to death.
 * Shiannar, 02/10/01.
 */

#define VALID_COMMANDS ({ "tell", "tel", "te", "t" })
#define ROLL_COMMANDS ({ "roll", "yes", "ye", "y", "no", "n" })

inherit "/std/effect_shadow";

int roll_command(string, string);
void finish_roll(int);

int rolling;

/**
 * Function to call to determine if death is talking to
 * a person.
 * @return int 1
 */
int query_death_speech() {
  return 1;
} /* query_death_speech() */

/**
 * Catches all player input.
 */
int command_shadowed(string command, string args) {
  if(!arg() || !objectp(arg()))
    remove_this_effect();
  if(creatorp(TP)) return 0;
  if(rolling) {
    if(!sizeof(({command}) & (VALID_COMMANDS + ROLL_COMMANDS))) {
      if(!arg() || !objectp(arg()))
        return 0;
      tell_object(player, arg()->short()+"'s steely gaze holds you "
         "enthralled.\n");
      return 1;
    }
    return roll_command(command, args);
  }
  else if(!sizeof(({command}) & VALID_COMMANDS)) {
    if(!arg() || !objectp(arg())) {
      remove_this_effect();
      return 0;
    }
    tell_object(player, arg()->short()+"'s steely gaze holds you "
        "enthralled.\n");
    return 1;
  }
} /* command_shadowed() */

/**
 * Performs rolls for the players life.
 * @arg command the command entered
 * @arg arguments the args entered with the command
 * @return int indicating success or failure
 */
int roll_command(string command, string arguments) {
  string dice;
  int num_dice;
  if(!arg() || !objectp(arg()))
    remove_this_effect();
  if(command != "roll") {
    if(!player->query_property("death_rolling")) {
      tell_object(player, arg()->short()+" chuckles mirthlessly and "
          "says: You must choose to \"roll\" one, two or three dice.\n");
      tell_object(player, arg()->short()+" casually mentions: Rolling "
          "more than one dice could cost you even more lifeforce, so "
          "choose wisely.\n");
      return 1;
    }
    else {
      dice = query_num(player->query_property("death_rolling"));
      tell_object(player, arg()->short()+" says: Very well.  You have "
          "chosen to roll "+dice+" dice, I hope you have chosen wisely.\n");
      tell_object(player, "With a flick of "+arg()->HIS+" knuckles, "+
          arg()->short()+" sends "+dice+" dice rolling.\n");
      call_out((:finish_roll:), 6, player->query_property("death_rolling"));
      return 1;
    }
  }
  else {
    if(player->query_property("death_rolling")) {
      tell_object(player, arg()->short()+" chuckles mirthlessly and "
          "says: You have already chosen how many dice to roll, now "
          "\"yes\" or \"no\", do you want to go ahead with the roll?\n");
      return 1;
    }
    if(sscanf(arguments, "%d%*s", num_dice) != 2) {
      tell_object(player, arg()->short()+" says: Wasting my time would "
          "not be considered wise...  Choose to \"roll\" 1, 2 or 3 "
          "dice.\n");
      return 0;
    }
    else if(num_dice < 1 || num_dice > 3) {
      tell_object(player, arg()->short()+" says: Wasting my time would "
          "not be considered wise... Choose to \"roll\" between 1 and 3 "
          "dice.\n");
      return 1;
    }
    else if(player->query_max_deaths() - player->query_deaths() < num_dice - 2) {
      tell_object(player, arg()->short()+" says dryly: You don't have "
          "that much life force to gamble with...  Choose a lower number.\n");
      return 1;
    }
    else {
      player->add_property("death_rolling", num_dice);
      tell_object(player, arg()->short()+" rubs "+arg()->HIS+" hands "
          "together and chuckles dryly, adding: Now, are you sure you "
          "want to roll "+query_num(num_dice)+" dice?  \"Yes\" or \"no\"...\n");
      return 1;
    }
  }
} /* roll_command() */

/**
 * Finishes the roll for the current player.
 * This should NEVER be called directly.
 * @arg dice Number of dice being rolled.
 */
void finish_roll(int num_dice) {
  int result;
  int i;
  if(!arg() || !objectp(arg())) {
    remove_this_effect();
    return;
  }
  tell_object(player, "The dice clatter softly to the ground.\n"+
      arg()->short()+" peers carefully at them, and then at you.\n");
  for(i = 0; i < num_dice; i++) {
    result = (((random(60) + 1) / 10) + 1);
    tell_object(player, arg()->short()+" says: Dice "+query_num(i+1)+": "+
        query_num(result)+".\n");
    if(result > 4) {
      if(num_dice == 1) {
        tell_object(player, arg()->short()+" says: You have won this "
            "life back.\n");
        player->adjust_deaths(-11);
      }
      else {
        tell_object(player, arg()->short()+" says: A successful roll.\n");
        player->adjust_deaths(-1);
        tell_object(player, arg()->short()+" says: I will return some of "
            "your lifeforce for your luck.\n");
        player->adjust_deaths(-random(9)+1);
      }
    }
    else {
      tell_object(player, arg()->short()+" says: An unsuccessful roll.\n");
      if(num_dice > 1) {
        player->adjust_deaths(random(5)+5);
        tell_object(player, arg()->short()+" says: You know the penalty, "
            "some of your lifeforce is sacrificed to me.\n");
      }
    }
  }
  tell_object(player, arg()->short()+" says: Very well.  For now, "
      "farewell.\n");
  arg()->player_chat_5();
  remove_this_effect();
} /* finish_roll() */

/**
 * Sets the rolling status of the player.
 * Used to see if they should be rolling dice or not.
 */
void set_death_rolling() {
  if(!arg() || !objectp(arg())) {
    remove_this_effect();
    return;
  }
  tell_object(player, arg()->short()+" says: Now, it is time to choose "
      "your fate.  You may \"roll\" one, two or three dice.  Rolling "
      "more than one is a gamble against your remaining lifeforce, though "
      "you may win some of it back.  The choice, and the risk, is yours.\n");
  rolling = 1;
} /* set_death_rolling() */

/**
 * Remove the death_message effect from the person.
 */
void remove_death_message_effect() {
  remove_this_effect();
} /* remove_death_message_effect() */
