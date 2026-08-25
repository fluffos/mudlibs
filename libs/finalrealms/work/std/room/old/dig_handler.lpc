//    This is a function to set up exits that can be dug to...
//   ie <dig direction>  lets you if allowed to dig an exit in this
//     room...    **Piper**

mixed *add_dig_exit(mixed *dig_exit, mixed *dig_where,
            string direc, mixed dest)
{
// string *nodig = room_ob->query_direc();

   if(!dig_exit||sizeof(dig_exit) == 0)
      dig_exit = ({ });
      dig_exit += ({ direc });

   if(!dig_where||sizeof(dig_where) == 0)
      dig_where = ({ });
      dig_where += ({ dest });

   return ({ dig_exit, dig_where });
}

// This is a query for the array of diggable exits.... :)
//   returns the exits in array form....  **Piper**

//string *query_pos_dig() { return dig_exit; }

// This is a query for the array of diggable exit destinations
//    returns array of file pathnames...  **Piper**

//string *query_dig_dest() { return dig_where; }

//  Had to add the dig code to this file.. no longer inheriting it
//  needed add_exit (besides thought it might streamline better.)
//    ***Piper***   (4-1-95)
//   Inheritable digging routine...  dig (direction) with digging tool
//       Original idea by Lor
//       Major rework by Piper

//#define TP this_player()
#define TPP this_player()->query_possessive()
#define TPN this_player()->query_cap_name()


int query_wielded_pick()
{
   object tool;
   int i;
   object *olist;
   olist = this_player()->query_held_ob();
   for(i=0;i<sizeof(olist);i++)
   {
      if(olist[i])
      {
         if((string)olist[i]->query_name() == "shovel")
         {
            tool = olist[i];
            return(1);
         }
         if((string)olist[i]->query_name() == "mining pick")
         {
            tool = olist[i];
            return(1);
         }
         if((string)olist[i]->query_name() == "pick")
         {
            tool = olist[i];
            return(1);
         }
      }
   }
   return(0);
}

void do_dig(mixed *dig_exit, mixed *dig_where,
              object room_ob, string direc)
{
   mixed path = file_name(room_ob);
   string adirec = "hole";

   int i,j;
   mixed *dlist,*dwhere;
   dwhere = room_ob->query_dig_dest();
   dlist = room_ob->query_pos_dig();
   for(i=0;i<sizeof(dlist) && i<sizeof(dwhere);i++)
   {
     mixed *ndlist;
     ndlist = room_ob->query_direc();
     for(j=0;j<sizeof(ndlist);j++)
     {
         if((string)ndlist[j] && direc == (string)ndlist[j])
         {
            if(query_wielded_pick())
            {
            write("\n   Why would you dig somewhere that a way"+
                  " of passage already exists.  Try digging else"+
                  "where.\n\n");
               say("\n   "+TPN+" prepares to dig"+
                  ", takes a step forward then stops, slaps "+TPP+
                  " forehead and looks digruntled.\n\n");
             return(1);
            }
         write("\n   Dig with what?\n\n");
          return(1);
         }
      }
      if((string)dlist[i] && direc == (string)dlist[i])
      {
         string where = dwhere[i];
         if(query_wielded_pick())
         {
            write("\n   You begin to dig slowly into the earth, but"+
                  " meet difficulty immediately.  The rock and dirt"+
                  " here has been settled for so long, it seems that"+
                  " it will be immpossible to make any progress.  With"+
                  " determination and a little time however, you are"+
                  " finally able to dig a hole.\n\n");
             tell_room(environment(this_player()),"\n   "+
                  this_player()->query_cap_name()+" begins to dig"+
                  " into the earth with fierce determination"+
                  ".  After a considerable amount of digging a"+
                  " nice size hole develops.\n\n",({this_player()}));
            room_ob->add_exit(direc,where,"hole");
            room_ob->init();
            room_ob->renew_exits();
               if(direc == "east")
                 adirec = "west";
               if(direc == "west")
                 adirec = "east";
               if(direc == "north")
                 adirec = "south";
               if(direc == "south")
                 adirec = "north";
               if(direc == "up")
                 adirec = "down";
               if(direc == "down")
                 adirec = "up";
               if(direc == "northeast")
                 adirec = "southwest";
               if(direc == "southeast")
                 adirec = "northwest";
               if(direc == "northwest")
                 adirec = "southeast";
               if(direc == "southwest")
                  adirec = "northeast";
            where->add_exit(adirec,path,"hole");
         return(1);
         }
      write("\n   Dig with what?\n\n");
      return(1);
      }
   }
   write("\n   You start to dig into the earth with such vigor that"+
         " the air is growing dusty and thick with dirt.  It is only"+
         " after you take a rest that you realize that the hole is"+
         " growing very slowly...  Looks like your gonna be digging for a"+
         " while.\n\n");
     say("\n   "+
         this_player()->query_cap_name()+" starts to dig with a"+
         " determination that you can only admire."+
         "\n\n"+
         " ");
   return(1);
}

