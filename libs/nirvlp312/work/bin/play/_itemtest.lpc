/* 08/13/06 Earwax: Daemonized this */
int cmd_itemtest(string arg)
{
  int i, siz;
  object *ob;

  ob = (object *) this_player()->query_treasure_obj();
  siz = sizeof( ob );
  write("The following items will be entered into your save list\n"+
        "in case of a crash or reboot upon a save.\n");
  write("<---------------------------------------------------------->\n");
  if( ob ) {
    for( i=0; i < siz; i++ ) {
      write("--> "+ob[i]->short()+"\n");
    }
  }
  write("<---------------------------------------------------------->\n"); 
  return 1;
}
