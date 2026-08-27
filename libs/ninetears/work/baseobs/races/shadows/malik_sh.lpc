#define AN my_player->query_cap_name()
#define DN himx->query_cap_name()

object my_player;
object himx;

void dest_shadow();

int test_add() { return 0; }
void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
  my_player->add_alias("wolf");
}

string *query_languages() 
{
 return ({ "werewolf", "grunt" }); 
}

string query_current_language()
{
  return "werewolf";
}

string query_short() 
{
 string path = file_name(previous_object());
  if (!my_player)
    return "Werewolf hide";
  if((path[20..23] == "look") || (path[20..24] == "glance"))
    return "A wolf";
  if((path[0..18] == "/global/player/cmds")||
       (!previous_object()->is_player()))
    return my_player->short();
  return "A wolf";
}

string query_cap_name() 
{
  return capitalize(query_short());
}


void remove_werewolf_shadow()
{
  tell_object(my_player, "You return to your previous form.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" returns "+
   my_player->query_possessive()+" normal form.\n", my_player);
   my_player->remove_alias("wolf");
  destruct(this_object());
}

int adjust_hp(int i, object hp_remover) {

   if(previous_object()){
      if(previous_object()->query_weapon()){
         if(previous_object()->query_property("SILVER")||
            previous_object()->query_property("SILVER_BLADE")){

            i *= 1.5;
         }
         else if(previous_object()->query_enchant()<1){
            i = 0;
         }
      }
   }
   return my_player->adjust_hp(i, hp_remover);
}

mapping valid_attack() {
   return([
      "kick"     :({AN+" rends "+DN+" horribly.\n",
                   "You rend "+DN+" horribly.\n",
                    AN+" rends you horribly.\n"}), 
      "knee"     :({AN+" rakes "+DN+" with its claws.\n",
                   "You rake "+DN+" with your claws.\n",
                    AN+" rakes you with its claws.\n"}),
      "punch"    :({AN+" tears "+DN+" with its claw.\n",
                   "You tear "+DN+" with your claws.\n",
                    AN+" tears you with its fist.\n"}),
      "headbutt" :({AN+" savages "+DN+" with its jaws.\n",
                   "You savage "+DN+" with your jaws.\n",
                    AN+" savages you with its jaws.\n"})  ]);
}  /*  valid_attack()  */


/* this is from haste_sh.c */
int weapon_attack(object him, object me){
   int ret, i, num;
   object *weap;

   himx = him;
 
   weap = my_player->query_weapons_wielded();
   if(sizeof(weap))
      "/std/spells/wizard/useful_stuff"->force_drop_everything(my_player);     

   ret = 0;
   num = 1 + my_player->query_level()/10;  

   num += 1;
   num -= random(3);
   
   if(num < 1) num = 1;

   my_player->adjust_tmp_tohit_bon(50);
   my_player->adjust_tmp_damage_bon(5);

   for(i=0;i<sizeof(num);i++)
      ret += my_player->unarmed_attack(him,me);     

   my_player->adjust_tmp_tohit_bon(-50);
   my_player->adjust_tmp_damage_bon(-5);

} /* weapon_attack() */

