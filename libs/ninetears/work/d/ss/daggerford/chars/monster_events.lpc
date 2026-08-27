
void regen_after_death() {
  object ob, dest;
  string nam;

  nam = (string)previous_object()->query_property("monster_type");
  dest = (object)previous_object()->query_property("start location");
  if (!dest)
    return ;
  ob = clone_object(nam);
  dest->add_monster(previous_object(), ob);
  call_out("do_move", 10, ({ ob, dest }) );
}

void do_move(mixed *junk) 
{
 if(junk[0]) 
  junk[0]->move(junk[1]);
}

void death() {
  call_out("do_pick_up", 0, previous_object());
}

void do_pick_up(object ob) {
  ob->do_command("'Thank you for the nice booty!\n");
  ob->do_command("get all from corpses");
  ob->run_away();
}
