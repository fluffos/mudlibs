int update_player(string name) {
	object o;
	string qry = "", cname;

	if(!name || !o = find_player(name)) return 0;

	qry += "REPLACE INTO Player_Data (`Name`, `Race`, `Class`, `Subclass`, `Level`, `Experience`, `Position`, `Email`) VALUES(";
	if(o->query_invis()) cname = capitalize(o->query_name()); else cname = o->query_cap_name();
	qry += "'" + cname + "', ";
	qry += "'" + o->query_race() + "', ";
	qry += "'" + o->query_class() + "', ";
	qry += "'" + o->query_subclass() + "', ";
	qry += "'" + o->query_level() + "', ";
	qry += "" + o->query_exp() + ", ";
	qry += "'" + o->query_position() + "', ";
	qry += "'" + o->query_email() + "')";

	mysql_connect();
	mysql_query(qry);
	mysql_disconnect();

	return 1;
}
