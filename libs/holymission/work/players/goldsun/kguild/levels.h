
int show_levels()
{
  int lvl;
  int to;
  int lg;
  string capname;

  lvl = to = this_player()->query_level();
  if (lvl > 30)
  {
     write("You are already an Immortal, search other ways to advance.\n");
     return 1;
  }
  capname = capitalize(this_player()->query_real_name());

  if (lvl > 20)
      lvl = 30;
  else
      lvl = lvl + 10;


  write(
  "*Here is a listing of the combat experience needed for the next levels:\n"+
  "[ with less than 100% quest experience for level you need much more ]\n\n");

  while (lvl >= to )
  {
     if (lvl == 30)
         write(to_string(lvl)+":\t\tImmortal"+" "+capname+"\t\t");
     else if (lvl < 6 && this_player()->query_gender()==1)
         write(to_string(lvl)+":\t\tKnight"+" "+capname+"\t\t");
     else if (lvl < 6 ) 
        write(to_string(lvl)+":\t\tMaid"+" "+capname+"\t\t");
     else if (this_player()->query_gender()==1)
        write(to_string(lvl)+":\t\tLord"+" "+capname+"\t\t");
     else 
        write(to_string(lvl)+":\t\tLady"+" "+capname+"\t\t");
     write("EXP: "+to_string("/guild/master"->query_exp(7,lvl)));
     write("\n");
     lvl--;
  }
  if ( (lg=this_player()->query_property("monk_legend"))>0)
      write("\nYou are a Legend level: "+to_string(lg));
  write("\nImmortallity might be reached at level 30.\n");
  return 1;
}
    
