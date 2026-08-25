// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// This object can function in a remarkably similar way to /domains/std/horse
// Save for the fact that you can't mount or dismount a bed, and beds don't
// normally move =)

inherit FURNITURE;

void setup()
{
  set_id("bed", "床");
  set_unit("张");
  set_in_room_desc("房间的一角有一张床。");
  set_get_on_msg("$N在床上坐下。\n");
  set_get_off_msg("$N从床上站起来。\n");
  set_long("这是一张床。");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*3, "on");
}

// Unlike most furniture, you can lie on a bed.  We'll assume you mean sit
// on the bed here, but you can do what you want...

int direct_lie_on_obj()
{
  return 1;
}

int lie()
{
  return sit();
}
