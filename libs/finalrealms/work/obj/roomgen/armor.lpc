inherit "obj/roomgen/support";

string *room_armors;
 
void init_armor_data() {
  room_armors = ({ });
}
 
void armor_menu() {
  write("   1. add armor to the room\n");
  write("   2. list armors for the room\n");
  write("   3. edit armor for the room\n");
  write("   4. delete armor for the room\n");
  write("   help - help on armors\n");
  write("Selection :");
  input_to("handle_armor_menu");
}
 
void handle_armor_menu(string str) {
}
 
string armor_vars() {
  if(sizeof(room_armors)) {
    return "object *armors";
  }
  else {
    return "";
  }
}
 
string dump_armors() {
  return "";
}
 
int num_armors() {
  return sizeof(room_armors);
}

void parse_armor(string str) {
}

void review_armor() {
}
