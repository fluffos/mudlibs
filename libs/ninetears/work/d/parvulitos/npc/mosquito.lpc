// Valdor '99

inherit "obj/monster";

void setup()
{
  set_name("mosquito");
  add_alias("insecto");
  set_short("%^BOLD%^Mosquito%^RESET%^");
  set_long("Es un mosquito despreciable y desaprensivo que no para de dar la murga"
		".\n");
  set_random_stats(10,15);
  set_cha(30);
  set_dex(25);
  set_level(random(2)+1);
  set_ac(-100);
  set_main_plural("%^RED%^BOLD%^Mosquitos%^RESET%^");
  add_plural("mosquitos");
  add_plural("insectos");
  set_align(0);
  set_gender(0);
  load_chat(100,
           ({
             1,":rebolotea alrededor tuyo.\n",
             2,"'Bzzzzzzzz, bzzzzzzzzzzz bz bzzzzzzzzz\n",
             1,":tropieza con tu oreja y casi se mete dentro de ella, causandote gran confusion y sorpresa.\n",
             1,":te pica.\n",
           }));
  
}

