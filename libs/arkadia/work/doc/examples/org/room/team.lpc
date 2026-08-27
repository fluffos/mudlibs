/* An example room to show how you can let your monsters team up.
 *
 * Made by Nick, 920819
 */

inherit "/std/room";

create_room()
{
    object ob1, ob2;

    set_long("The long desc of the team example room.\n");
    set_short("room");

    add_exit("/d/Krynn/workroom", "work");

    ob1 = clone_object("/doc/examples/mobiles/troll");
    ob1->move_living("xxx", this_object());

    ob2 = clone_object("/doc/examples/mobiles/walk_monster");
    ob2->move_living("xxx", this_object());
    ob2->team_join(ob1); /* ob2 will be the leader of ob1 */


    /* Since both monster inherit /d/Krynn/open/monster instead of
     * /std/monster the teammates will attack you (90 % chance) if 
     * you attack a team member. Note that they try to perform the noraml
     * kill command so if their dis is low perhaps they cannot attack you.
     *
     * Feel freee to eighter inherit our monster file in Krynn or
     * just scan it and see how things like this can be solved.
     */
}

