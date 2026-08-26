#if 0
// contents.c
// Buddha@tmi-2 (9-27-92)
// Renamed by Mobydick 11-14-92 to prevent confusion with the inheritable for
// bags and other containers.
// Changed ob to ({ob})  Leto, 11-94
// And thus i think i fixed it....maybe ?

nosave mapping contents;


int receive_object(object ob) {
	string short;

	short = (string)ob->query("short");
	if (!contents) {
		contents = ([ short : ({ ob }) ]);
		return 1;
	}
	if (!contents[short]) {
		contents[short] = ({ ob });
		return 1;
	}
	contents[short] += ({ ob });
	return 1;
}

int release_object(object ob) {
	int i;
	string short, *shorts;

	short = (string)ob->query("short");
	if (!contents) return 1; // huh? oh well, whatever.
	if (contents[short]) {
		if (sizeof(contents[short]) > 1) contents[short] -= ({ ob });
		else map_delete(contents, short);
		return 1;
	}
	// uh oh... the object's short has changed.
	// but the object should still be found and removed.
	shorts = keys(contents);
	for (i=0;i<sizeof(shorts);i++) {
		if (member_array(ob, contents[shorts[i]]) == -1) continue;
		if (sizeof(contents[shorts[i]]) > 1) contents[shorts[i]] -= ({ ob });
		else map_delete(contents, shorts[i]);
		return 1;
	}
	log_file("release_object", "object " + file_name(ob) + " not released"
		+ " from " + file_name(this_object()) + "!\n");
	return 1; 
}
	
mapping query_contents() { return contents; }
#endif
