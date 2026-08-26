// Example room for the npc school
// October '01 by Avelan

#include "defs.h"
inherit OUTSIDE_OBJ;

object thing;
int x;
int anim;

void setup(){

    set_zone("npc_school");
    set_light(80);
    set_short("example room");
    set_determinate("the ");
    set_day_long("An example room with a search function which"
      " will clone an npc if it has not yet been discovered.\n"
      "There's some bushes in one corner which you could search.\n");

    set_night_long("An example room with a search function which"
      " will clone an npc if it has not yet been discovered.\n"
      "There's some bushes in one corner which you could search.\n");

    /**
    * add_items here when doing a real room.
    */

    add_exit("forward",NPCSCHOOL+"npc_school04","path");
    add_exit("back", NPCSCHOOL+"npc_school02","path");

} /* setup() */

void reset(){
    anim = 1;
} /* reset() */

int do_search(string str){
    if(str == "bushes"){
        call_out("search2", 3);
        return 1;
    }
    /*
    * Ok, the player tried searching from some other place
    * than the bushes.  We return -1 so the player
    * will be given a standard failed search message.
    */
    return -1;
} /* do_search() */

int search2(){
    /*
    * Ok, let's check if someone has already found an animal
    * during this reset().  If the variable anim is bigger than 0
    * no-one has found the animal yet and so we clone one and also
    * make sure they won't find any more by making the value of
    * anim 0.
    */

    if(anim > 0){
        anim = 0;
        tell_object(TP,"You roam around the bushes and stumble upon a "
          "wild animal!\n");
        tell_room(ENV(TP),TP->one_short()+" goes poking around the "
          "bushes but quickly returns.",TP);

        thing = clone_object(NPC_OBJ);

        /*
        * ok, assign a value to x, it is something from 0 to 5.
        * now, let's use the function 'switch' to determine what to do
        * with it. as you can see, if the value of x is 0, we shall make
        * the cloned npc a cat, give it the values we want and move the damn
        * thing to this object.  Same with every number, only different
        * attributes for the npc itself.
        */
        x = (random(5));
        switch(x){

        case 0:thing->set_name("cat");
            thing->set_short("stray cat");
            thing->set_determinate("a ");
            thing->set_long("This poor thing obviously doesn't have a "
              "home to go to.  It is skinny as hell and its fur has seen "
              "better days.  Perhaps it would be better to put it out of "
              "its misery.\n");
            thing->basic_setup("cat", 5, 0);
            thing->set_aggressive(1);
            thing->move(TO);
            /*
            * Remember to type in this line.  It will make the function stop here.
            * if you don't make it break here, it would also do everything after the
            * point it first matched the x to a number.
            */
            break;
        case 1:thing->set_name("rat");
            thing->set_short("crazed rat");
            thing->set_determinate("a ");
            thing->set_long("This thing is ugly as hell with its skinny "
              "tail and ragged fur.  Who knows what diseases it carries "
              "so better to stay away from it.\n");
            thing->basic_setup("rat", 5, 0);
            thing->set_aggressive(1);
            thing->move(TO);
            break;
        case 2:thing->set_name("fox");
            thing->set_short("sneaky fox");
            thing->set_determinate("a ");
            thing->set_long("This fox sure looks intelligent.  The way he "
              "looks at you makes cold shivers run down you spine.\n");
            thing->basic_setup("fox", 5, "male");
            thing->move(TO);
            break;
        case 3:thing->set_name("frog");
            thing->set_short("huge frog");
            thing->set_determinate("a ");
            thing->set_long("This frog is amazingly big and ugly and its "
              "skin is repulsive, almost enough to make one puke.\n");
            thing->basic_setup("frog", 5, 0);
            thing->set_aggressive(1);
            thing->move(TO);
            break;
        case 4:thing->set_name("bat");
            thing->set_short("vicious bat");
            thing->set_determinate("a ");
            thing->set_long("This vicious creature only wants one thing, "
              "to drink blood.  It has sharp fangs and seems none too eager "
              "to sink them in someone's neck.  Watch out!\n");
            thing->basic_setup("bat", 5, 0);
            thing->set_gender("male");
            thing->set_aggressive(1);
            thing->move(TO);
            break;
        case 5:thing->set_name("hare");
            thing->set_short("scared hare");
            thing->set_determinate("a ");
            thing->set_long("This little hare is so scared you can almost see "
              "his whiskers shiver.  He looks up at you and you almost "
              "start to laugh at the poor thing.  Perhaps it would be better "
              "to leave it be.\n");
            thing->basic_setup("hare", 5, 0);
            thing->move(TO);
            break;
        default:tell_object(TP,"You don't find anything.\n");
            break;
        }
    }
    /*
    * So, the variable anim was 0 so we don't clone anything and
    * tell the player he doesn't find anything.
    */
    else {
        tell_object(TP,"You search around for a while, but don't find anything.\n");
    }
}
