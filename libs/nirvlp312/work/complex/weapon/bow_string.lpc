inherit "complex/item";

status
drop()
{
  if (environment() && environment()->query_bow_string() == this_object())
    return 1;
}

void
configure()
{
  item::configure();
  set_name("bow string");
  set_id(({"string", "bow string"}));
  set_short("bow string");
  set_long("A bow string.\n");
}
