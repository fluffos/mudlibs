int main() {
	string buf = "WHITE(HP:) ";
	int percent = this_player()->query_hp() * 100 / this_player()->query_max_hp();
	if( percent > 100 )
		buf += "BLUE(";
	else if ( percent > 75 )
		buf += "GREEN(";
	else if ( percent > 50 )
		buf += "YELLOW(";
	else if ( percent > 25 )
		buf += "RED(";
	else
		buf += "GRAY(";
	buf += this_player()->query_hp()+")/"+this_player()->query_max_hp();
	buf += " ("+percent+"%) WHITE(Mana:) ";
	buf += this_player()->query_mana()+"/"+this_player()->query_max_mana();
	buf += " WHITE(End:) ";
	buf += this_player()->query_endurance()+"/"+this_player()->query_max_endurance();
	command("say "+buf, this_player());
	return 1;
}
