inherit "/obj/food";
string der_long();
void setup(){
  set_name( "elixir" );
  add_adjective(({"octarine", "strangely", "clear"}));
  set_long((:der_long():));
  set_medium_alias("BasilFennelSpiderTea");
  add_adjective("some");
  add_property( "determinate", "some ");
  set_amount_types( ([ "drop": ({ 1, "drops" }),
          "teaspoon": ({ 20, "teaspoons" }),
          "tablespoon": ({ 60, "tablespoons" }),
          "ounce": ({ 120, "ounces" }),
          "cup": ({ 960, "cups" }),
          "pint": ({ 2400, "pints" }),
          "quart": ({ 4800, "quarts" }),
          "gallon": ({ 19200, "gallons" }) ]));
  add_adjective( ({ "drop", "drops", "teaspoon", "teaspoons", "tablespoon",
                 "tablespoons", "ounce", "ounces", "cup", "cups", "pint",
                 "pints", "quart", "quarts", "gallon", "gallons", "of" }));
  set_pile_types( ({ 50, "small", 100, "medium", "large" }));
  set_continuous();
  set_liquid();
}
string short(int dark){
  if(this_player() && this_player()->query_see_octarine())
     return "octarine elixir";
  return "strangely clear elixir";
}
string der_long(){
  if(this_player() && this_player()->query_see_octarine())
     return "This is an octarine elixir.\n";
  return "This is a strangely clear elixir.\n";
}
