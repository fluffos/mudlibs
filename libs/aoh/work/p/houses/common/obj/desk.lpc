/* This is a chair for to sit down on it and leave it again */

inherit "/p/houses/common/obj/furniture";

object sitting;

/*----------------------------------------------------------------------------*/
create() {
  ::create();
  SetDesignShort("a desk (Standard Dwarven Interior)");
  SetDesignLong("This is a very exclusive desk.\n");

  SetShort("a SDI-desk");
  SetLong("The desk looks like some elephant squeezed into the form\n"+
          "of an anvil. A loose trunk strengthens your impression.\n"+
          "A Standard Dwarven Interior mark labels the desk as one of\n"+
          "the finest things you ever can buy.\n");

  SetValue(5000);
  SetNoGet("Better you don't take the desk with you. What do you want with\n\
it out in the world?\n");
  SetWeight(5500);
  AddId("desk");
}
/*----------------------------------------------------------------------------*/
init() {
  ::init();
  add_action("sit_down","sit");
  add_action("leave","leave");
}
/*----------------------------------------------------------------------------*/
sit_down(string str) {
  if(!str || (str != "down" && (str[0..7] != "down on " ||
                present(str[8..]) != this_object()))) {
    notify_fail("Where do you want to sit on?\n");
    return 0;
  }
  if (sitting && present(sitting)) {
    notify_fail("Excuse, but " +
                (sitting == this_player()?
                "you are":capitalize(sitting->QueryName()) + " is") +
                " sitting on this chair.\n");
    return 0;
  }
  write("You sit down at the chair.\n");
  say(capitalize(this_player()->QueryName()) + " sits down on a chair.\n");
  sitting = this_player();
  return 1;
}
/*----------------------------------------------------------------------------*/
leave(string str) {
  if(str && present(str) != this_object()) {
    notify_fail("What do you want to leave?\n");
    return 0;
  }
  if(this_player() != sitting) {
    notify_fail("You weren't sitting at the chair.\n");
    return 0;
  }
  write("You leave the chair and stand up.\n");
  say(capitalize(this_player()->QueryName()) + " stands up from a chair.\n");
  sitting = 0;
  return 1;
}
/*----------------------------------------------------------------------------*/
      
