string *history;

create()
{
   history = ({ });
}

void finger_history(string name)
{
   string file = "/players/"+name[0..0]+"/"+name+".o";
   if(!this_player(1)->query_lord())
      return ;
   restore_object(file,1);
   write("Name: "+file+"\n");
   printf("%O\n",history);
   return;
}
