
#include <std.h>
#include <combo_cl.h>

inherit DAEMON;

// list of all possible combos
class Combo *allcombos = ({});

// list of all (potential) combos going on in the mud
class ComboProgress *allplayercombos = ({});

// max number of moves among all combos
int max_combo_pieces;

int check_combo(object, string);
int do_combo(object, string);
varargs int combo(object, string, int);
int match_combo(class ComboProgress, class Combo *);
void add_combo(string *, int);

void create() {
  ::create();

  add_combo( ({ "jab", "jab", "jab" }), 25);
  add_combo( ({ "jab", "jab", "headbutt" }), 20);
  add_combo( ({ "jab", "headbutt", "snapkick" }), 30);
  add_combo( ({ "snapkick", "jab", "jab", "palmstrike" }), 50);
  add_combo( ({ "headbutt", "jab" }), 20);
  add_combo( ({ "headbutt", "palmstrike" }), 20);
  add_combo( ({ "snapkick", "palmstrike" }), 20);
  add_combo( ({ "snapkick", "axekick" }), 20);
  add_combo( ({ "snapkick", "circlekick", "snapkick" }), 40);
  add_combo( ({ "jab", "palmstrike", "snapkick" }), 30);
  add_combo( ({ "palmstrike", "circlekick" }), 20);
  add_combo( ({ "palmstrike", "surgingblow" }), 25);
  add_combo( ({ "surgingblow", "circlekick" }), 25);
  add_combo( ({ "surgingblow", "chistrike", "circlekick" }), 30);
  add_combo( ({ "circlekick", "palmstrike", "axekick" }), 35);
  add_combo( ({ "palmstrike", "chistrike" }), 20);
  add_combo( ({ "chistrike", "surgingblow" }), 20);
  add_combo( ({ "palmstrike", "palmstrike", "eagleclaw" }), 35);
  add_combo( ({ "chistrike", "chistrike", "eagleclaw" }), 25);
  add_combo( ({ "chistrike", "chiblast" }), 35);
  add_combo( ({ "axekick", "chiblast" }), 30);
  add_combo( ({ "chiblast", "eagleclaw" }), 30);
  add_combo( ({ "chistrike", "palmstrike", "axekick", "circlekick", "surgingblow", "chiblast" }), 90);

}

// tp: player doing potential combo
// move: name of move being done
// checks if doing this move will finish a combo,
// returns the percentage damage bonus
int check_combo(object tp, string move) {
  return combo(tp, move, 1);
}

// tp: player doing the potential combo move
// move: name of the current move being done
// returns the percentage damage bonus
int do_combo(object tp, string move) {
  return combo(tp, move, 0);
}

// tp: player doing the move
// move: name of the move being done
// checkonly: if 1, don't actually modify the player's current combo info
varargs int combo(object tp, string move, int checkonly) {
  class ComboProgress player_combo;
  class ComboProgress *tmp;
  class Combo this_combo;
  int *srch_tmp;
  int ret = 0;

  if (nullp(tp) || nullp(move))
    return 0;

  if (nullp(checkonly))
    checkonly = 0;

  // first look up this player's current combo progress
  tmp = filter(allplayercombos, (: $1->name == $2 :), tp->query_name() );
  if (sizeof(tmp) == 1) {
    player_combo = copy(tmp[0]);
  }

  // no progress currently, create a blank one
  if (!player_combo) {
    player_combo = new(class ComboProgress);
    player_combo->name = tp->query_name();
  }

  // these two lines will always happen if we just created player_combo above
  if (!sizeof(player_combo->moves) || player_combo->times[<1] < time()-2) {
    player_combo->moves = ({});
    player_combo->times = ({});
  }

  // add current move to the player's combo progress
  player_combo->moves += ({ move });
  player_combo->times += ({ time() });

  // check if player performed a combo successfully
  if (sizeof(player_combo->moves) > 1) {

    // only keep track of the last X potential combo moves
    if (sizeof(player_combo->moves) > max_combo_pieces) {
      player_combo->moves = player_combo->moves[1..<1];
      player_combo->times = player_combo->times[1..<1];
    }

    ret = match_combo(player_combo, allcombos);
  }

  if (ret > 0) 
    ret = ret*2/3 + random(ret/3);
  else if (ret < 0)
    ret = ret*2/3 - random((-ret)/3);

  ret += 100;

  if (!checkonly) {

    // clear out the combo count if we performed one
    if (ret != 100)
      player_combo->moves = ({});

    // remove the original combo info that we copied
    if (sizeof(tmp) == 1) {
      allplayercombos -= ({ tmp[0] });
      tmp[0] = 0;
    }

    // put (possibly) new combo info back into the list (if it's not there)
    allplayercombos |= ({ player_combo });
  }

  return ret;

}

// player_combo: the potential combo to check against a list of actual combos
//   (will not be changed)
// allcombos: list of actual combos to check against
// returns a percentage damage bonus (0 if it didn't check out)
int match_combo(class ComboProgress player_combo, class Combo *allcombos) {
  class Combo *matchcombos;
  int sm, st;

  if (!player_combo || !sizeof(player_combo->moves))
    return 0;

  sm = sizeof(player_combo->moves) - 1;
  st = sizeof(player_combo->times) - 1;

  // check each combo
  foreach (class Combo this_combo in allcombos) {
    int i = sizeof(this_combo->moves) - 1;
    int m = sm;
    int t = st;
    int fail = 0;

    // compare moves, starting from most recent (end of the arrays)
    // make sure each move was done 2 seconds or less after previous
    // if anything doesn't match, break out as soon as possible to save cpu
    for ( ; i >= 0 && m >= 0 && t >= 0 ; i--, m--, t--) {
      if (player_combo->moves[m] != this_combo->moves[i]) {
        fail = 1;
        break;
      }
      if (t > 0) {
        int time = player_combo->times[t] - player_combo->times[t-1];
        if (time > 2) {
          fail = 1;
          break;
        }
      }
    }

    // i == -1 when we've gone through all the moves of this_combo
    // if nothing failed, then we consider this a match
    if (!fail && i == -1)
      return this_combo->bonus;

  }

  return 0;
}

void add_combo(string *moves, int bonus) {
  class Combo adding = new(class Combo);
  adding->moves = copy(moves);
  adding->bonus = bonus;
  if (sizeof(moves) > max_combo_pieces)
    max_combo_pieces = sizeof(moves);
  allcombos |= ({ adding });
}


