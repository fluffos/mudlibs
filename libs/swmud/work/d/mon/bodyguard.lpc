inherit ADVERSARY;

object owner;

void setup(object set_owner, int level, string race, int sex)
{
   owner = set_owner;

   if (level < 1)
   {
      level = 1;
   }

   if ((sex < 0) || (sex > 2))
   {
      sex = random(2) + 1;
   }

   set_sex(sex);
   set_race(race);
   set_unique(1);
   set_id("bodyguard");
   set_name(owner->short() + "'s bodyguard");
   set_in_room_desc(owner->short() + "'s bodyguard");
   set_long("A bodyguard who was hired to protect " + owner->short() + " from harm.");

   set_max_health(random(100) + 100 + (level * 40));
   set_health(query_max_health());
   set_wimpy(50);

   set_str(100);
   set_con(100);
   set_agi(100);
   set_dex(100);
   set_per(100);
   set_int(80);
   set_cha(80);
   set_luc(80);
   set_for(50);

   set_guild_level("mercenary", level);
   set_primary_guild("mercenary");

   if (level > 20)
   {
      set_guild_level("engineer", level - 10);
      set_skill("armor repair", 1000);
      set_skill("blaster repair", 1000);
      set_skill("droid repair", 1000);
      set_skill("melee repair", 1000);

      set_guild_level("physician", level - 10);
      set_skill("anatomy", 1000);
      set_skill("first aid", 1000);
      set_skill("surgery minor", 1000);
      set_skill("surgery major", 1000);
   }

   if (level > 30)
   {
      set_guild_level("assassin", level - 20);
   }

   set_skill("unarmed", 1000);
   set_skill("pistol combat", 1000);
   set_skill("rifle combat", 1000);
   set_skill("slash 1h", 1000);
   set_skill("slash 2h", 1000);
   set_skill("strike 1h", 1000);
   set_skill("strike 2h", 1000);
}

int is_diplomat_bodyguard() { return 1; }

void do_command(object commander, string command)
{
   string token_1;
   string token_2;
   string token_3;
   string token_4;
   string token_5;

   if (owner && (commander != owner))
   {
      do_game_command("say I only take orders from " + owner->short() + ", " + commander->short() + ".");
      return;
   }

   if (command == "defend")
   {
      object target = commander->get_target();

      if (target)
      {
         initiate_combat(target);
         switch_to(target);
      }
      else
      {
         tell(commander, this_object()->short() + " says: You don't have a target at the moment.\n");
      }
   }
   else if (sscanf(command, "desc %s", token_1) == 1)
   {
      if (token_1 == "clear")
      {
         set_long("");

         tell(commander, this_object()->short() + " says: My description has been cleared.\n");
      }
      else if (strlen(token_1) > 800)
      {
         tell(commander, this_object()->short() + " says: My description cannot be more than 800 characters.\n");
      }
      else if (strlen(token_1) < 1)
      {
         tell(commander, this_object()->short() + " says: My description must be at least 1 character, if you set a description.\n");
      }
      else
      {
         set_long(token_1);

         tell(commander, this_object()->short() + " says: My description has been set.\n");
      }
   }
   else if (command == "dismiss")
   {
      simple_action("$N $vdrop everything $n's carrying before leaving.");
//      do_game_command("drop all");

      foreach (object thing in all_inventory())
      {
         thing->do_remove();
         thing->do_unwield();
         thing->clear_flag(F_WORN);
         thing->clear_flag(F_WIELDED);
         thing->clear_flag(F_HELD);
         thing->move(environment());
      }

      destruct(this_object());
   }
   else if (sscanf(command, "drop %s", token_1) == 1)
   {
      do_game_command("drop " + token_1);
   }
   else if (sscanf(command, "emote %s", token_1) == 1)
   {
      do_game_command("emote " + token_1);
   }
   else if (sscanf(command, "follow %s", token_1) == 1)
   {
      object target = present(token_1, environment(this_object()));

      if (target)
      {
         if (query_follow() == target)
         {
            do_game_command("say I'm already following " + target->short() + ".");
            return;
         }

         clear_follow_search();
         do_follow_obj(target);
         do_game_command("say I will now follow " + target->short() + ".");
      }
      else
      {
         tell(commander, this_object()->short() + " says: I don't see any \"" + token_1 + "\" here.\n");
      }
   }
   else if (sscanf(command, "get %s", token_1) == 1)
   {
      do_game_command("get " + token_1);
   }
   else if (sscanf(command, "give %s to %s", token_1, token_2) == 2)
   {
      do_game_command("give " + token_1 + " to " + token_2);
   }
   else if (sscanf(command, "go %s", token_1) == 1)
   {
      do_game_command("go " + token_1);
   }
   else if (command == "health")
   {
      do_game_command("say I am " + health_description(this_object()->query_health() * 100 / this_object()->query_max_health()) + ".");
   }
   else if (sscanf(command, "kill %s", token_1) == 1)
   {
      do_game_command("kill " + token_1);
   }
   else if (sscanf(command, "name %s", token_1) == 1)
   {
      if (strlen(token_1) > 70)
      {
         tell(commander, this_object()->short() + " says: My name cannot be more than 70 characters.\n");
      }
      else if (strlen(token_1) < 2)
      {
         tell(commander, this_object()->short() + " says: My name must be at least 2 characters.\n");
      }
      else
      {
         clear_id();
         set_id("bodyguard", token_1);
         set_name(token_1);
         set_in_room_desc(token_1);

         tell(commander, this_object()->short() + " says: I am now known as \"" + token_1 + "\".\n");
      }
   }
   else if (sscanf(command, "remove %s", token_1) == 1)
   {
      do_game_command("remove " + token_1);
   }
   else if (sscanf(command, "say %s", token_1) == 1)
   {
      do_game_command("say " + token_1);
   }
   else if (sscanf(command, "sex %s", token_1) == 1)
   {
      if ((token_1 == "male") || (token_1 == "m"))
      {
         set_sex(1);

         tell(commander, this_object()->short() + " says: I am now male.\n");
      }
      else if ((token_1 == "female") || (token_1 == "f"))
      {
         set_sex(2);

         tell(commander, this_object()->short() + " says: I am now female.\n");
      }
      else if ((token_1 == "neuter") || (token_1 == "n"))
      {
         set_sex(0);

         tell(commander, this_object()->short() + " says: I am now neuter.\n");
      }
      else
      {
         tell(commander, this_object()->short() + " says: My sex must be specified as 'male', 'female' or 'neuter'.\n");
      }
   }
   else if (command == "stay")
   {
      clear_follow_search();
      clear_follow();
      do_game_command("say I will no longer follow anyone.");
   }
   else if (command == "unwield")
   {
      do_game_command("unwield");
   }
   else if (sscanf(command, "unwield %s", token_1) == 1)
   {
      do_game_command("unwield " + token_1);
   }
   else if (sscanf(command, "wear %s", token_1) == 1)
   {
      do_game_command("wear " + token_1);
   }
   else if (command == "wield")
   {
      do_game_command("wield");
   }
   else if (sscanf(command, "wield %s", token_1) == 1)
   {
      do_game_command("wield " + token_1);
   }
   else if (command == "wimpy")
   {
      int wimpy = this_object()->query_wimpy();

      if (wimpy <= 0)
      {
         tell(commander, this_object()->short() + " says: I will fight until I die!");
         return;
      }

      tell(commander, this_object()->short() + " says: I will retreat from combat when my health is below " + this_object()->query_wimpy() + "%.");
   }
   else if (sscanf(command, "wimpy %s", token_1) == 1)
   {
      int wimpy = to_int(token_1);

      if ((!wimpy && (token_1 != "0")) || (wimpy < 0))
      {
         tell(commander, this_object()->short() + " says: My wimpy must be a positive number.");
         return;
      }
      else if ((wimpy < 0) || (wimpy > 50))
      {
         tell(commander, this_object()->short() + " says: My wimpy must be from 0-50.");
         return;
      }

      this_object()->set_wimpy(wimpy);

      if (wimpy <= 0)
      {
         tell(commander, this_object()->short() + " says: I will now fight until I die!");
         return;
      }

      tell(commander, this_object()->short() + " says: I will now retreat from combat when my health is below " + this_object()->query_wimpy() + "%.");
   }
   else
   {
      tell(commander, this_object()->short() + " says: I didn't understand your command.");
   }
}

object query_owner() { return owner; }
int query_experience() { return 0; }

void add_experience(int x)
{
//   do_game_command("say I got " + x + " exp!  Yay!");

   if (x < 0)
   {
      x = 0;
   }

   if (owner)
   {
//      int owner_exp = x * 80 / 100;
//      do_game_command("say I'm giving " + owner_exp + " of that exp to " + owner->short() + "...");
//      owner->add_experience(owner_exp);
      owner->add_experience(x);
   }

   set_experience(0);
}
/*
void set_bodyguard_owner(object new_owner)
{
   if (new_owner)
   {
      owner = new_owner;

      set_name(owner->short() + "'s bodyguard");
      set_in_room_desc(owner->short() + "'s bodyguard");
      set_long("A bodyguard who was hired to protect " + owner->short() + " from harm.");
   }
}
*/