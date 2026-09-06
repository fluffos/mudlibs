inherit "/econ/plants/tree";
#include <const.h>

TASTE( "It tastes like lemons -- must be a glitch in the Matrix." )

string query_name() {
   return "pine";
}

int query_wood() {
   return 10;
}

string query_fruit_type() {
   return "/econ/seed/pinecone";
}

string query_specific() {
   return "the pine tree";
}

string query_distant() {
   return "a pine tree";
}

string query_plural() {
   return "pine trees";
}

string *query_alt_name() {
   return ({ "tree", "pine tree" });
}

string *query_alt_plural() {
   return ({ "trees", "pines" });
}

string query_look() {
   switch( query_size() ) {
      case 0..2: return "This pine tree is just a small sprout of green sticking out of the ground. The finger-width trunk is $(TREEHP).";
      case 3..10: return "A young pine sapling. It's still under six feet. The trunk is $(TREEHP).";
      case 11..25: return "A new-growth pine tree. It's got a firm, sturdy trunk, and light green needles. The trunk is $(TREEHP).";
      case 26..50: return "A large, mature pine tree. The trunk is covered in flaky bark, and the ground all around it is covered in a thick mat of dead needles. The trunk is $(TREEHP).";
      default: return "An ancient, old-growth pine tree, with a tall, firm trunk and an imposing mix of living and dead branches which soar into the sky above. The trunk is $(TREEHP).";
   }
   return ""; // fix spammy warning
}

void on_map_paint( object painter ) {
   switch( query_size() ) {
      case 0..2:
      painter->paint( query_x(), query_y(), '^', 0x8A, LAYER_ITEMS );
      break;
      case 3..10:
      painter->paint_shape( query_x()-1, query_y()-2, "\t/\n//\\", 0x2A, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      case 11..30:
      painter->paint_shape( query_x()-1, query_y()-3, "\t/\n//\\\n//\\", 0x2A, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
      default:
      painter->paint_shape( query_x()-2, query_y()-4, "\t\t/\n\t//\\\n\t//\\\n///\\\\", 0x2A, LAYER_OVERLAY );
      painter->paint( query_x(), query_y(), '#', 0x38, LAYER_LIVING );
      break;
   }
}
