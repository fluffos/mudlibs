inherit "obj/soft_drink";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("fishsoup");
    set_alias("soup");
    set_short("A bottle of fishsoup");
    set_long("The druid Lakmir loves such a delicious fishsoup.\n");
    set_value(500);
    set_strength(20);
    set_drinking_mess(" drinks some fishsoup.\n");
    set_drinker_mess("You feel much stronger.\n");
    set_empty_container("bottle");
  }
}

id_quest(arg) {
  return arg == "fishsoup";
}
