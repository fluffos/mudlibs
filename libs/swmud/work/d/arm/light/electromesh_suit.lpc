inherit ARMOR;
inherit ARMOR_CUSTOM;

void setup()
{
   set_id("electromesh suit", "suit", "armor");
   set_long("This light combat suit is used by Nagai operatives.  It is highly resistant to blaster fire and is designed to allow the Nagai to fully capitalize on their naturally high dexterity.  It cannot be used with overlays, however.");

   set_slots("torso", "right arm", "left arm", "right leg", "left leg");

   set_armor_class(6);
   set_resistances(([ "%energy" : 5 ]));

   set_mass(7000);
   set_value(5000);
}

int cannot_use_component(string type, string name)
{
   if (type == "armor overlay") { return 1; }

   return 0;
}