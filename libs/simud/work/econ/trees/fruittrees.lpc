inherit "/econ/plants/tree";
#include <const.h>

TASTE( "It tastes like idling." )

string query_name()
{
  /* Should override in instances */
  return "";
}

string query_wood_type() {
  return "/econ/raw/wood/"+query_name()+"wood";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}

string query_specific() {
   return "the "+query_name()+" tree";
}

string query_distant() {
  if (member((['a','e','i','o','u','h','A','E','I','O','U','H']), query_name()[0]))
  {
    return "an "+query_name()+" tree";
  } else {
    return "a "+query_name()+" tree";
  }
}

string query_plural() {
   return query_name()+" trees";
}

string *query_alt_name() {
   return ({ "tree", query_name()+" tree" });
}

string *query_alt_plural() {
   return ({ "trees", query_name()+"s" });
}

string query_look() {
   switch( query_size() ) {
      case 0..2: return "This "+query_name()+" tree is just a small sprout of green sticking out of the ground. The little trunk is $(TREEHP).";
      case 3..10: return "A young "+query_name()+" sapling. It's still under six feet. The small trunk is $(TREEHP).";
      case 11..30: return "A new-growth "+query_name()+" tree. It's got light green leaves, and a firm, sturdy trunk, which is $(TREEHP).";
      case 31..60: return "A large, mature "+query_name()+" tree. The trunk is covered in flaky bark, and is $(TREEHP).";
      default: return "An ancient, old-growth "+query_name()+" tree, with a tall, firm trunk and an imposing mix of living and dead branches which soar into the sky above. The robust trunk is $(TREEHP).";
   }
   return "";
}

string myfruitlook()
{
   return query_fruit_type()->query_treed_fruit_look();
}

int myfruitcolor()
{
  return query_fruit_type()->query_treed_fruit_color();
}

void on_map_paint( object painter ) {
// Sera's old look. Uncomment to get it back.
/*
   switch( query_size() ) {
      case 0..2:
      painter->paint( query_x(), query_y(), '^', 0x8A, LAYER_LIVING );
      break;
      case 3..10:
      painter->paint_shape(query_x()-1, query_y()-3, "\t*\n*\t*\n\t*\t",
                           0x2A, LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      case 11..30:
      painter->paint_shape(query_x()-1, query_y()-4, "\t*\t\n\t**\n**\t\n",
                           0x2A, LAYER_OVERLAY);
      painter->paint(query_x()-1, query_y()-3, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x()+1, query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y()-1, '#', 0x38, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      default:
      painter->paint_shape(query_x()-2, query_y()-4,
                   "\t*\t*\t\n\t***\t\n\t*\t*\t\n", 0x2A, LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-4, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x()-2, query_y()-3, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x()+2, query_y()-3, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y()-1, '#', 0x38, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
   }
*/

   switch( query_size() ) {
      case 0..2:
      painter->paint( query_x(), query_y(), '^', 0x8A, LAYER_LIVING );
      break;
      case 3..10:
      painter->paint_shape(query_x()-1, query_y()-2, "\t_\n( )",
                           0x2A, LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-1, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      case 11..30:
      painter->paint_shape(query_x()-2, query_y()-3, "\t\t_\n\t( )\n( * )",
                           0x2A, LAYER_OVERLAY);
      painter->paint(query_x()-1, query_y()-1, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x()+1, query_y()-1, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      default:
      painter->paint_shape(query_x()-2, query_y()-4,
                   "\t.-.\n(* *)\n( * )", 0x2A, LAYER_OVERLAY);
      painter->paint(query_x()-1, query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x(), query_y()-3, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint(query_x()+1, query_y()-2, myfruitlook()[0],
                     myfruitcolor(), LAYER_OVERLAY);
      painter->paint( query_x(), query_y()-1, '#', 0x38, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
   }
}




