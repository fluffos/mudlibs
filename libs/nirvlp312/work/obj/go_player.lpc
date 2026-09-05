#include "living.h"
/* fiddled with by illarion on 2015.08.21
 * also removed Rump's debug stuff
 * updated reset() to reduce farming without preventing go players from working on initial load
 */

int current_problem, starts_thinking, problem_value, already_solved;
object solved_by, wrong_by;

string short() { return "Go player"; }

int id(string str) {
  return str == "go player" || str == "problem" || str == "board" ||
         str == "go board" || str == "player";
}

void reset(int arg) {
/* on reset, there is a 20% chance to reset the problem */
  if(current_problem != 3 && already_solved && !random(5))
    current_problem = 3;
  if (arg)
    return;
  name = "go player";
  level = 10;
  experience = 39000;
  max_hp = 100;
  hit_point = 100;
  weapon_class = 12;
  is_npc = 1;
  cap_name = "Go Player";
  alignment = 200;
  enable_commands();
  /* on initial load, the player is always ready to give out exp */
  current_problem = 3;
}

int show_problem() {
  string board;

  switch(current_problem) {
  case 3:
    board = "5|.......\n" +
            "4|.......\n" +
            "3|@@@@@..\n" +
            "2|OOOO@..\n" +
            "1|...O@..\n" +
            " --------\n" +
            "  abcdefg\n" +
            "\nIt is black ('@') to play.\n";
    break;
  case 2:
    board = "7|.......\n" +
            "6|.......\n" +
            "5|@@@....\n" +
            "4|OOO@@..\n" +
            "3|O.OO@..\n" +
            "2|...O@..\n" +
            "1|..OO@..\n" +
            " --------\n" +
            "  abcdefg\n" +
            "\nIt is black ('@') to play.\n";
    break;
  case 1:
    board = "5|..........\n" +
            "4|...@@@@@..\n" +
            "3|@@@.O...@.\n" +
            "2|@OO@OOOO@.\n" +
            "1|@OO.O...@.\n" +
            " -----------\n" +
            "  abcdefghij\n" +
            "\nIt is white ('O') to play.\n";
    break;
  default:
    write("The go player doesn't want to be bothered anymore.\n");
    return 1;
  }

  write("The board looks like this:\n\n");
  say(this_player()->query_name() + " examines the go problem.\n");
  write(board);
  return 1;
}

void long(string str) {
  if (str == "go player" || str == "player") {
    write("A man sitting beside a go board, concentrating on a problem.\n");
    write("He looks as if he wants help. Why not look at his problem,\n");
    write("and tell him where to play ?\n");
    return;
  }
  if (str == "problem" || str == "board" || str == "go board")
    show_problem();
}


int catch_tell(string str) {
  string who, what;
  if (sscanf(str, "%s tells you: play %s\n", who , what) == 2 ||
      sscanf(str, "%s says: play %s\n", who , what) == 2) {
    set_heart_beat(1);
    switch(current_problem) {
    case 3:
      if (what == "b1" || what == "b 1" || what == "1b" || what == "1 b")
        solved_by = this_player();
      else
        wrong_by = this_player();
      problem_value = 50;
      break;
    case 2:
      if (what == "b2" || what == "b 2" || what == "2b" || what == "2 b")
        solved_by = this_player();
      else
        wrong_by = this_player();
      problem_value = 100;
      break;
    case 1:
      if (what == "d3" || what == "d 3" || what == "3d" || what == "3 d") {
        solved_by = this_player();
        already_solved = 1;
      } else
        wrong_by = this_player();
      problem_value = 200;
      break;
    default:
      return 0;
    }
    starts_thinking = 1;
  } else if (sscanf(str, "%s tells you: %s", who, what) == 2) {
    say("The go player says: what ?\n");
    return 1;
  }
}

void heart_beat() {
  age += 1;
  already_fight = 0;
  attack();
  
  if (starts_thinking) {
    say("The go player contemplates a proposed play.\n");
    starts_thinking = 0;
    return;
  }

  if (solved_by) {
    say("The go player says: Right ! That works !\n" +
        "He immediately plays out a new problem.\n");
    tell_object(solved_by,
                "You feel that you have gained some experience.\n");
    solved_by->add_exp(problem_value);
    solved_by = 0;
    current_problem--;
    set_heart_beat(0);
  }
  if (wrong_by) {
    say("The go player says: No, that doesn't work.\n");
    say("He sinks back into his deep thought.\n");
    wrong_by = 0;
    set_heart_beat(0);
  }
}

string query_name() { return "go player"; }
