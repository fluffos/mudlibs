/*
    Taniwha's attempt at a clothing class
   based on Baldrick's armour, but just sits and 
   look's purty , so it's far easier.
 */

inherit "/std/item";
nosave int material;
int clothing_type;

int query_value()
{
   return(value);
}

/* here is the new setup routine, will make the whole a lot cleaner.. */
varargs int set_base_clothing(string type,string myname,string myplural,int wt,int val,string long);

varargs int set_base_clothing(string type,string myname,string myplural,int wt,int val,string long)
  {
   if(type == "shirt")
   {
      clothing_type = 1;
      set_name("shirt");
      set_main_plural("shirts");
   }
   if(type == "pants")
   {
      clothing_type = 2;
      set_name("pants");
      set_main_plural("pair or pair of pants");
   }
   if(type == "scarf")
   {
      clothing_type = 3;
      set_name("scarf");
      set_main_plural("scarves");
   }
   if(type == "stockings")
   {
      clothing_type = 4;
      set_name("stockings");
      set_main_plural("stockings");
   }
   if(type == "skirt")
   {
      clothing_type = 5;
      set_name("skirt");
      set_main_plural("skirts");
   }
   if(type == "hat")
   {
      clothing_type = 6;
      set_name("hat");
      set_main_plural("hats");
   }
   if(type == "shoes")
   {
      clothing_type = 7;
      set_name("shoes");
      set_main_plural("pair of shoes");
   }
   set_short(myname);
   add_plural(myplural);
   set_weight(weight);
   set_value(val);
   set_long(long);
}

int query_clothing_type() { return clothing_type; }
int query_armour_type() {return(0);}

string query_clothing_type_name() 
  {
  switch (clothing_type)
    {
    case 1:
      return "shirt";
    case 2:
      return "pants";
    case 3:
      return "scarf";
    case 4:
      return "stockings";
   case 5:
      return "skirt";
   case 6:
      return "hat";
   case 7:
      return "shoes";
    default:
      return "unknown";
    }
}


void create() 
  {
  item::create();
  add_alias("clothing"); 
  add_plural("clothes"); 
   set_wearable(1);
} 

void dest_me() 
  {
  return ::dest_me();
}

