inherit "/obj/armour";

void setup()
{
  set_base_armour("amuleto");
  set_name("amuleto de azufre");
  set_short("%^YELLOW%^Amuleto de Azufre%^RESET%^");
  set_long("%^YELLOW%^Amuleto de Azufre%^RESET%^");
  add_alias(({"amuleto","azufre"}));
  set_main_plural("%^YELLOW%^Amuletos de Azufre%^RESET%^");
  add_plural("amuletos");
  set_enchant(3);
}

void init()
{
  ::init();
  add_action("do_inclinarse","frotar");
}

int do_inclinarse(string que)
{
  if (this_player()->query_fd_shadow())
  {
    notify_fail("Una voz retumba en tu cabeza: Ya estas usando los poderes del Amuleto!\n");
    this_player()->adjust_hp(-(random(10)+5));
    return 0;
  }
  if (!que)
  {
    notify_fail("Frotar el que?\n");
    return 0;
  }
  if (que == "el amuleto")
  {
    write("Frotas el Amuleto. De repente, algo sucede...\n\n");
    clone_object("/w/xerxes/obj/shadows/glabrezu")->setup_shadow(TP);
    return 1;
  }
  else
  {
    notify_fail("Frotar el que?\n");
    return 0;
  }
}
