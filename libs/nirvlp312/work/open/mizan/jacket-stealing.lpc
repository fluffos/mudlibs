#define MAX_WEIGTH      43
inherit "obj/armor";

int svf_flag;
int local_weight;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  if(1 == random(2))  svf_flag = 1;
  local_weight = 0;
  set_name("Jacket of Mass Stealing");
  set_value(3005);
  set_ac(4);
  set_weight(2);
  set_type("armor");
  set_alias("jacket");
}

clean_up() {
  if(local_weight) {
    write("The items in the jacket clunk and clatter against one another.\n");
  }
  return 1;
}

long() {
    write("This jacket is so named for the multitude of big, baggy pockets\n"+
	"in it, but even when full, you would never suspect the wearer to\n"+
	"be carrying anything in them.\n");
    if (first_inventory(this_object()))
        write("There are things in the pockets.\n");
    else
        write("You can put things in it.\n");
}

query_save_flag() {
  if(svf_flag) return 1;
  else return 0;
}

add_weight(w) {
  if (local_weight + w > MAX_WEIGTH) return 0;
  local_weight += w;
  return 1;
}

short() {
  if(worn) {
    return "The Jacket of Mass Stealing (worn)";
  }
  return "The Jacket of Mass Stealing";
}


can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the jacket.\n");
    return 1;
  }
  return 0;
}

