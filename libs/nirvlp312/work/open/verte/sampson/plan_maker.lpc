#include <ansi.h>

id(str){
  return (str=="plan_maker");
}

short(){
  return "A plan_maker";
}

/* Makes the item undroppable */
drop(){
  return 1;
}

/* Makes the item 'gettable' so you can clone it. */
get(){
  return 1;
}

init(){
  add_action("create_plan", "plan");
}

create_plan(){
  string text;
  write("You create your PLAN.\n");

  rm("/open/pub_plans/sampson.plan");
  rm("/players/sampson/PLAN");

  text = "\
To kick some "+HIR+"ASS"+NORM+"!\n";
  write_file("/open/pub_plans/sampson.plan", text);
  write_file("/players/sampson/PLAN", text);
  return 1;
}
