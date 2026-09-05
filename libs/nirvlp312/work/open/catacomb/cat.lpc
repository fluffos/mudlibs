inherit "/obj/monster";

int called;

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_short("test");
    set_name("test");
    set_long("hmm\n");
    set_level(1);
    set_dead_ob(this_object());
    set_hp(500);
}

heart_beat()
{
    ::heart_beat(); /* call the inherited heart beat in monster.c */
    /* check to make sure it has an environment, else the stuff will fail */
    if(!environment()) return;
    /* if it hasn't 'changed' already and the hit points are below 2/10 */
    if(!called && (hit_point <= ((max_hp / 10) * 2)))
    {
      /* first tell the room it regenerated */
      tell_room(environment(), "The monster regenerates itself.\n");
      hit_point = max_hp; /* set the hit point back to max */
      weapon_class += 10; /* increase the wc */
      called = 1; /* mark it so it's already been done.. won't do it again */
    }
}

status
monster_died()
{
    int i, s;
    object *inv;

    if(!environment()) return 0;  /* if no room, forget about it */
    
    /* this is kinda advanced.. take all the objects in the room
       and dump em in an array 'inv' */
    inv = all_inventory(environment());

    /* set s equal to the size of the array 'inv' */
    s = sizeof(inv);

    /* tell the room it's dead */
    tell_room(environment(), "\
The monster rains fire down upon the room before it dies.\n");

    for(i = 0; i < s; i ++) /* for each item in the inventory, */
      if(living(inv[i])) /*  if the item is living */
        inv[i]->hit_player(50); /* hit em with 50 damage */

    return 0;  /* if you returned 1 here, the monster wouldn't die */
}
