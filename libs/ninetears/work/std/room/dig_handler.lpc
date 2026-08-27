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
         if((string)olist[i]->query_name() == "pico de minero")
         {
            tool = olist[i];
            return(1);
         }
         if((string)olist[i]->query_name() == "pico")
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
   string adirec = "hueco";

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
            write("\nPor que ibas a cavar en un sitio donde ya "+
                  "existe una via de paso? Intentalo en otro "+
                  "lugar.\n\n");
               say("\n"+TPN+" se prepara para cavar, da un paso "+
                  "adelante y se para, se frota la barbilla "
                  "y pone mala cara.\n\n");
             return(1);
            }
         write("\nCavar con que?\n\n");
          return(1);
         }
      }
      if((string)dlist[i] && direc == (string)dlist[i])
      {
         string where = dwhere[i];
         if(query_wielded_pick())
         {
            write("\nComienzas a cavar lentamente en el suelo, pero "+
                  "encuentras dificultades. La roca y los estratos "+
                  "han permanecido durante tanto tiempo que parece "+
                  "imposible progresar. Pese a ello, con determinacion "+
                  "y esfuerzo terminas por abrir un hoyo.\n\n");
             tell_room(environment(this_player()),"\n   "+
                  this_player()->query_cap_name()+" empieza a cavar "+
                  "en el suelo con feroz determinacion"+
                  ". Tras cavar durante un buen rato se abre un "+
                  "hermoso hoyo.\n\n",({this_player()}));
            room_ob->add_exit(direc,where,"standard");
            room_ob->init();
            room_ob->renew_exits();
               if(direc == "este")
                 adirec = "oeste";
               if(direc == "oeste")
                 adirec = "este";
               if(direc == "norte")
                 adirec = "sur";
               if(direc == "sur")
                 adirec = "norte";
               if(direc == "arriba")
                 adirec = "abajo";
               if(direc == "abajo")
                 adirec = "arriba";
               if(direc == "noreste")
                 adirec = "sudoeste";
               if(direc == "sudeste")
                 adirec = "noroeste";
               if(direc == "noroeste")
                 adirec = "sudeste";
               if(direc == "sudoeste")
                  adirec = "noreste";
               if(direc == "dentro")
                  adirec = "fuera";
               if(direc == "fuera")
                  adirec = "dentro";
            where->add_exit(adirec,path,"standard");
         return(1);
         }
      write("\nCavar con que?\n\n");
      return(1);
      }
   }
   write("\nComienzas a cavar en el suelo con tal vigor que el aire "+
         "se llena de polvo rapidamente. Tan solo despues de tomar "+
         "un descanso te das cuenta que el hoyo apenas crece... "+
         "Parece como si tuvieras que cavar toda una eternidad.\n\n");
     say("\n   "+
         this_player()->query_cap_name()+" comienza a cavar con tal "+
         "furia y determinacion que tan solo puedes admirar su inutil "+
         "esfuerzo.\n\n");
   return(1);
}
