// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** horse.c
**
** Example of a mount.
**
** 951220, Rust: Created.
*/

inherit VEHICLE;
inherit M_MOUNTABLE;

void setup()
{
    set_relations("on");
    set_adj("丑");
    set_id("horse", "马");
    set_unit("匹");
    set_long("Ｅｒｒｒ．．．这匹马太丑了!!!");
    set_preposition("on");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_primary_verb("sitting");
//    set_in_room_desc("这里有一匹丑马。");
    set_get_on_msg("$N翻身骑上了丑马。\n");
    set_get_off_msg("$N翻身从丑马上跳了下来。\n");

// We could opt for simple messages, and uncomment these
// 2 lines, but we can also go for more complex msgs (see below).
//    set_arrival_msg("$N一步三晃地走了过来。\n");
//    set_departure_msg("$N离开了。\n");
}


string get_arrival_msg()
{
  string riders;

  if(!(riders = get_riders_as_string()))
    return 0;

  return short() + "驮着" + riders +"离开了。\n";
}

string get_departure_msg()
{
  string riders;

  if(!(riders = get_riders_as_string()))
    return 0;

  return riders + "骑在" + a_short() + "过来了。\n";
}
