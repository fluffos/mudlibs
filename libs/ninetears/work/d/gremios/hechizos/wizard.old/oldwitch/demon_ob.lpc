 
inherit "obj/monster";
string demon;
 
void setup()
{
    switch(random(11))
    {
      case 0: demon = "small hordling"; break;
      case 1: demon = "minor poltergeist"; break;
      case 2: demon = "young nightmare"; break;
      case 3: demon = "red slaad"; break;
      case 4: demon = "dretch"; break;
      case 5: demon = "manes"; break;
 
      case 6: demon = "rutterkin"; break;
      case 7: demon = "alu-fiend"; break;
      case 8: demon = "cambion"; break;
      case 9: demon = "succubus"; break;
      case 10: demon = "bar-lgura"; break;
          }
    set_main_plural(demon+"s");
add_alias("demon");
set_name(demon);
add_alias(demon);
 set_al(-100);
    set_short(demon);
    set_long("This is a horrid "+demon+".\n");
    set_race(demon);
   set_level(random(3)+3);
    call_out("destruct", 300);
}
 
void destruct()
{
 tell_object(environment(),
  "The "+demon+" gets restless and returns"
" to the plane of existance it was summoned from.\n");
 dest_me();
}   
