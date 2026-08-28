inherit ITEM;
create_item()
{
  set_name("seal");
  set_short("a farmer's seal of ownership");
  set_long("This is a small round magical disc made of stone.  "+
  "It has a picture of a large farm with a setting sun.  On the "+
  "reverse side it says, to claim a land type 'claim <crop type>'.\n");
  set_dimensions (10, 10, 2);
  set_material("stone");
  set_smell("It smells like nothing.\n");
  set_taste("It tastes like cold stone.\n");
}
init()
{
  add_action("do_claim","claim");
}
do_claim(what)
{
  if(!(environment(THIS)->query_farm()))
  {
    write("You can only claim designated farm lands.\n");
    return 1;
  }
  else
  {
    if(environment(THIS)->do_buy(THIS->query_cap_name(),what)){
      write(wrap("You throw your coin up into the air and it lands standing "+
     "on end.  You feel the ground grow into your mind and you glow "+
     "for a bit.  You feel at peace with the earth.\n"));
    message("0",wrap(THIS->query_cap_name()+" takes a magic coin out of "+
    "his pocket and throws it into the air.  It lands upon the ground "+
    "standing on end.  Suddenly the ground begins to shake and the coin is "+
    "sucked below the dirt.  "+THIS->query_cap_name()+" begins to glow "+
    "a bit and gets a large grin.\n"),ENV(THIS),THIS);
    destruct(THOB);
    return 1;
    }
    else return 1;
  }
}

query_value ()
{
  return 500;
}
