#include <properties.h>
#define QC "/obj/quest_control"
inherit "/std/npc";

int current_problem;
int is_solved;

create(){
  if (::create()) return 1;
  SetName("Go player");
  AddId("player");
  AddAdjective("go");
  SetShort("a Go player with a go board");
  SetLong(
"A man sitting beside a go board, concentrating on a problem. "
"He looks as if he wants help. Why not look at his problem, "
"and tell him where to play ?\n");
  SetRace("human");
  SetLevel(10);
  SetAlign(200);
  SetXP(39000);
  SetHP(100);
  SetHands( ({ ({"right hand",0,6}), ({"left hand",0,6}) }) );
  InitChats(1,({
    "Go player says: Hm. This is tricky!\n",
    "Go player says: The moron who wrote this book didn't deal with this problem.\n",
    "Go player says: A throw in here should just be wasted.\n",
    "Go player says: This group is more alive than I am.\n",
    "Go player says: This is simple using oi-otoshi.\n"}) );
  reset();
}

reset() {
  ::reset();
  current_problem = random(3);
  is_solved = 0;
}

init(){
  ::init();
  add_action("examine","examine");
  add_action("examine","look");
  add_action("examine","exa");
  add_action("examine","l");
  add_action("play","play");
 }

examine(arg){
  if (-1 == member(({"board", "at board", "the board", "at the board"
                    , "go board", "at go board", "the go board", "at the go board"
                    , "problem", "at problem", "the problem", "at the problem"
                   }), arg)
     )
    return 0;
  write(show_problem());
  write("Type: \"play <arg>\" to play.  (i.e. \"play a1\")\n");
  return 1;
}

show_problem(){
  say(this_player()->QueryName() + " examines the go problem.\n");
  return "The board looks like this:\n\n"
    + ({ ("5|.......\n\
4|.......\n\
3|@@@@@..\n\
2|OOOO@..\n\
1|...O@..\n\
 --------\n\
  abcdefg\n\
\nIt is black ('@') to play.\n"),
         ("7|.......\n\
6|.......\n\
5|@@@....\n\
4|OOO@@..\n\
3|O.OO@..\n\
2|...O@..\n\
1|..OO@..\n\
 --------\n\
  abcdefg\n\
\nIt is black ('@') to play.\n"),
        ("5|..........\n\
4|...@@@@@..\n\
3|@@@.O...@.\n\
2|@OO@OOOO@.\n\
1|@OO.O...@.\n\
 -----------\n\
  abcdefghij\n\
\nIt is white ('O') to play.\n") })[current_problem];
}

play(arg) {
  if (is_solved == 1) {
    notify_fail("The Go player is thinking of another problem.\n");
    return 0;
  }
  if (!arg)
    return 0;
    
  arg = norm_id(arg);

  if ( strlen(arg) > 2 || -1 != member(arg, ' '))
  {
    notify_fail("The Go Player looks puzzled.\n");
    return 0;
  }
    
  if(current_problem == 0){
    if(arg == "b1" || arg == "1b"){
       is_solved = 1;
       }
    }
  else if(current_problem == 1){
    if(arg == "b2" || arg == "2b"){
       is_solved = 1;
       }
    }
  else if(current_problem == 2){
    if(arg == "d3" || arg == "3d"){
       is_solved = 1;
       }
    }
  if (!is_solved)
  {
    write("The Go Player says: No, that won't work.\n");
    return 1;
  }
  tell_room(environment(),"The Go Player says: Great idea!  That solves this problem.\n");
  say(this_player()->QueryName()+" solves the go players problem.\n");
  if(QC->QueryQuestSolved("go_problem",this_player()) == 0){
     QC->SetPlayerQuest("go_problem",this_player());
     this_player()->AddXP(100);
     write("You feel more experienced now.\n");
     }
  call_out("new_problem",1);
  return 1;
 }

new_problem(){
  is_solved = 0;
  if(current_problem == 2){return current_problem = 0;}
  else return ++current_problem;
 }
