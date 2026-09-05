#include "/players/cobain/defines/ansi.h"
#include "/players/cobain/defines/common.h"


inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("cwiztell");
    set_alias("cwiztell");
    set_weight(0);
    set_value(0);
}

short() {return 0; } /* Invisible Item */
drop() { return 1; } /* Non Droppable */

init(){
   ::init();
   add_action("ctell", "tell");
   add_action("csay", "say");
   add_action("csay", "'");
   add_action("cemote", "emote");
   add_action("cemote", ":");

   add_action("title_me", "title_me");
   add_action("title_me2", "title_me2");
}


/* TALK FUNCTIONS */

ctell(str){
    object ob;
    string msg;
    string target;

    if (!str) return (notify_fail("Tell who ?\n"), 0);

  /* SETS TARGET USERNAME AND MESSAGE STRING */
    if ( sscanf(str, "%s %s", target, msg) != 2 ) {target = str;}
    target = lower_case(target);
    ob = find_player(target);

  /* CHECK FOR MESSAGE */
    if (!msg) return (notify_fail("Tell what ?\n"), 0);

   /* MESSAGE DAEMON */
    tell_object(ob, HIB+"-= " + HIR + TPN + HIB + " =-" + NORM + " \"" +msg+ ".\"\n");
    write("You tell " + capitalize(target) + ", \"" + msg + ".\"\n");

return 1;
}

csay(str) {
    say(HIB + "-= " + HIW + TPN + " says" + HIB + " =- "+ NORM + "\" " + str + ".\"\n");
    write("You say, \"" + str + ".\"\n");
    return 1;
}

cemote(str) {
    say( HIB+"-= " + HIW + TPN + " " + str + HIB + " =-" + NORM + "\n");
    write("You " + str + "\n");
    return 1;
}

/* TITLE FUNCTIONS */

title_me()  {
    TP->set_pretitle( "("+WHT+"+"+NORM+") "+HIB+"--{"+NORM+""+WHT );
    TP->set_title(HIB+ "}--"+NORM);
    TP->set_al_title(WHT+"+"+NORM);
    return 1;
}

title_me2()  {
    TP->set_pretitle("( "+HIG );
    TP->set_title(BLK);
    TP->set_al_title(NORM);
    return 1;
}
