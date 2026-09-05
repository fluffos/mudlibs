/*
This is a simple example of an armor that has a 'special'
emote that occurs when it is hit.
-Feldegast
*/
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shield");
   set_alias("steel shield");
   set_short("A steel shield");
   set_long(
      "A round steel shield approximately a foot and a half in diameter.\n"
   );
   set_ac(1);
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(3);
   set_value(200);
}

/*
The important thing to remember with these functions is that
the argument 'owner' is the owner of the armor, and this_player()
if it is defined is THE PERSON HITTING THE PLAYER.  It is also
   possible that this_player() is the owner if that person is hitting
   themself.  Be sure to take this into account.
*/
do_special(owner)
{
   /* Each time a player is hit there are seven objects that have
   the oportunity to go off.  Do not make armor specials with
   a chance of going off greater than 1 in 10.  */
   if(!random(12))
      {
      tell_object(owner, "You manage to partially deflect the blow with your shield.\n");
      return 1; /* The value returned is added to the player's armor class.
      In most cases, this is 0-2.  If it is an extremely good
      armor with a disadvantage, then maybe 3. */
   }
}
