inherit "std/thing";

string maptext;

buildmap() {
	maptext = " ------- Nightfall Flightdragon Airways -------- \n\n";
	maptext += "current prize: 100 copper coins to enter a gondola.\n\n";
	maptext += call_other("d/archwiz/randyandy/dragon/green_dragon", "get_stationlist");
	maptext += "\n";
	maptext += call_other("d/archwiz/randyandy/dragon/red_dragon", "get_stationlist");
	maptext += "\n";
	maptext += call_other("d/archwiz/randyandy/dragon/black_dragon", "get_stationlist");
	maptext += "\n";
	maptext += call_other("d/archwiz/randyandy/dragon/pink_dragon", "get_stationlist");
	maptext += "\n";
}
	
void create() {
	::create();
	seteuid(getuid());
	SetShort("a map");
  SetHelpMsg(
"This map shows you the different flighing routes of the Nightfall "
"Dragon Airways.\n");
	SetLong(
"The Nightfall Flightdragon Airways map. You can read it.\n");
        AddId("map");
        AddId("airmap");
        SetWeight(100);
        SetValue(2);
        buildmap();
}

init() {
	add_action("read", "read");
}

read(str) {
	if(!(str == "map" || str == "airmap")) {
		return 0;
	}
	write(maptext);
	return 1;
}

