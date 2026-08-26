/*  This is the plant object thingy.  This is the quite the easy part.   */

inherit OBJECT_OBJ;

string plant_name, plant_type, plant_desc;

void set_plant(string name) { plant_name = name; add_alias(name);  }
void set_plant_type(string type) { plant_type = type; }
void set_plant_desc(string desc) { plant_desc = desc; }

string get_plant_short() {
  if (plant_name && plant_type)
    return plant_type;
  return "plant";
}

string get_plant_long() {
  if (plant_desc)
    return plant_desc;
  return "A lovely plant thingy.\n";
}

void setup() {
  set_name("plant");
  set_short((: get_plant_short() :));
  set_long((: get_plant_long() :));
  add_property("plant",1);
}
