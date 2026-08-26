
inherit COMMAND_BASE;

mixed cmd(string str) {
  int i;
  mixed * facing;

  if ( !( i = ([ "half right": 1, "right": 2, "rt": 2, "around": 4, "left": 6,
      "lt": 6, "half left": 7 ])[ str ] ) ) {
    return 0;
  }
  facing = TP->query_facing();
  
  facing[ 0 ] = ( i + facing[ 0 ] ) % 8;
  write( "You reorient yourself with the world.\n" );
  say( TP->one_short() +" reorients "+ TP->query_objective() +"self.\n" );
  TP->set_facing(facing);
  if ( environment(TP) )
    environment(TP)->init();
  return 1;
}


mixed *query_patterns()  {
    return ({ "<string'around, [half] right, [half] left, rt, lt'>",
              (: cmd($4[0]) :) });
}
