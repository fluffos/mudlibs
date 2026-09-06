main(string who) {

  WIZ_CHECK

  object victim = first_inventory(environment(this_player()));
  while (victim) {
    victim->stop_combat();
    victim = next_inventory(victim);
  }
  this_player()->msg_local("~CBRT~Name ~verbraise ~poss hands and ~verbcall a time-out.~CDEF");
  return 1;
}
