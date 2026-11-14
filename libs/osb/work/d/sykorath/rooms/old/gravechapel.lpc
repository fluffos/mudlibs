// the chapel belongs to the graveyard of the outer city
// made by magictcs - 7 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

int cross,torch,ruby;

//******************
// property handling
//******************
int QueryTorch()    { return torch; }
int SetTorch(int t) { torch=t; return torch; }
int QueryCross()    { return cross; }
int SetCross(int c) { cross=c; return cross; }
int QueryRuby()     { return ruby; }
int SetRuby(int r)  { ruby=r; return ruby; }

//*************
// get handling
//*************
int gettake(string str) {
  object obj;
  if (!str) return 0;
  if (present(str)) return 0;         // allow the get command
  if (member(({"torch","torches"}),str)!=-1) {
    if (torch) {
      obj=clone_object("/obj/torch");
      TP->Take(obj,PUTGET_FULL);
      torch--;
      return 1;
    }
    return 0;
  }
  if (member(({"cross","silver cross"}),str)!=-1) {
    // allow get cross?
    if (cross) {
      cross--;
      obj=clone_object(OBJ("gravecross"));
      if (obj) {
        if ((obj->move(TP,M_SILENT))!=ME_OK) {
          write("You can't hold the cross.\n");
          obj->move(TO,M_SILENT);
          return 1;
        }
      } else { write("Notify a wizard please.\n"); return 1; }
      write(
        "As you take the cross, the red ruby falls down to the ground "
        "and breaks into thousand pieces. Better you had broken it out of "
        "the cross before!\n");
      show(NAME+" takes the cross.\n");
      return 1;
    }
    write("There is no cross left actually. Come back later.\n");
    return 1;
  }
  if (member(({"ruby","ruby of cross","ruby of silver cross"}),str)!=-1) {
    if (!cross) {
      write("There is no cross with a ruby here!\n");
      return 1;
    }
    write("The ruby is stuck to the cross. But maybe you can break it out "
      "of the cross?\n");
    show(NAME+" tries to take the ruby of the cross.\n");
    return 1;
  }
  return 0;
}

//**************
// light command
//**************
int lighttorch(string str) {
  if (!str) return 0;
  if (present(str) || present(str,TP)) return 0;
  if (member(({"torch","torches"}),str)!=-1) {
    switch (torch) {
      case 0: return 0;
      case 1: write("The torch is already light.\n"); return 1;
      case 2: write("The torches are already lighten.\n"); return 1;
    }
    return 1;
  }
  return 0;
}

//*****
// pray
//*****
int pray(string str) {
  if (str) { notify_fail("Use: pray\n"); return 0; }
  if (TP->QueryGhost()) {
    show(NAME+" prays.\n");
    write("Your prayer is heared by our local god.\n");
    TP->SetGhost(0);
    return 1;
  }
  write("You fold your hands and pray to your local god.\n");
  show(NAME+" prays.\n");
  return 1;
}

//****************
// unlight command
//****************
int unlighttorch(string str) {
  if (!str) return 0;
  if (present(str) || present(str,TP)) return 0;
  if (member(({"torch","torches"}),str)!=-1) {
    switch (torch) {
      case 0: return 0;
      case 1: write("The priest will be very angry if you do this!\n");
              return 1;
      case 2: write("The priest will not allow this.\n"); return 1;
    }
    return 1;
  }
  return 0;
}

//***********
// break ruby
//***********
int breakruby(string str) {
  notify_fail("Break what out of where?\n");
  if (!str) return 0;
  if (member(({"ruby out of cross","ruby out of the cross",
    "ruby out of silver cross","ruby out of the silver cross"}),str)!=-1) {
    if (!cross) {
      write("There is no cross here!\n");
      return 1;
    }
    write("You try to break the ruby out of the cross.\n"
      "You touch the ruby of the cross to break the ruby out of it.\n"
      "Something happens....\n"
      "The world around you becomes darker and darker.\n"
      "You are sucked away by an evil force.....\n");
    show(NAME+" works with the cross.\n");
    TP->move(SYKORATH("tomb"),M_SILENT);
    return 1;
  }
  return 0;
}

//***************
// detailhandling
//***************
string lookaltar() {
  string ret;
  ret="It is a small altar, because it is a small chapel.\n";
  if (cross) {
    switch (torch) {
      case 0:  return ret+"A silver cross stands near the altar.\n";
      case 1:  return ret+"A silver cross stands near the altar. Left of the "
                 "altar is a torch.\n";
      default: return ret+"A silver cross stands near the altar. The altar "
                "is right between two torches.\n";
    }
  } else {
    switch (torch) {
      case 0:  return ret;
      case 1:  return ret+"Left of the altar is a torch.\n";
      default: return ret+"The altar is right between two torches.\n";
    }
  }  
}

string lookcross() {
  if (cross) return
    "The silver cross looks very expensive. A red ruby is mounted to the\n"
    "cross.\n";
  return 0;
}

string looktorch() {
  switch (torch) {
    case 0: return 0;
    case 1: return "There is a torch left of the altar.\n";
  }
  return "There are two torches.\n";
}

string lookruby() {
  if (cross && ruby) return
    "It is a wonderful ruby. Are you able to break it out?\n";
  return 0;      // no ruby or no cross
}

// special long
string QueryIntLong() {
  string ret;
  ret=
    "You are standing in a small chapel. It is used to think about your\n"
    "beloved and to hold the commemoration.\n";
  if (cross) ret+="A silver cross is standing near the altar.\n";
  return ret;
}

//*******
// create
//*******
create() {
  ::create();
  cross=1;
  torch=2;
  ruby=1;
  SetIntShort("In a small chapel.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"chapel","small chapel"}),#'IntLong);
  AddDetail(({"exit","west"}),"You can leave the chapel by going west.\n");
  AddDetail(({"grave","graves"}),
    "You are standing in a chapel - no graves are here.\n");

  AddDetail(({"cross","silver cross"}),#'lookcross);
  AddDetail(({"torch","torches"}),#'looktorch);
  AddDetail("altar",#'lookaltar);
  AddDetail(({"ruby","ruby of cross","ruby of silver cross"}),
    #'lookruby);

  /* commands */
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("break",#'breakruby);
  AddRoomCmd("light",#'lighttorch);
  AddRoomCmd("unlight",#'unlighttorch);
  AddRoomCmd("extinguish",#'unlighttorch);
  AddRoomCmd("pray",#'pray);

  /* exits */
  AddExit("west","./graveyard3");
}

//******
// reset
//******
reset() {
  ::reset();
  if (cross) {
    if (torch<2) {
      tell_room(TO,"A priest comes along and replaces some torches.\n");
    }
  } else {
    if (torch<2) {
      tell_room(TO,
        "A priest comes along and replaces the cross and some torches.\n");
    } else {
      tell_room(TO,
        "A priest comes along and replaces the silver cross.\n");
    }
  }
  cross=1;
  torch=2;
  ruby=1;
}
