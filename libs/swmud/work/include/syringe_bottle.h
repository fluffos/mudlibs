// Last edited by deforce on 03-25-2010
mapping liquid_color = ([
   "black" : "%^BOLD%^%^BLACK%^black%^RESET%^",
   "blue" : "%^BLUE%^blue%^RESET%^",
   "blueblack" : "%^BLUE%^blue%^RESET%^-%^BOLD%^%^BLACK%^black%^RESET%^",
]);

mapping liquid_fills = ([
   "black" : 10,
   "blue" : 10,
   "blueblack" : 10,
]);

mapping liquid_doses_per_fill = ([
   "black" : 10,
   "blue" : 10,
   "blueblack" : 10,
]);

mapping liquid_value = ([
   "black" : 250,
   "blue" : 100,
   "blueblack" : 400,
]);

mapping effect_file = ([
   "black" : "poison_black",
   "blue" : "poison_blue",
   "blueblack" : "poison_blue-black",
]);

string format_liquid_color(string liquid)
{
   if (liquid_color[liquid])
   {
      return liquid_color[liquid];
   }

   return liquid;
}

string get_liquid_effect_file(string liquid)
{
   if (effect_file[liquid])
   {
      return effect_file[liquid];
   }

   return effect_file["blue"];
}