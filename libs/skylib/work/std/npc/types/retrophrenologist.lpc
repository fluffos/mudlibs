/**
 * This is a special type of npc that will move stat points around.
 * @author Pinkfish
 * @started Fri May 19 22:56:20 PDT 2000
 */
inherit NPC_OBJ;

#include <money.h>
#include <position.h>

#define RETRO_PROP "retrophrenologist"
#define RETRO_TIME_PROP "last retrophrenologist"

#define RETRO_INITIAL_STATE      1
#define RETRO_DECREASE_STATE     2
#define RETRO_INCREASE_STATE     3
#define RETRO_CHECK_COST_STATE   4
#define RETRO_DO_PROCEDURE_STATE 5

#define RETRO_COST_PER_POINT 40000
// 6 weeks...
#define RETRO_TIME_BETWEEN_SESSIONS (6 * 7 * 24 * 60 * 60)

private object _busy_with;
private int _last_comment;
private int _state;
private string _decrease_stat;
private string _increase_stat;

void do_modify(object player);
void do_set_stat(object player, string stat);
void do_strength(object player);
void do_intelligence(object player);
void do_wisdom(object player);
void do_dexterity(object player);
void do_consitution(object player);
void do_yes(object player);
void do_no(object player);

void create() {
   _state = RETRO_INITIAL_STATE;
   ::create();
} /* create() */

void setup_responses() {
   add_respond_to_with(({ "@say", "modify", "stats" }),
                       (: do_modify :));

   add_respond_to_with(({ "@say", ({ "strength", "str"}) }), 
                         "#do_set_stat" );
   add_respond_to_with(({ "@say", ({ "intelligence", "int" }) }),
                         "#do_set_stat" );
   add_respond_to_with(({ "@say", ({ "wisdom", "wis" }) }),
                         "#do_set_stat" );
   add_respond_to_with(({ "@say", ({ "dexterity", "dex" }) }),
                         "#do_set_stat" );
   add_respond_to_with(({ "@say", ({ "constitution", "con" }) }),
                         "#do_set_stat" );

   add_respond_to_with(({ "@say", "yes" }),
                       (: do_yes :));
   add_respond_to_with(({ "@nod", query_name() }), (: do_yes :));
   add_respond_to_with(({ "@say", "no" }),
                       (: do_no :));
   add_respond_to_with(({ "@shake", query_name() }), (: do_no :));
} /* setup_responses() */

/**
 * This method returns the cost of getting your head smashed.
 * @return the cost of getting your head smashed
 */
int query_cost_of_smashing(object player) {
   int ret;

   ret = player->query_property(RETRO_PROP);
   return (ret + 1) * RETRO_COST_PER_POINT;
} /* query_cost_of_smashing() */

/**
 * This method returns the longer name of the short stat.
 * @param name the short stat name
 * @return the long stat name
 */
string query_stat_name(string name) {
   switch (name) {
   case "str" :
      return "brawn";
   case "con" :
      return "vigour";
   case "dex" :
      return "flexibility";
   case "int" :
      return "intellect";
   case "wis" :
      return "intuition";
   default :
      return "stone the crows";
   }
} /* query_stat_name() */

/**
 * This method is called to set the stat when in the correct states.
 * @param stat the stat to change
 * @return 1 if successful, 0 if not
 */
int set_modify_stat(string stat) {
   string place;
   int cost;

   switch (_state) {
   case RETRO_DECREASE_STATE :
      _decrease_stat = stat;
      if (call_other(_busy_with, "query_real_" + stat) <= 8) {
         do_command("sayto " + _busy_with->query_name() +
                 " Sorry, but your " + query_stat_name(stat) +
                 " is too low already!");
         _busy_with = 0;
         return 0;
      }
      _state = RETRO_INCREASE_STATE;
      do_command("sayto " + _busy_with->query_name() +
                 " Whooo!  Great, so what ability would you like to "
                 "increase?");
      break;
   case RETRO_INCREASE_STATE :
      _increase_stat = stat;
      if (call_other(_busy_with, "query_real_" + stat) >= 23) {
         do_command("sayto " + _busy_with->query_name() +
                 " Sorry, but your " + query_stat_name(stat) +
                 " is far too high!");
         _busy_with = 0;
         return 0;
      }
      if (_increase_stat == _decrease_stat) {
         do_command("sayto " + _busy_with->query_name() +
                 " Increasing the same thing your decreasing?  Even "
                    "the bumps on your head are not that confused.");
         _busy_with = 0;
         return 0;
      }
      cost = query_cost_of_smashing(_busy_with);
      place = query_property("place");
      if (!place) {
         place = "default";
      }
      _state = RETRO_CHECK_COST_STATE;
      do_command("emote feels the bumps on " +
                 _busy_with->poss_short() + " head speculatively.");
      do_command("sayto " + _busy_with->query_name() +
                 " It will cost you " +
                 MONEY_HAND->money_value_string(cost, place) +
                 " to smash your head into the shape required to increase your "
                 + query_stat_name(_increase_stat) + " at the detriment to your "
                 + query_stat_name(_decrease_stat) + "." /*It may cause a small "
                 "amount of incapacitance in some subjects and it may take you "
                 "a while to totally restore your faculties. A few of my "
                 "patients have been complete butterfingers after their "
                 "treatment but they recovered nicely.  It's a perfectly safe "
                 "procedure however!"*/);
      do_command("sayto " + _busy_with->query_name() +
                 " Do you wish to continue?");
      break;
   }
   return 1;
} /* set_modify_stat() */

/**
 * This method returns if the npc is busy or not without printing
 * anything.
 * @return 1 if busy, 0 if not
 */
int is_busy(object player) {
   if (_state == RETRO_DO_PROCEDURE_STATE) {
      return 1;
   }
   if (_busy_with &&
       _busy_with != player &&
       environment(_busy_with) == environment() &&
       time() - _last_comment < 5 * 60) {
      return 1;
   }
   return 0;
} /* is_busy() */

/**
 * This method checks to see if they are in the initial state.
 * @return 1 if initial state, 0 if not
 */
int is_initial_state() {
   if (_state == RETRO_INITIAL_STATE) {
      return 1;
   }
   return 0;
} /* is_initial_state() */

/**
 * This method checks to see if the npc is busy with someone else.
 * It prints an error message if they are busy.
 * @param player the person to check
 * @return 1 if they are busy
 */
int check_busy_with(object player) {
   if (is_busy(player)) {
      if (_state == RETRO_DO_PROCEDURE_STATE) {
         do_command("sayto " + player->query_name() +
                    " This is a delicate procedure, please do not interrupt.");
         return 1;
      }
      do_command("sayto " + player->query_name() +
                 " Can't you see I am busy with " + _busy_with->the_short() +
                 "?");
      do_command("sayto " + player->query_name() +
                 " Talk to me after I have finished with " +
                 _busy_with->query_objective() + ".");
      return 1;
   }
   if (_busy_with != player) {
      _state = RETRO_INITIAL_STATE;
   }
   _busy_with = player;
   _last_comment = time();
   return 0;
} /* check_busy_with() */

/** @ignore yes */
void do_modify(object player) {
   if (check_busy_with(player)) {
      return ;
   }
   if (_state != RETRO_INITIAL_STATE &&
       _state != RETRO_DECREASE_STATE) {
      do_command("sayto " + _busy_with->query_name() +
                 " I am confused.  You are not answering my questions properly!");
      do_command("signore " + _busy_with->query_name());
      _busy_with = 0;
      return ;
   }

// Remove this if statment after PT, is here just to fix a typo in the property
   if (player->query_property("last retrophenologist")) {
       player->add_property(RETRO_TIME_PROP, 
                           player->query_property("last retrophenologist"));
       player->remove_property("last retrophenologist");
   }
// endif
   if (player->query_property(RETRO_TIME_PROP) + RETRO_TIME_BETWEEN_SESSIONS > time()) {
      do_command("emote feels " + player->poss_short() + " head and "
                 "makes 'tch'ing noises.");
      do_command("sayto " + player->query_name() +
                 " Your bumps have not yet settled back down to a uniform "
                 "feeling of oneness.  Come back again soon.");
      _busy_with = 0;
      return ;
   }
   do_command("sayto " + _busy_with->query_name() +
              " So you would like to get some stats modified...  Which one "
              "would you like decreased?");
   _state = RETRO_DECREASE_STATE;
} /* do_modify() */

/** @ignore yes */
void do_set_stat(object player, string stat) {

   stat = stat[0..2]; // Get the required three letter stat

   if (_state == RETRO_INITIAL_STATE) {
      return ;
   }

   if (check_busy_with(player)) {
      return ;
   }
   if (_state != RETRO_DECREASE_STATE &&
       _state != RETRO_INCREASE_STATE) {
      do_command("sayto " + _busy_with->query_name() +
                 " I am confused.  You are not answering my questions properly!");
      do_command("signore " + _busy_with->query_name());
      _busy_with = 0;
      return ;
   }

   if (!set_modify_stat(stat)) {
      return ;
   }
} /* do_set_stat() */

/** @ignore yes */
void do_no(object player) {
   if (_state == RETRO_INITIAL_STATE) {
      return ;
   }

   if (check_busy_with(player)) {
      return ;
   }
   if (_state == RETRO_DECREASE_STATE) {
      do_command("boggle gently at " + _busy_with->query_name());
      do_command("sayto " + _busy_with->query_name() +
                 " No? Nose? You want me do decrease your nose?  Now now. "
                 "What stat did you want to decrease?");
      return;
   }
   if (_state == RETRO_INCREASE_STATE) {
      do_command("sayto " + _busy_with->query_name() +
                 " No? Know? How should I know what you want?  Now tell me "
                 "what stat did you want to increase?");
      return;
   }
   if (_state != RETRO_CHECK_COST_STATE) {
      do_command("frown in bewilderment");
      do_command("sayto " + _busy_with->query_name() +
                 " No?  Where does the no come from?");
      _busy_with = 0;
      return ;
   }

   do_command("sayto " + _busy_with->query_name() +
                 " Ok, well thanks for the business.  Come back when you have "
              "changed your mind.");
   _busy_with = 0;
} /* do_no() */

/** @ignore yes */
void do_yes(object player) {
   int cost;
   string place;

   if (_state == RETRO_INITIAL_STATE) {
      return ;
   }

   if (check_busy_with(player)) {
      return ;
   }
   if (_state == RETRO_DECREASE_STATE) {
      do_command("emote looks up from a dented hammer");
      do_command("sayto " + _busy_with->query_name() +
                 " Yes? Yes?! Eh What? What stat did you want to decrease?");
      return;
   }
   if (_state == RETRO_INCREASE_STATE) {
      do_command("blink in confusion");
      do_command("sayto " + _busy_with->query_name() +
                 " Yes? Yes what? You want to increase your Yes stat? Be "
                 "serious now, what stat did you want to increase?");
      return;
   }

   if (_state != RETRO_CHECK_COST_STATE) {
      do_command("sayto " + _busy_with->query_name() +
                 " Yes yes yes.  No..\n");
      _busy_with = 0;
      return ;
   }

   do_command("sayto " + _busy_with->query_name() +
                 " Great!  I will see what I can do.");
   cost = query_cost_of_smashing(player);
   place = query_property("place");
   if (!place) {
      place = "default";
   }
   if (player->query_value_in(place) < cost) {
      do_command("nudge " + _busy_with->query_name());
      do_command("sayto " + _busy_with->query_name() +
                 " Umm, sorry to bring this up.  But you do not have " +
                 MONEY_HAND->money_value_string(cost, place) + ".");
      do_command("sayto " + _busy_with->query_name() +
                 " Do come back when you are a little richer.");
      _busy_with = 0;
      return ;
   }

   player->pay_money(MONEY_HAND->create_money_array(cost, place));
   _state = RETRO_DO_PROCEDURE_STATE;
   do_command("emote pockets the money as payment from " +
              _busy_with->the_short() + ".");
   do_command("emote feels around on " + _busy_with->poss_short() + " head.");
   call_out("do_next_stage", 2);
} /* do_no() */

/** @ignore yes */
void do_next_stage(int stage) {
   object *obs;

   if (!_busy_with) {
      do_command("'Whoops!  They left.");
      _state = RETRO_INITIAL_STATE;
      return ;
   }
   if (environment(_busy_with) != environment()) {
      do_command("tell " + _busy_with->query_name() +
                 " I cannot complete this procedure if you walk off.");
      do_command("tell " + _busy_with->query_name() +
                 " There is a no money back policy.");
      _busy_with = 0;
      _state = RETRO_INITIAL_STATE;
      return ;
   }
   switch (stage) {
   case 0 :
      //
      // If there is a chair here, sit them in it.
      //
      obs = match_objects_for_existence("chairs", ({ environment() }));
      SITTING_CMD->position_object(obs, "on", _busy_with);
      do_command("emote starts to strap " + _busy_with->the_short() +
                 " into the chair.");
      break;
   case 1 :
      do_command("emote measures " + _busy_with->poss_short() +
                 " head with a somewhat battered looking tape measure.");
      break;
   case 2 :
      do_command("emote pulls out a huge hammer and licks " +
                 query_possessive() + " lips.");
      break;
   case 3 :
      do_command("emote squints and lines the hammer up.");
      break;
   case 4 :
      do_command("'Don't worry.  You won't feel a thing!");
      break;
   case 5 :
      do_command("emote thumps the hammer down hard on " +
                 _busy_with->poss_short() + " head, blood and bits of "
                 "hair spray around the room.");
      tell_object(player,
                  "You feel immediately loose consciousness and feel "
                  "pretty messed up.\n");
      _busy_with->add_property(RETRO_TIME_PROP, time());
      _busy_with->add_property(RETRO_PROP,
                               _busy_with->query_property(RETRO_PROP) + 1);
      _busy_with->add_effect("/std/effects/other/out_cold", 360);
      call_other(_busy_with, "adjust_" + _increase_stat, 1);
      call_other(_busy_with, "adjust_" + _decrease_stat, -1);
      _busy_with->adjust_tmp_con(
            (_busy_with->query_con() - 8) < 0 ? _busy_with->query_con() : -8);
      _busy_with->adjust_tmp_str(
            (_busy_with->query_str() - 8) < 0 ? _busy_with->query_str() : -8);
      _busy_with->adjust_tmp_dex(
            (_busy_with->query_dex() - 8) < 0 ? _busy_with->query_dex() : -8);
      _busy_with->adjust_tmp_wis(
            (_busy_with->query_wis() - 8) < 0 ? _busy_with->query_wis() : -8);
      _busy_with->adjust_tmp_int(
            (_busy_with->query_int() - 8) < 0 ? _busy_with->query_int() : -8);
      break;
   case 6 :
      do_command("emote looks a little worried and checks " +
                 _busy_with->poss_short() + " pulse, then smiles "
                 "brightly.");
      break;
   case 7 :
      do_command("emote cleans off " + query_possessive() +
                 " hammer and smiles happily.");
      break;
   case 8 :
      do_command("'Another job well done.");
      break;
   case 9 :
      do_command("emote rubs " + _busy_with->poss_short() + " head "
                 "and smiles.");
      break;
   case 10 :
      do_command("sayto " + _busy_with->query_name() +
                 " I think you will find that did the trick.");
      break;
   case 11 :
      do_command("emote pushes " + _busy_with->poss_short() +
                 " unconscious body off the chair onto the floor.");
      do_command("say Next please!");
      LYING_CMD->position_floor(_busy_with, 1);
      _state = RETRO_INITIAL_STATE;
      _busy_with = 0;
      return ;
   }
   call_out("do_next_stage", 4, stage + 1);
} /* do_next_stage() */
