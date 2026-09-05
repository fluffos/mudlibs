/*
Originally written by Mizan for his beatfixer.
Modified by Feldegast for use in /bin
5-10-00
*/
/* illarion 31 may 05 - added explicit multiuser support */
object *users;

void reset(status arg) {
  if(!users) users=({});
}

int cmd_beatfix(string str) {
  /*
  if(find_call_out("do_fix") != -1) {
  */
  if(member_array(this_player(),users) != -1) {
    write("You are still gathering your strength to fix yourself.\n");
    return 1;
  }
  write("You slowly extend your arm from your body, gather up all your\n");
  write("strength, and....\n");
  users+=({this_player()});
  call_out("do_fix",5,this_player());
  return 1;
}

void do_fix(object me) {
  if(!me) return;
  users-=({me});
  if(me->query_ghost()) {
    tell_object(me, "You are DEAD! (No heart to fix)\n");
    return;
  }
  me->set_heart_beat(1);
  tell_object(me, "You smack yourself in the chest and your heart begins beating again.\n");
  return;
}
