// a special room with a special door :)
// just part of a new quest
// made by Magictcs - 29 jun 97

// TODO: add exits :)
// TODO: check the door handling
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

#define QUESTNAME "wheeldoor"

/* stores the position of the wheel */
int *wheels=({0,0,0,0,0});

/* stores the chars of the wheel */
// string contains the complete circle twice! */
string *wchars=({"FSLGDTPHFSLGDTPH",
                 "EIOEIO",
                 "TLWSTLWS",
                 "AIYEAIYE",
                 "YDFMRNYDFMRN"});

string *wheela_e=({
  //01234567890123456789012345678901234567890
    "  a b c         a             a   b    \n",
    "   \\|/          |     a   b    \\ /     \n",
    "  c-1-d    a  b-3-c    \\ /     /~\\     \n",
    "   /|\\     |    |       4   c-+ 5 +-d  \n",
    "  e f h    2    d      / \\     \\_/     \n",
    "  ^       / \\   ^     c   d    / \\     \n",
    "         b   c        ^       e   f    \n",
    "         ^                    ^\n"});
inherit BASEROOM;

//*******************
// property handling:
//*******************
int *QueryWheels(){ return wheels; }
int *SetWheels(int *new) { wheels=new; return wheels; }

//***********
// enter door
//***********
// TODO: close the door (or just let only the solver of the mini passing by?
int enter_door() {
  write("You enter the door to the north.\n");
  TP->move(SYKORATH("treasure"),M_GO,"north");
  return 1;
}

//***************
// detailhandling
//***************
string lookwheels() {
  string ret,tmp;
  int i;
  ret=
    "You see 5 wheels:\n";
  // get all 6 lines and change them according to the position of the wheels
  tmp=wheela_e[0];
  tmp[2]=wchars[0][wheels[0]];
  tmp[4]=wchars[0][wheels[0]+1];
  tmp[6]=wchars[0][wheels[0]+2];
  tmp[16]=wchars[2][wheels[2]];
  tmp[30]=wchars[4][wheels[4]];
  tmp[34]=wchars[4][wheels[4]+1];
  ret+=tmp;

  tmp=wheela_e[1];
  tmp[22]=wchars[3][wheels[3]];
  tmp[26]=wchars[3][wheels[3]+1];
  ret+=tmp;

  tmp=wheela_e[2];
  tmp[2]=wchars[0][wheels[0]+7];
  tmp[6]=wchars[0][wheels[0]+3];
  tmp[11]=wchars[1][wheels[1]];
  tmp[14]=wchars[2][wheels[2]+3];
  tmp[18]=wchars[2][wheels[2]+1];
  ret+=tmp;

  tmp=wheela_e[3];
  tmp[28]=wchars[4][wheels[4]+5];
  tmp[36]=wchars[4][wheels[4]+2];
  ret+=tmp;

  tmp=wheela_e[4];
  tmp[2]=wchars[0][wheels[0]+6];
  tmp[4]=wchars[0][wheels[0]+5];
  tmp[6]=wchars[0][wheels[0]+4];
  tmp[16]=wchars[2][wheels[2]+2];
  ret+=tmp;

  tmp=wheela_e[5];
  tmp[22]=wchars[3][wheels[3]+3];
  tmp[26]=wchars[3][wheels[3]+2];
  ret+=tmp;

  tmp=wheela_e[6];
  tmp[9]=wchars[1][wheels[1]+2];
  tmp[13]=wchars[1][wheels[1]+1];
  tmp[30]=wchars[4][wheels[4]+4];
  tmp[34]=wchars[4][wheels[4]+3];
  ret+=tmp;

  tmp=wheela_e[7];
  ret+=tmp;

  return ret;
}

//****************
// check if solved
//****************
int is_solved() {
  int i;
  for (i=0;i<5;i++) {
    if (wheels[i]!=0) return 0;        // not solved
  }
  return 1;                            // is solved
}

//***************
// turn wheel a-e
//***************
int turn_wheel(string str,int output) {
  object door;
  string *exp;
  int w;
  notify_fail("Use: Turn <1-5> left|right\n");
  if (!str) return 0;
  exp=explode(str," ");
  if (sizeof(exp)!=2) return 0;
  if (exp[1]!="left" && exp[1]!="right") return 0;
  if (strlen(exp[0])!=1) return 0;
  w=exp[0][0]-'0';
  if (w<1 || w>5) return 0;
  if (!output) {
    write("You turn the wheel "+w+" to the "+exp[1]+".\n");
    show(NAME+" turns a wheel.\n");
  }
  // w==wheel number, exp[1]=left|right
  if (exp[1]=="left")
    wheels[w-1]++;
  else wheels[w-1]--;
  // turn the other wheels too
  switch (w) {
    case 1: if (wheels[0]<0) wheels[0]=7;
            if (wheels[0]>7) wheels[0]=0;
            // turn wheel 3
            if (exp[1]=="left") {
              wheels[2]--;
            } else {
              wheels[2]++;
            }
            if (wheels[2]<0) wheels[2]=3;
            if (wheels[2]>3) wheels[2]=0;
            break;
    case 2: if (wheels[1]<0) wheels[1]=2;
            if (wheels[1]>2) wheels[1]=0;
            // turn wheel 1
            if (exp[1]=="left") {
              wheels[0]++;
            } else {
              wheels[0]--;
            }
            if (wheels[0]<0) wheels[0]=7;
            if (wheels[0]>7) wheels[0]=0;
            break;
    case 3: if (wheels[w-1]<0) wheels[w-1]=3;
            if (wheels[w-1]>3) wheels[w-1]=0;
            // turn no other wheel
            break;
    case 4: if (wheels[w-1]<0) wheels[w-1]=3;
            if (wheels[w-1]>3) wheels[w-1]=0;
            // turn wheel 5
            if (exp[1]=="left") {
              wheels[4]--;
            } else {
              wheels[4]++;
            }
            if (wheels[4]<0) wheels[4]=5;
            if (wheels[4]>5) wheels[4]=0;
            // turn wheel 1
            if (exp[1]=="left") {
              wheels[0]--;
            } else {
              wheels[0]++;
            }
            if (wheels[0]<0) wheels[0]=7;
            if (wheels[0]>7) wheels[0]=0;
            break;
    case 5: if (wheels[4]<0) wheels[4]=5;
            if (wheels[4]>5) wheels[4]=0;
            // turn wheel 2
            if (exp[1]=="left") {
              wheels[1]++;
            } else {
              wheels[1]--;
            }
            if (wheels[1]<0) wheels[1]=2;
            if (wheels[1]>2) wheels[1]=0;
            break;
    default: write("Please consult a wizard!\n");
  }
  if (!output) write(lookwheels());
  door=present("door");
  if (is_solved()) {
    if (door)
      door->SetLockState(LOCK_OPEN);
    else {
      if (!output) write("Please visit a wizard!\n");
      return 1;
    }
    if (!output) {
      tell_room(TO,"The door opens.\n");
      if (!QUESTMASTER->QueryQuestSolved(QUESTNAME,TP)) {
//        QUESTMASTER->SetPlayerQuest(QUESTNAME,TP);
        QUESTMASTER->qshout(NAME+" opens a special door!\n");
      }
    }
  } else {
    if (door->QueryLockState()==LOCK_OPEN) {
      door->SetLockState(LOCK_CLOSED);
      tell_room(TO,"The doors closes.\n");
    }
  }
  return 1;
}

//***************************
// turn some wheels by random
//***************************
void random_wheels() {
  string leftright;

  if (random(2)==1) leftright=="left";
  else leftright="right";
  turn_wheel((random(5)+1)+" "+leftright,1);

  turn_wheel((random(5)+1)+" "+leftright,1);

  if (random(2)==1) leftright=="left";
  else leftright="right";
  turn_wheel((random(5)+1)+" "+leftright,1);

  if (random(2)==1) leftright=="left";
  else leftright="right";
  turn_wheel((random(5)+1)+" "+leftright,1);

  if (random(2)==1) leftright=="left";
  else leftright="right";
  turn_wheel((random(5)+1)+" "+leftright,1);
  if (is_solved()) random_wheels();
}

//*******
// create
//*******
void create() {
  ::create();
  wheels[0]=0; wheels[1]=0; wheels[2]=0; wheels[3]=0; wheels[4]=0;
  SetIntShort("Near a safe");
  SetIntLong(
    "You are standing in a huge room. The north wall is blocked by a huge "
    "steel door. You see a some gear wheels with different numbers of "
    "teeth and a complicated machine which connects the wheels.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({42,50,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  // ({"door","steel door"}) -> by AddDoor
  AddDetail(({"safe"}),#'IntLong);
  AddDetail(({"wheels","wheel","gear wheel","gear wheels"}),#'lookwheels);
  AddDetail(({"machine","complicated machine"}),
    "The machine interconnects the 5 wheels. If you turn one of the wheels,\n"
    "some other wheels will turn too. If the special chars (pointed to with\n"
    "a '^') build a special word - the door will open!\n");
  AddDetail(({"word","special word"}),
    "You have to find the word by turning the wheels!\n");

  /* command */
  AddRoomCmd("turn",#'turn_wheel);                // turn a special wheel

  /* exits */
  AddDoor("north",#'enter_door,
    ([ P_SHORT:    "a steel door",
       P_LONG:     "A huge steel door with some wheels is blocking the way "
                   "to the north.\n",
       P_LOCKSTATE: LOCK_LOCKED,
       P_DOORCODE:  "safedoor",
       P_ADS:      ({"steel"}),
    ]) );
  HideDoor("north",HIDE_ALWAYS);
  AddExit("east","./44x50");
  random_wheels();
}

reset() {
  ::reset();
  tell_room(TO,"Suddenly the wheels turn a bit.\n");
  wheels[0]=0; wheels[1]=0; wheels[2]=0; wheels[3]=0; wheels[4]=0;
  random_wheels();
}

void notify_enter(object oldenv,int method,mixed extra) {
  object door;
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) {
    door=present("door");
    if (door) {
      door->SetLockState(LOCK_LOCKED);
      random_wheels();
      tell_room(TO,"As "+NAME+
        " enters the room - the wheels of the door turn randomly.\n");
    }
  }
}

