// the go player problem
// adapted by Magictcs - 18 jun 1997
// TODO: add new problems

#include <properties.h>
#include <secure/wizlevels.h>
#include <sykorath.h>

inherit "/std/npc";

int current_problem;
int is_solved;

//******************
// property handling
//******************
int QueryProblem() { return current_problem; }
int SetProblem(int prob) { current_problem=prob; return current_problem; }
int QueryIsSolved() { return is_solved; }     // read only

//*******
// create
//*******
create(){
  if (::create()) return 1;
  SetName("Go player");
  AddId("player");
  AddAdjective("go");
  SetShort("a Go player with a go board");
  SetLong(
    "A man sitting beside a go board, concentrating on a problem.\n"
    "He looks as if he wants help. Why not look at his problem,\n"
    "and tell him where to play ?\n");
  SetRace("human");
  SetLevel(10);
  SetAlign(200);
  SetXP(39000);
  SetHP(100);
  SetHands( ({ ({"right hand",0,6}), ({"left hand",0,6}) }) );
  InitChats(1,({
    "Go player says: Hm. This is tricky!\n",
    "Go player says: The moron who wrote this book didn't deal with this "
                     "problem.\n",
    "Go player says: A throw in here should just be wasted.\n",
    "Go player says: This group is more alive than I am.\n",
    "Go player says: This is simple using oi-otoshi.\n"}) );
  reset();
}

//**************************
// one game after each reset
//**************************
reset() {
  ::reset();
  current_problem = random(6);
  is_solved = 0;
}

// add some special hacks to allow looking at the board and the problem
init(){
  ::init();
  add_action("examine","examine");
  add_action("examine","look");
  add_action("examine","exa");
  add_action("examine","l");
  add_action("play","play");
}

//**************************
// return the actual problem
//**************************
show_problem(){
  if (is_solved) {
    show(NAME+" tries to examine the go problem.\n");
    return "THe Go player looks a little bit tired.\n";
  }
  show(NAME+" examines the go problem.\n");
  return "The board looks like this:\n\n"
    + ({ "5|.........\n"
         "4|....OOO..\n"
         "3|.OOO@@O .\n"
         "2|.O@@.@@O.\n"
         "1|.O@...@O.\n"
         " ----------\n"
         "  abcdefghi\n\n"
         "It is black ('@') to play.\n",

         "5|.......\n"
         "4|@@@....\n"
         "3|OOO@...\n"
         "2|..OO@..\n"
         "1|...O@..\n"
         " --------\n"
         "  abcdefg\n\n"
         "It is black ('@') to play.\n",

        "5|.....\n"
        "4|OOO..\n"
        "3|@@@O.\n"
        "2|..@O.\n"
        "1|@.@O.\n"
        " -----------\n"
        "  abcde\n\n"
        "It is white ('O') to play.\n",

        "5|.....\n"
        "4|.OOO.\n"
        "3|@@@O.\n"
        "2|..@O.\n"
        "1|.@...\n"
        " -----------\n"
        "  abcde\n\n"
        "It is black ('@') to play.\n",

        "5|.....\n"
        "4|.OO..\n"
        "3|O@@..\n"
        "2|.O...\n"
        "1|.....\n"
        " -----------\n"
        "  abcde\n\n"
        "It is white ('O') to play.\n",

        "6|......\n"
        "5|..OO..\n"
        "4|.O@O..\n"
        "3|.O@...\n"
        "2|.O....\n"
        "1|......\n"
        " -----------\n"
        "  abcdef\n\n"
        "It is white ('O') to play.\n",

 })  [current_problem];
}

//***************************
// l,exa,look,examine problem
//***************************
int examine(string arg){
  if (!arg) return 0;
  if(member(({"board","at board","the board","at the board","go board",
    "at go board","the go board","at the go board","problem","at problem",
    "the problem","at the problem"}), arg)==-1) return 0;
  write(show_problem());
  if (!is_solved)
    write("Type: \"play <arg>\" to play.  (i.e. \"play a1\")\n");
  return 1;
}

//******************
// solve the problem
//******************
int play(string arg){
  if (!arg) {
    notify_fail("Use: play <coord>\n  for example: play d4\n"); return 0; }
  if(is_solved ==1) {
    write("The Go player is thinking of another problem.\n");
    return 1;
  }
  switch (current_problem) {
    case 0: if (member(({"e1","E1","1e","1E"}),arg)!=-1)
              is_solved = 1;
            break;
    case 1: if(member(({"b1","B1","1b","1B"}),arg)!=-1)
              is_solved = 1;
            break;
    case 2: if (member(({"b2","B2","2b","2B"}),arg)!=-1)
              is_solved = 1;
            break;
    case 3: if (member(({"a2","A2","2a","2A"}),arg)!=-1)
              is_solved = 1;
            break;
    case 4: if (member(({"d3","D3","3d","3D"}),arg)!=-1)
              is_solved = 1;
            break;
    case 5: if (member(({"d2","D2","2d","2D"}),arg)!=-1)
              is_solved = 1;
            break;
  }
  if(is_solved){
    tell_room(environment(),
      "The Go Player says: Great idea!  That solves this problem.\n");
    show(NAME+" solves the go players problem.\n");
    if(QUESTMASTER->QueryQuestSolved("go_problem",TP) == 0){
       QUESTMASTER->SetPlayerQuest("go_problem",TP);
       TP->AddXP(100);
       write("You feel more experienced now.\n");
    }
  } else {
    tell_room(environment(),"The Go Player says: No, that won't work.\n"); }
  return 1;
}

