
/*
** mist_move.c
**
** -moves player to a random direction.
**
** (C) Tron.
***************************************/

status done;
string *dirs;
status executing;

status
id(string str) { return str=="mist_move"; }

void
init() {
   
   int i;
   
   dirs=(string *)environment(this_player())->query_dest_dir();    
   if(!dirs) return;
   
   for(i=0; i<sizeof(dirs)/2; i++) 
     add_action("move_me", dirs[i*2+1]);

}

status
move_me() {   

string rnd_dir;
   
   if(executing)  return 0;

   if(environment()->query_mist())  
   {
      executing=1;
      rnd_dir=dirs[random(sizeof(dirs)/2)*2 + 1];
      command(rnd_dir, this_player());
      executing=0;
    }

   return 1;
}


