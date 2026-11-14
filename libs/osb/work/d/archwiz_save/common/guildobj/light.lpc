/* a light sphere casted by adventurers to lit a special room for a short
   amount of time */
/* Cadra@Nightfall 13-06-94 */

inherit "/std/thing";

create() {
  if (!is_clone(this_object())) return;
  ::create();
  SetShort(0);
  SetBright(20);
  SetWeight(0);
  SetNoGet(1);
  call_out("remove",30);
}

