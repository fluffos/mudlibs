/**
 * Contains a list of locations the person remembers.
 * Added by the Remember spell. Name may change.
 * This effect does not have a shadow associated with it.
 */

#include <tasks.h>
#include <effect.h>

string query_classification() { return "magic.mentalism.remembered.locations"; }

int query_indefinite() { return 1; }

mixed beginning(object person, mixed args) {
  tell_object(person, "The location settles happily into your mind.\n");
  return args;
}

mixed restart(object person, mixed args, int id) {
  return args;
}

mixed merge_effect(object person, mixed old_arg, mixed new_arg) {
  int new_size;
  int i;
  if(!sizeof(old_arg) && !sizeof(new_arg)) {
    if(!sizeof(old_arg)) return new_arg;  //Housekeeping.
    else return old_arg;
  }
  new_size = sizeof(old_arg) + sizeof(new_arg);
  if((new_size - sizeof(old_arg)) > 2) {  //More housekeeping.
    tell_object(person, "Something has gone wrong with the spell you "
       "just cast.  Please bug report it.\n");
    return old_arg;
  }
  for(i = 0;i < sizeof(old_arg); i += 2) {
    if(old_arg[i] == new_arg[0]) {
      tell_object(person, "You already know this location!\n");
      return old_arg;
    }
  }
  if(TASKER->perform_task(person, "magic.spells.misc",
           45*(new_size - 1), TM_NONE, 0) == SUCCEED) {
    tell_object(person, "The new location settles happily into your mind.\n");
    return old_arg + new_arg;
  }
  else {
    tell_object(person, "You concentrate hard, but the location slips "
       "out of your grasp!\n");
    return old_arg;
  }
}

void end(object person, mixed args) {
  if(sizeof(args) > 2) {
    tell_object(person, "You forget all the locations you were remembering!\n");
  }
  else {
    tell_object(person, "You forget the location you were remembering!\n");
  }
}
