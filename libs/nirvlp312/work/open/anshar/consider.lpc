
con(str) {
  object target;
  int X;
  int Y;
  int Z;
  if(!str) {
    write("Consider what?\n");
    return 1;
    }
    target=present(str,environment(this_player()));
    if(!target) { 
      write("That is not here to consider.\n");
      return 1;
      }
    if(!target->is_npc()) {
      write("That is not something you can consider.\n");
      return 1;
      }
    X = (target->query_level());
    Y = (this_player()->query_level());
      if(Y>X) {
        write("You should have little problem with this opponent.\n");
        return 1;
        }
      if(Y==X) {
        write("This is a worthy adversary.\n");
        return 1;
        }
      if(Y<X) {
        Z = (X-Y);
        if(Z<4) {
          write("This could be quite a challenge.\n");
          return 1;
          }
        if(7>Z && Z>3) {
          write("This opponent would be very difficult.\n");
          return 1;
          }
        if(10>Z && Z>6) {
          write("This opponent would possibly be beyond your abilities.\n");
          return 1;
          }
        if(Z>9) {
          write("As Aerosmith might sing: Dream On.\n");
          return 1;
          }
        }
   return 1;
  }
