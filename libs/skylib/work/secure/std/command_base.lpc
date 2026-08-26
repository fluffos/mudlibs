/**
 * This is basic inherit module for inheriting into commands.
 * Please inherit this into all command objects.
 * <p>
 * It sets up all the functions needed to do useful stuff with a 
 * command object.
 * @author Pinkfish
 */

void create() {
    seteuid(getuid(this_object()));
} /* create() */

/** @ignore yes */
nomask void dwep() {
  object my_ob = TO;

  if (my_ob)
    destruct(my_ob);
} /* dwep() */

/** @ignore yes */
void dest_me() {
    dwep();
} /* dest_me() */

/** @ignore yes */
int clean_up() {
    dest_me();
    return 1;
} /* clean_up() */

/** @ignore yes */
void reset() {
    dest_me();
} /* reset() */
