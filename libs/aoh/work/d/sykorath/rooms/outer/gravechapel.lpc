/*
 * the chapel belongs to the graveyard of the outer city
 *
 * introduced:
 * Magictcs 07 jul 97 - first version
 *
 * updated:
 * Magictcs - 23 feb 98 - remade, added skills, fixed commands
 */

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
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
  str=norm_id(str);
  if (present(str)) return 0;         // allow the get command
  if (sizeof(regexplode(str,
    "^(the|a|an|some|[ ])*(torch|torches)( (from|of) (the|a|an|[ ])*"
    "altar)*$"))==3) {
    if (torch) {
      obj=clone_object("/obj/torch");
      TP->Take(obj,PUTGET_FULL);
      torch--;
      return 1;
    }
    return 0;
  }
  if (sizeof(regexplode(str,
    "^(the|a|an|silver|[ ])*cross( (from|of) (the|a|an|[ ])*altar)$"))==3) {
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
  if (sizeof(regexplode(str,
    "^(the|a|an|red|[ ])*ruby( (out of|of|from) "
    "(the|a|an|silver|[ ])*cross)*$"))==3) {
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
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|some|[ ])*(torch|torches)$"))==3) {
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
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|some|[ ])*(torch|torches)$"))==3) {
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
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|red|[ ])*ruby( (out of|of|from) "
    "(the|a|an|silver|[ ])*cross)*$"))==3) {
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
    TP->move(OUTER("tomb"),M_GO);
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

string extra_cross() {
  if (cross)
    return "A silver cross is standing near the altar.\n";
  return 0;
}

//*******
// create
//*******
create() {
  string v_cross,v_altar,v_chapel,v_ruby1,v_ruby2,v_torch;
  ::create();
  cross=1;
  torch=2;
  ruby=1;

  SetIntShort("In a small chapel.\n");
  SetIntLong("You are standing in a small chapel. It is used to think "
    "about your beloved and to hold the commemoration.\n");
  SetExtraEntry("cross",P_INT_LONG,#'extra_cross);

  SetIndoors(1);
  SetCoordinates( ({ ({800,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  v_chapel = AddVItem( ([
    P_IDS:  ({"chapel"}),
    P_ADS:  ({"small"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"exit","west"}),
    P_LONG: "You can leave the chapel by going west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"grave","graves"}),
    P_LONG: "You are standing in a chapel - no graves are here.\n" ]) );

  v_cross = AddVItem( ([
    P_IDS:  ({"cross"}),
    P_ADS:  ({"silver"}),
    P_PREPS:({"of","on"}),
    P_LONG: #'lookcross ]) );
  v_torch = AddVItem( ([
    P_IDS:  ({"torch","torches"}),
    P_LONG: #'looktorch ]) );
  v_altar = AddVItem( ([
    P_IDS:  ({"altar"}),
    P_LONG: #'lookaltar ]) );
  v_ruby1 = AddVItem( ([
    P_IDS:  ({"ruby"}),
    P_ADS:  ({"red"}),
    P_LONG: #'lookruby ]),v_cross );
  v_ruby2 = AddVItem( ([
    P_IDS:  ({"ruby"}),
    P_ADS:  ({"red"}),
    P_LONG: #'lookruby ]) );

  /* commands */
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("break",#'breakruby);
  AddRoomCmd("light",#'lighttorch);
  AddRoomCmd("unlight",#'unlighttorch);
  AddRoomCmd("extinguish",#'unlighttorch);
  AddRoomCmd("pray",#'pray);
  AddSkill(SK_SEARCH,"cross",20,v_cross);
  AddSkill(SK_SEARCH,"altar",20,v_altar);
  AddSkill(SK_SEARCH,"ruby",20,v_ruby1);
  AddSkill(SK_SEARCH,"ruby2",20,v_ruby2);
  AddSkill(SK_SEARCH,"chapel",20,v_chapel);
  AddSkill(SK_SEARCH,"torch",20,v_torch);


  /* exits */
  AddExit("west","./graveyard3");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//******
// reset
//******
reset() {
  ::reset();
  if (cross) {
    if (torch<2) {
      tell_room(TO,
        "A priest comes along and replaces some missing torches.\n");
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

