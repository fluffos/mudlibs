object *bridges;

int cmd_bridget()
{
  if(!bridges) bridges = ({ });
  if(member_array(this_player(), bridges) == -1)
    bridges += ({ this_player() });
  write("You put up a wall against incoming eye-jabs with the outside\n"+
        "of your hand.\n");
  write("Heh heh. That'll teach 'em!\n");
  say((string)this_player()->query_name()+" sticks "+possessive(this_player())+
  " hand up goofily in between "+possessive(this_player())+" eyes.\n"+
  "What the hell?\n");
  return 1;
}

query_bridge(ob)
{
  int i;
  if(!bridges) return 0;
  i = member_array(ob, bridges);
  if(i > -1)
  {
    bridges -= ({ bridges[i] });
    return 1;
  }
}
