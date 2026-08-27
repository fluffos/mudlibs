//Paris. Ene'99 
object my_player;
int check_off = 0; 
start(object ob) 
{ 
   my_player = ob; 
   shadow(ob,1); 
} 
 
void destruct_blindness_shadow() 
{ 
   destruct(this_object()); 
} 

int check_duration()
{
  if (my_player->query_timed_property("cegado")) return 0;
  if (!check_off)
  {
    if (!my_player->query_dead())
      tell_object(my_player, "Por fin puedes ver de nuevo !.\n");
    check_off = 1;
  }
  return 1;
}

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter)
{
  if (check_duration()) call_out("destruct_blindness_shadow", 0, 0);
  return my_player->move_player(dir, dest, message, followee, enter);
}

attack_by(object ob) 
{ 
   if (check_duration()) call_out("destruct_blindness_shadow", 0, 0);
   if(random(2)) 
   { 
      tell_object(my_player,"Estas desorientado debido a tu ceguera!.\n"); 
      tell_room(environment(this_object()),this_object()->query_short()+ 
         " esta desorientado debido a su ceguera.\n",this_object()); 
   } 
   return my_player->attack_by(ob); 
} 
 

int query_total_ac() { return my_player->query_total_ac()+40; } 
 
int query_tmp_tohit_bon() { return (int)my_player->query_tmp_tohit_bon() - 4; } 
 
 
int query_blind_shadow() { return(1); } 
int query_blindness_shadow() { return(1); } 
int query_blind() { return(1); } 
int query_spell_cegar(){ return 1;}
 
