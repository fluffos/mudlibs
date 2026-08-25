// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;

void setup()
{
  set_adj("沙砌的");
  set_unit("座");
  set_id("castle", "城堡", "sculpture");
  set_in_room_desc("你面前有一个由沙砌成的城堡。");
  set_long("这座沙堡准是一位艺术天才的杰作，上面的塔楼和围墙都雕得十分精细，"
           "如过你不是在沙地里，你将不会认为它是沙子砌成的。你用手指戳了戳，"
           "并没有戳动它，真的就象石砌的一样！");
  set_size(TOO_LARGE);
}

void do_enter()
{
  write("你不太可能进去，因为它并没有门。\n");
}


mixed direct_enter_obj()
{
  return 1;
}

void dig(object o)
{
  this_body()->simple_action("$N想挖这座城堡，却发现它和岩石一样坚硬。");
}
