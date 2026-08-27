#define MONSTER "/obj/monster"
#define ARMORY "/obj/handlers/armoury"

inherit "/std/room";
void setup();

void pub_brawl(object ob, mixed where, object me) {
  mixed *arr;
  int i;

  arr = (mixed *)previous_object()->query_current_room()->query_dest_dir();
  if (!arr)
    return ;
  if ((i = member_array(where, arr)) == -1) {
    if (!objectp(where))
      where = find_object(where);
    else
      where = file_name(where);
    if ((i = member_array(where, arr)) == -1)
      return ; /* we cant get there (sniff) */
  }
  previous_object()->init_command(arr[i-1]);
}

void regen_after_death() {
  object ob, dest;
  string nam;

  nam = (string)previous_object()->query_property("monster_type");
  dest = (object)previous_object()->query_property("start location");
  if (!dest)
    return ;
   // Radix was .. this looked horrid .. not sure what to put
   // to get driver back up online
//ob = setup();
   ob = this_object();
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
