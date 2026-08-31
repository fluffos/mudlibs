inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   set_brief("Landing Control Office");
   set_long("The landing control office is strategically located near the main docking terminals. The room is a blend "
            "of high-tech functionality and utilitarian design, with walls lined with large, multi-screen consoles "
            "displaying real-time data on incoming and outgoing ships. The screens flash with radar images, "
            "communication logs, and status updates, casting a blue-green glow over the room.");
   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["south":"n_landing1"]));
   set_objects((["^common/item/status_monitor":1, "^omega/npc/floor8/aria_voss":1]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}

/*

Behind the main counter stands the chief landing controller, Aria Voss, a seasoned veteran with sharp eyes and an air of
authority. She wears a crisp uniform adorned with insignias of her rank and years of service. Her short-cropped hair is
streaked with silver, hinting at her vast experience, and her focused expression reveals a mind always at work, juggling
multiple tasks at once. A headset is permanently affixed to her ear, connecting her to various ship channels and station
personnel.

The office is equipped with several workstations, each manned by diligent staff members who monitor ship movements and
handle emergency communications. The air is filled with the hum of machinery and the occasional crackle of static from
the communication devices. The atmosphere is tense but controlled, as the team is trained to deal with the constant flow
of ships, including those that don't respond or are in distress. Charts and maps of the surrounding space are pinned to
the walls, along with emergency protocols and docking procedures, ensuring that everyone knows their role in maintaining
the station's safety and efficiency.*/