#include <moving.h>;
inherit "/std/container";
int fly;
int door_cl;
int tdown;

QueryIntShort() { return QueryShort(); }

QueryShort() {
    if (!tdown) return "A brand new rescue capsule";
    else return "A scrap heap";
}

QueryLong() {
      if (!tdown) {
	return "A brand new rescue capsule with an open door.\n"+
	"You think, it is your chance to get back "+
	"to the ground.\n";
      } else
	return "This is very rusty scrap.\n";
}

QueryIntLong() {
    if (!door_cl) {
      return "You are inside the rescue capsule.\n"+
      "The door is open.\n";
    } else if (!tdown) {
      return "You are inside the rescue capsule. There are "+
      "no windows.\nThe door is closed.\n";
    } else {
      return "It was an very hard touch down. Now the capsule "+
      "is a wreck. You can leave the wreck if you want.\n";
    }
}

init() {
    if (environment(this_player())!=this_object()) {
      add_action("enter", "enter");
      add_action("close_a", "close");
    } else {
      add_action("leave", "leave");
      add_action("leave", "out");
      add_action("close", "close");
      add_action("open", "open");
    }
}

enter(str) {
    if (str != "capsule" && str!="heap" && str!="scrap") return;
    if (!tdown) this_player()->move(this_object(),M_GO,"into the capsule");
    else return 0;
    return 1;
}

leave() {
  if (!door_cl) {
    this_player()->move(object_name(environment()), M_GO, "the capsule");
  } else if (!tdown) {
    write("You can't leave the capsule; the door is closed.\n");
  } else
    this_player()->move("/d/archwiz/common/room/city/field", M_GO, "the capsule");
  return 1;
}

open(str) {
  if (str=="door") {
    if (tdown)
      write("There is no door.\n");
    else
      write("The door is locked.\n");
  } else return 0;
  return 1;
}

close_a(str) {
  if (str=="door") {
    tell_object(this_player(),"The door-handle is inside the capsule.\n");
  } else return 0;
  return 1;
}

close(str) {
  if (!this_player()) return 0;
  if (str=="door") {
    tell_room(environment(this_object()),
      "Someone closed the door of the capsule. The capsule leaves "+
      "through the air lock and flies away.\n");
    tell_object(this_player(),"You close the door.\n");
    show(this_player()->QueryName()+"closes the door.\n",this_player());
    tell_room(this_object(),
       "Suddenly you hear a strange sound.\n"+
       "Now you enjoy the weightlessness.\n");
    call_other(environment(),"new_cap");
    this_object()->move("/d/archwiz/firestone/space",M_SILENT);
    door_cl=1;
    fly=1;
    set_heart_beat(1);
  } else return 0;
  return 1;
}

int count;
heart_beat() {
  object dest;
  count++;
  if (count==2) {
    say("The capsule falls down to earth...\n");
  } else if (count==4) {
    say("The capsule enters the earth's atmosphere...\n");
  } else if (count==6) {
    say("It is a very uncomfortable journey back to earth...\n");
  } else if (count==8) {
    say("It seems there is something wrong...\n");
  } else if (count==10) {
    say("The retro-rockets don't work...\n");
  } else if (count==12) {
    say("BBBOOOOOOOOOOOOOOOOOMMMMMMM!!!!!!!!\n");
  } else if (count==13) {
    set_heart_beat(0);
    say("This was a very hard touch down! But you are alive.\n");
    tdown=1;
    call_out("futsch",120);
    dest=find_object("/d/archwiz/common/room/city/field");
    if (!dest) dest=clone_object("/d/archwiz/common/room/city/field");
    this_object()->move(dest);
    tell_room(environment(),
        "BBBOOOOOOOOOOOOOOOOOMMMMMMM!!!!!!!!\n");
  }
}

futsch() {
  object dest;
  dest=find_object("/d/archwiz/common/room/city/field");
  if (!dest) dest=clone_object("/d/archwiz/common/room/city/field");
  transfer_all_to(dest);
  destruct(this_object());
}

create() {
   ::create();
   AddId("capsule");
   SetWeight(200000);
   SetMaxWeight(1000000);
   SetValue(200);
}

transfer_all_to(dest) {
  object *obs;
  int i;
  obs=all_inventory(this_object());
  for (i=0; i<sizeof(obs); i++) {
      obs[i]->move(dest,M_NOCHECK);
  }
  dest->SetWeight(dest->QueryWeight()+QueryWeight());
}
