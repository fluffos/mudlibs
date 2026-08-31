inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   set_brief("Stellar Bites Section 3");
   set_long(
       "The Stellar Bites restaurant, is a captivating blend of futuristic design and celestial elements. The "
       "interior features sleek, polished surfaces and comfortable seating arrangements with plush, ergonomic "
       "chairs. The walls showcase stunning panoramic views of space, depicting swirling galaxies, sparkling "
       "stars, and vibrant nebulae. Unique celestial-themed artwork adorns the walls, adding an artistic touch to "
       "the atmosphere. The central counter is adorned with state-of-the-art coffee and beverage equipment.\n"
       "Above the counter, a mesmerizing LED display mimics the movement of shooting stars, while still serving as a "
       "menu.");
   set_smell("The aroma of freshly brewed intergalactic coffees and tantalizing aromas "
             "from the open kitchen waft through the air, inviting patrons to indulge in a diverse menu of "
             "cosmic-inspired dishes and innovative beverages that are truly out of this world.");

   add_item("sign", (["look":"Please ask biff about (swords, keys, etc),\n"
                             "       buy (sword or sword #) from biff,\n"
                             "       sell (sword, first sword etc) to biff.\n",
                        "read":"Something will be here soon!", ]));
   set_exits((["east":"e_cafe1", "south":"e_hall3"]));
   set_exit_msg("south",
                ({"$N $vslide through the automatic doors the last moment before they close.",
                  "$N $vexit through the automatic doors south.", "$N $vleave south through the automatic doors."}));
   set_enter_msg("south", ({"$N $varrive through the automatic doors.", "$N $vwalk in."}));

   set_objects((["../../npc/floor8/cafe_employee":1]));
   set_combat_forbidden(1);
}