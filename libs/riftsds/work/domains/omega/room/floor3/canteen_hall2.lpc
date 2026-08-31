inherit INDOOR_ROOM;

string sign()
{
   return "An illuminated sign overhead guide you toward the canteen, indicating the direction with playful "
          "icons of plates, coffee cups, and cutlery.";
}

void setup()
{
   set_area("omega_terminal", "hallway");
   set_brief("Canteen hallway near elevator");
   set_long("A well-lit and bustling hallway stretches out before you, leading to the canteen area. The walls are "
            "adorned with vibrant digital displays. The soft glow from these displays casts a warm and inviting "
            "ambiance throughout the corridor. The hallway itself is sleek and streamlined, with polished metallic "
            "walls. The floor beneath your feet is made of "
            "durable composite material, designed to withstand heavy foot traffic and occasional spills.\n"
            "An illuminated sign hangs overhead.");
   set_exits((["south":"canteen_hall1", "north":"canteen_area_sw"]));
   add_item("floor", "The surface has a subtle texture that provides traction and minimizes the risk of slipping, "
                     "ensuring safe passage for the station's inhabitants.");
   add_item("display", "displays",
            "The displays showcase captivating holograms of animated celestial bodies, deep space "
            "exploration, and the wonders of the universe.");
   add_item("wall", "walls",
            (["adjs":"metallic", "look":"The metallic walls reflect the light, creating a sense of spaciousness."]));
   add_item("sign", (["adjs":({"illuminated"}), "look":sign(), "read":sign()]));
   set_smell("As you make your way down the corridor, the faint aroma of freshly brewed coffee and delicious food "
             "wafts through the air, originating from the canteen ahead.");
   set_listen("The distant sound of cheerful conversations and the clinking of utensils hint at the lively atmosphere "
              "awaiting you.");
}
