//	speak command used to change your default language used in says
//	and yells.
//	DarkeLIB 0.1
//	DarkeMUD

int cmd_speak(string str) {
    int prof;

if(!this_player() && previous_object() && living(previous_object())) {
previous_object()->set_primary_lang(str);
return 1;
}
    prof = (int)this_player()->query_lang_prof(str);
    if(!prof)
	return notify_fail("You do not know how to speak "+str+".\n");
    this_player()->set_primary_lang(str);
    write("You are now speaking in "+str+".");
    return 1;
}

void help() {
message("help",
"This command is used to change the default language you speak in for "
"says and yells.\nSyntax: speak <languages>.\nsee also: languages, say, yell.",
this_player());
}
