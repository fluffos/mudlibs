// /include/ship.h
// by bor @DA, 2/25 2003

int do_save_ship(object ob)
{
	string file, str;
	mapping dbase;
	int i;

	if(!ob) return 0;
	if( ob->query("type")!="ship" ) return 0;

	file = base_name(ob)+".lpc";
	dbase = ob->query_entire_dbase();

	str = "// file : " + file + "\n";
	str += "// save ship by "+ this_player(1)->query("id")+" @DA, "+ctime(time())+"\n";

	str += "#include \"ansi.h\"\ninherit SHIP;\n\nvoid create()\n{\n";
	str += sprintf("\tset(\"short\", %O);\n", kill_all_bug(dbase["short"]) );
	str += sprintf("\tset_name( %O, %O );\n", kill_all_bug(dbase["short"]), text_item_id(dbase["id"]) );

	str += "\tif( clonep() )\n\t\tset_default_object(__FILE__);\n\telse {\n";

	str += sprintf("\tset(\"long\", @TEXT\n%sTEXT\n\t);\n", kill_all_bug(dbase["long"]) );

	str += sprintf("\t\tset(\"type\", %O);\n", dbase["type"] );

	str += sprintf("\t\tset(\"port1\", %O);\n", dbase["port1"] );
	str += sprintf("\t\tset(\"port2\", %O);\n", dbase["port2"] );
	str += sprintf("\t\tset(\"max_load\", %O);\n", dbase["max_load"] );
	str += sprintf("\t\tset(\"value\", %O);\n", dbase["value"] );

	str += sprintf("\t\tset(\"unit\", %O);\n", dbase["unit"] );
	str += sprintf("\t\tset(\"no_kill\", %O);\n", dbase["no_kill"] );
	str += sprintf("\t\tset(\"no_get\", %O);\n", dbase["no_get"] );
	str += sprintf("\t\tset(\"kingdom_id\", %O);\n", dbase["kingdom_id"] );

	str += "\t}\n\tsetup();\n}\n";

	i = strlen(file)-1;
	while( (i > 0) && (file[i]!='/')) i--;
	if( i>0 ) {
		str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
	}

	write_file(file, str, 1);
	return 1;
}
