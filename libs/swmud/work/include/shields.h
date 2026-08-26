string *shield_names = ({
   ({ "main" }),
   ({ "front", "rear" }),
   ({ "front", "left", "right" }),
   ({ "front", "left", "rear", "right" }),
   ({ "front", "left", "rear left", "rear right", "right" }),
   ({ "front", "front left", "rear left", "rear", "rear right", "front right" }),
   ({ "front", "front left", "left", "rear left", "rear right", "right", "front right" }),
   ({ "front", "front left", "left", "rear left", "rear", "rear right", "right", "front right" }),
});

string get_shield_name(int shield_count, int shield_number)
{
   if (shield_names[shield_count - 1])
   {
      mixed names = shield_names[shield_count - 1];

      if (names[shield_number - 1])
      {
         return names[shield_number - 1];
      }
   }

   return "unavailable";
}

int get_shield_number(int shield_count, string shield_name)
{
   if (shield_names[shield_count - 1])
   {
      if (member_array(shield_name, shield_names[shield_count - 1]) > -1)
      {
         return member_array(shield_name, shield_names[shield_count - 1]) + 1;
      }
   }

   return 0;
}

string *get_shield_name_data()
{
   return shield_names;
}