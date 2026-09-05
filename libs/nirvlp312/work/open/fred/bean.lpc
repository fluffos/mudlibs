#define USER     this_player()
#define USERN    USER->query_name()

id(str) { return (str == "bean" || str == "sensu" || str == "sensu bean"); }

short() { return "A small sensu bean"; }

long() { 
  write("  A small sensu bean that can you can 'eat' to regain power.\n");
}

query_value(){ return 3000; }
query_save_flag(){ return 1; }
query_weight(){ return 1; }
get(){ return 1; }

reset(arg) 
{
  if(arg) return;
}

init() 
{
  add_action("use_heal","eat");
}


use_heal(str) 
{
  if(!id(str)) 
  { 
    notify_fail("Eat what?\n"); 
    return 0; 
  }
  if(!str) 
  { 
    notify_fail("Eat what?\n"); 
    return 0; 
  }
  if(environment(this_object()) != USER) return 0;

  if(!random(10)) /*  10% chance of failure  */
  {
    write("You swallow the bean whole but nothing happens.\n");
    say(USERN+" swallows a sensu bean whole.\n");
    USER->recalc_carry();
    destruct(this_object());
    return 1;
  }

  write("You swallow the bean whole and feel revitalized.\n");
  say(USERN+" swallows a sensu bean whole.\n");
  USER->heal_self(10000);
    
  command("mon", USER);
  this_object()->set_weight(0);
  USER->recalc_carry();
  destruct(this_object());
  return 1;
}

is_heal(){ return 1; }
query_charges(){ return 1; }
