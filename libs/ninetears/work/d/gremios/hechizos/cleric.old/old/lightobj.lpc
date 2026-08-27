inherit "std/object";
#define BRIGHTNESS 50

void setup()
{
  set_name("light");
  set_main_plural("");
  set_short("");
  set_long("You can't exacly SEE the light.\n");
  set_light(BRIGHTNESS);
  set_weight(0);
  set_value(0);
  reset_drop();
}

void dest_me()
{
  set_light(0);
  ::dest_me();
}
