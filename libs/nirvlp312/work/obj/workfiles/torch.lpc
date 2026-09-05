string amount_of_fuel;
string name;
string out_desc;
string long_lit_desc;
string long_unlit_desc;
string short_desc;
status is_lit;
int weight;

long() {
    if (is_lit) write(long_lit_desc);
    else write(long_unlit_desc);
}

reset(arg) {
    if (arg)
  return;
    amount_of_fuel = 0; name = 0; is_lit = 0; weight = 0;
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

short() {
 if(!short_desc) short_desc = name;
 if(!short_desc) short_desc = "torch";
    if (is_lit)
  return short_desc + " (lit)";
    if (amount_of_fuel == 0)
  return short_desc + " (burnt out)";
    return short_desc;
}

set_name(n) {
    name = n; 
    long_lit_desc = "A " + name + " (lit)\n";
    long_unlit_desc = "A " + name + "\n";
}
set_fuel(f) { amount_of_fuel = f; }

init() {
    add_action("light", "light");
    add_action("extinguish", "extinguish");
}

light(str) {
    if (!str || str != name)
  return 0;
    if (amount_of_fuel == 0) {
  write("End of fuel.\n");
  return 1;
    }
    if (is_lit) {
  write("It is already lit.\n");
  return 1;
    }
    is_lit = 1;
    write("Ok.\n");
    set_light(1);
    set_heart_beat(1);
    return 1;
}

extinguish(str) {
    if (!str || str != name)
  return 0;
    if(!is_lit) {
  write("It is not lit!\n");
  return 1;
    }
    is_lit = 0;
    write("Ok.\n");
    set_light(-1);
    set_heart_beat(0);
    return 1;
}

heart_beat() {
    object ob;
    if (!is_lit)
  return;
    amount_of_fuel -= 1;
    if (amount_of_fuel > 0)
  return;
    if(!out_desc)
    say(short_desc + " goes dark.\n");
    else  say(out_desc);
    set_heart_beat(0);
    is_lit = 0;
    set_light(-1);
    ob = environment();
    if (call_other(ob, "query_level"))
  call_other(ob, "add_weight", -weight);
    destruct(this_object());
}

id(str) {
    return str == name;
}

query_value() {
    return amount_of_fuel/100 + 1;
}

get() { return 1; }

set_long_lit(str) { long_lit_desc = str; }
set_long_unlit(str) { long_unlit_desc = str; }
set_short(str){short_desc=str;}
set_out_desc(str){out_desc=str;}
