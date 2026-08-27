// Traducida por Gareth 21.01.03

inherit "/std/item";
#define BRIGHTNESS 50 

int amount_of_fuel;
int is_lighted;
 
void setup() {
  amount_of_fuel = 2000; 
  set_name("antorcha"); 
  set_main_plural("antorchas");
  set_short("Antorcha");
  set_long("Una pequenya antorcha.\n");
  is_lighted = 0;
  set_weight(50);
  set_value(50);
  set_size(1);
}

int query_holdable() {return 1;}
int query_hands_needed() { return 1; }

string short(int i) 
  {
  if (is_lighted)
      return ::short(0) + " (lit)";
  return ::short(0);
  }
 
string pretty_plural() {
  if (is_lighted)
    return ::pretty_plural() + " (lit)";
  return ::pretty_plural();
}

void set_fuel(int f) { amount_of_fuel = f; }
 
void init() {
  /* Wow.. haven't seen this method before... */
  /* Will try add_action 
  this_player()->add_command("light", this_object());
  this_player()->add_command("extinguish", this_object());
  */
  add_action("do_light", "encender");
  add_action("do_extinguish", "apagar");

}
 
//Taniwha, 1997, for cute stuff
void lightme()
{
   is_lighted = 1;
   set_light(BRIGHTNESS);
   if(ETO)
   {
      tell_room(ETO,"%^YELLOW%^Una antorcha parpadea hasta encenderse.\n",({ 0 }));
   }
}
void unlightme()
{
   is_lighted = 0;
   set_light(0);
   if(ETO)
   {
      tell_room(ETO,"La luz de una antorcha parpadea y se apaga.\n");
   }
}

/* This function will only be called as a result of the add_command(), that
is, it will only be called by the living object that has this torch in 
inventory.  If we want for any other object to be able to cause the torch
to light, I have to write another function. */

int do_light(object *indir, int s1, int s2, mixed *prep) {
  string mess;
  if (!query_in_use())
    mess = "debes sostener la antorcha primero (uso: empunyar antorcha)";
  else if (is_lighted)
    mess = "esta encendida";
  else if (amount_of_fuel <= 0)
    mess = "esta sin combustible";
  if (mess) 
    {
    tell_room(environment(),environment()->query_cap_name()+" intenta encender"+
      " una antorcha, pero "+mess+"!\n",environment());
    tell_object(environment(), "Intentas encender la antorcha, pero "+mess+"!\n");
    return 0;
    }
  is_lighted = 1;
  call_out("out_of_fuel", amount_of_fuel * 2);
  amount_of_fuel = 0;
  set_light(BRIGHTNESS);
  return 1;
}
 
void out_of_fuel() 
  {
  is_lighted = 0;
  set_light(0);
  tell_room(environment(),"La " + short(0) + " se apaga.\n",environment());
  tell_object(environment(), "La " + short(0) + " se apaga.\n");
}

int set_in_use(int i,object amo)
  {
  if (i==0 && is_lighted)
    out_of_fuel();      /* it's not really out of fuel */
       return ::set_in_use(i,amo);
}

int do_extinguish(object *indir, string s1, string s2, string prep) {
  int i;
  if (!is_lighted) {
    tell_room(environment(),environment()->query_cap_name()+" intenta "+
      "apagar la antorcha, pero no esta iluminada!\n",environment());
    tell_object(environment(), "Intentas apagar la antorcha, pero"+
      " no esta encendida!\n");
    return 0;
  }
  i = remove_call_out("out_of_fuel");
  amount_of_fuel = i/2;
  is_lighted = 0;
  set_light(0);
  return 1;
} 
int query_lit()
{
   return is_lighted;
}

void dest_me()
{
  set_light(0);
  ::dest_me();
}
