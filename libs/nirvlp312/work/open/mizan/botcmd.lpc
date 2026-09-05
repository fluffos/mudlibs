init() {
add_action("mon","mon");
}

mon()
{
  object ob;
  ob = present("tiamat", environment(this_player()));

if(ob)
{
  this_player()->attack_object(ob);
}
}

get() { return 1; }
