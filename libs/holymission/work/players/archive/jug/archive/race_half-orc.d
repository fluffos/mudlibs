inherit "players/jug/room/race_room";

reset(arg) {
	if (arg) return;
	::reset();
	init_room("half-orc");
}
