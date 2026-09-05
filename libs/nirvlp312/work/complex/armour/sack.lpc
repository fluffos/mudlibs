#include <prop/item.h>
#include <combat.h>
#include <grammar.h>
#include <message.h>

inherit "complex/armour";
virtual inherit "basic/parser";

private int top,bottom;

string my_long() {
  return ("This sack has a top and a bottom and a large opening at the top."
          " It is very old and it should be easy to rip holes into its old"
          " cloth to make a kind of rudimentary armour out of it.\n"+
          (top?
           (bottom?
            "There are several holes in the sack already: "+top+
            " at the top and "+bottom+" at the bottom.\n" :
            "There "+(top>1? "are" : "is")+" "+describe("hole",0,0,top)+
            " near its top in it already.\n") :
           (bottom?
            "There "+(top>1? "are" : "is")+" "+describe("hole",0,0,bottom)+
            " near its bottom in it already.\n" :
            "")));
}

void create() {
  ::create();
  set_type("sack");
  set_short("a sack");
  set_name("sack");
  set_armour_long(#'my_long);
  add_item("opening","It is sewn close, so this sack cannot be used as a sack"
           " anymore.\n");
  set_rigid(0);
  add_rule("rip "G_TEXT" into the top of "G_ME,"head_rip");
  add_rule("rip "G_TEXT" into top of "G_ME,"head_rip");
  add_rule("rip "G_TEXT" into the bottom of "G_ME,"tail_rip");
  add_rule("rip "G_TEXT" into bottom of "G_ME,"tail_rip");
  add_error_message("rip","Try to rip a hole into the top or the bottom of"
                    " the sack.\n");
}

void init() { add_actions(); }

status do_action(string verb,mapping args) {
  mapping layout;
  int i;
  layout = query_property(P_WEARABLE);
  while (member(layout,"rip"+i))
    i++;
  switch (verb) {
  case "head_rip":
    layout["top"] += ({ "rip"+i });
    layout["rip"+i] = 0;
    layout["rip"+i,1] = "body extension";
    top++;
    send_message(({ M_PL,M_PL_VERB,"rip"," a hole into the top of ",
                    M_PL_POSSESSIVE,M_OBJECT,M_ME_NONE,"." }));
    return 1;
  case "tail_rip":
    layout["bottom"] += ({ "rip"+i });
    layout["rip"+i] = 0;
    layout["rip"+i,1] = "body extension";
    bottom++;
    send_message(({ M_PL,M_PL_VERB,"rip"," a hole into the bottom of ",
                    M_PL_POSSESSIVE,M_OBJECT,M_ME_NONE,"." }));
    return 1;
  }
}
