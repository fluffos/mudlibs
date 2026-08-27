/*************************************************************************
 
             Shadow for the arrows stiked in the PCs
     
**************************************************************************/

#define CHANCE 50  // Chance of get damage every move. Change after fix 
#define DAM 1      // Damage for moving 

object enemy;
object proj;


void destruct_me() 
{
   enemy->remove_extra_look(this_object());  
   destruct(this_object());
}

void setup_shadow(object ob , object ob2) 
{
   shadow(ob,1);
   enemy = ob;
   proj = ob2;
}

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
   if( enemy->query_property("dead") )
   {
      proj->remove_property("cursed");
      proj->remove_property("stiked");      
      call_out("destruct_me",1);
   }      
   else if( random(100)<= CHANCE)
   {
      enemy->adjust_hp(-DAM,proj);
      tell_object(enemy ,"As you move you feel the "+proj->query_short()+
                  " removing into your body. You must extract the "
                  +proj->query_short()+".\n"); 
   }
  return enemy->move_player(dir, dest, message, followee, enter);
}

string extra_look()
{
   return ("Is bleeding from a stuck "+proj->query_short()+".\n");
}

int extract_proj(string str)
{
   object dagger;

   
   if ( ( 
          str == "dagger" || str == "knife" ||
          str == (string)this_object()->query_proj_name() ||
          str == (string)this_object()->query_name() ||    
          str == (string)this_object()->query_cap_name() ||    
          str == (string)this_object()->query_short() ) &&
    1 )
   {
      if ( random(100) > ((int)this_player()->query_dex() * 5) )
      {
         // The player cannot extract the arrow because he is clumsy  
         
              tell_object(this_player(), "You try to extract the "
                     +this_object()->query_name()+" "+
                     "but you only move it deeper into your flesh.\n");
         this_player()->adjust_hp(-1,this_object());         
         return 1;
      }
      tell_object(this_player(), "As you extract the "
            +this_object()->query_name()+" you feel a "
            "deep pain shoot through your body, but now you "
            "feel strangely better.\n");
   call_out("destruct_me",0);

      return 1;
   }
   else
      return 0;
}

