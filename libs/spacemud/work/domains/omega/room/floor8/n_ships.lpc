inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   set_brief("Nova Ship Trading");
   set_long("The shop trading in space ships is a dimly lit establishment, with rows of sleek" +
            "spacecraft lining the walls. Neon signs flicker overhead, casting an otherworldly" +
            "glow across the room. Potential buyers browse the " +
            "selection of ships, inspecting their features and specifications displayed on " +
            "holographic screens. The shop exudes an atmosphere of excitement and possibility, " +
            "as customers envision themselves embarking on thrilling interstellar adventures " +
            "aboard their newly acquired vessels.");
   set_smell("The air carries a faint scent of lubricants and ionized particles, a testament to the "
             "high-tech nature of the shop's offerings.");
   set_listen("The air is filled with the hum of engines and the faint scent of lubricants. ");

   set_exits((["east":"n_hall2"]));
   set_exit_msg("east",
                ({"$N $vslide through the automatic doors the last moment before they close.",
                  "$N $vexit through the automatic doors south.", "$N $vleave east through the automatic doors."}));
   set_enter_msg("east", ({"$N $varrive through the automatic doors.", "$N $vwalk in."}));
   set_combat_forbidden(1);
}
