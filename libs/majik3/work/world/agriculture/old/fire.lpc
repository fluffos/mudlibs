inherit ITEM;
create_item()
{
  set_name(({"fire","a small fire","small fire"}));
  set_short("a small fire");
  set_long("This is a normal hot burning campfire.\n");
  set_light(4);
  set_taste("You burn your tongue as you taste the fire.\n");
  set_no_get(1);
  set_smell("It smells like burning wood.\n");
  call_out("do_done",120);
}
do_done()
{
  message("0","The fire flickers suddenly then goes out.\n",
  environment(this_object()));
  destruct(THOB);
  return;
}
