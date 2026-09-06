inherit "/std/thing";

create() {
  ::create();
  SetShort("a sunray");
  SetLong(
"This is a strange magic object. It's only partially material. "
"You can use it to 'disrupt' disturbing rain clouds.\n");
  SetValue(20);
  SetWeight(100);
  SetIds(({"sun","ray","sunray","sun ray"}));
}

init() {
  add_action("disrupt","disrupt");
}

int disrupt(string str) {
  object ob;
  if ((str!="cloud") && (str!="rain cloud")) return (int) notify_fail(
    "You cannot disrupt this.\n") && 0;
  if (!ob=(present("rain cloud",this_player()))) return (int) notify_fail(
    "You cannot disrupt something you don't have!\n") && 0;
  write("You aim at it...\n\A ray of light hits the cloud. It dissolves.\n");
  say(this_player()->QueryName()+" aims at the rain cloud with a "
"strange object. The rain cloud dissolves.\n");
  ob->remove();
  if (ob) destruct(ob);
}
