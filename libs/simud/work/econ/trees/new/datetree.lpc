inherit "/econ/trees/fruittrees";

TASTE( "It tastes Caribbean." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "palm";
}

string query_wood_type() {
  return "/econ/raw/coconutwood";
}

string query_fruit_type() {
  return "/econ/seed/coconut";
}

string query_look() {
   switch( query_size() ) {
      case 0..10: return "This palm tree is just a small green sprout sticking out of the ground. The trunk is $(TREEHP).";
      case 11..30: return "A new-growth palm tree.  It has a firm sturdy trunk, and light green palms. Its trunk is $(TREEHP).";
      case 31..60: return "A fully grown palm tree, with a trunk that's $(TREEHP). Its palm leaves are a rich green hue.";
      default: return "An aged palm tree with an dark brown trunk, which is $(TREEHP).";
   }
   return ""; // for spammy warning
}

void on_map_paint( object painter ) {
   switch( query_size() ) {
      case 0..10:
         painter->paint( query_x(), query_y(), '^', 0x8A, LAYER_LIVING );
      break;
      case 11..30:
         painter->paint_shape( query_x()-2, query_y()-2, "d^v^b\n\"\t\t\t\"", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-1, "#\n#", 0x38, LAYER_LIVING );
         break;
/*
         painter->paint_shape( query_x()-2, query_y()-2, ".;.;.", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-2, query_y()-1, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-1, "&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()+2, query_y()-1, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y(), "&", 0x38, LAYER_LIVING );
         break;
*/
      default:
         painter->paint_shape( query_x()-3, query_y()-4, "\td^v^b\nd^\"\t\"^b\n\"\t\t\t\t\t\"", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-3, "#\n#\n#\n#", 0x38, LAYER_OVERLAY );
         break;

/*
         painter->paint_shape( query_x()-2, query_y()-4, ".;.;.", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-3, query_y()-3, ".'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-3, "&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()+2, query_y()-3, "'.", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-3, query_y()-2, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-2, "&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()+3, query_y()-2, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-1, query_y()-1, ".&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()-1, query_y(), "&'", 0x38, LAYER_LIVING );
         break;
      default:
         painter->paint_shape( query_x()-2, query_y()-4, ".;.;.", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-3, query_y()-3, ".'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-3, "&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()+2, query_y()-3, "'.", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-3, query_y()-2, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x(), query_y()-2, "&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()+3, query_y()-2, "'", 0x2A, LAYER_OVERLAY );
         painter->paint_shape( query_x()-1, query_y()-1, ".&", 0x38, LAYER_LIVING );
         painter->paint_shape( query_x()-1, query_y(), "&'", 0x38, LAYER_LIVING );
         break;
*/
   }
}
