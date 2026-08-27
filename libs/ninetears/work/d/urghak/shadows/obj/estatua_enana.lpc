inherit "/std/object";

void setup()
{
  set_name("estatua");
  set_short("%^ORANGE%^Estatua de cobre%^RESET%^");
  add_alias(({"estatua","cobre"}));
  set_main_plural("%^ORANGE%^Estatuas de cobre%^RESET%^");
  add_plural(({"estatuas","cobres"}));
  set_long("Una estatua de tres metros de altura, que representa una mujer "
  "con los brazos extendidos mirando hacia el cielo. Deduces que se trata de "
  "una elfa por sus finos rasgos estilizados.\n");
  reset_get();
}

void init()
{
  ::init();
  add_action("do_inclinarse","inclinarse");
}

int do_inclinarse(string que)
{
  if (this_player()->query_volar_shadow())
  {
    notify_fail("Una voz retumba en tu cabeza: Ya estas usando los poderes de la Estatua!\n");
    this_player()->adjust_hp(-(random(10)+5));
    return 0;
  }
  if (!que)
  {
    notify_fail("Inclinarse ante que?\n");
    return 0;
  }
  if (que == "ante la estatua")
  {
    write("Te inclinas ante la estatua. De repente, el tiempo parece detenerse...\n");
    clone_object("/d/urghak/shadows/volar")->setup_shadow(TP);
    return 1;
  }
  else
  {
    notify_fail("Inclinarse ante que?\n");
    return 0;
  }
}
