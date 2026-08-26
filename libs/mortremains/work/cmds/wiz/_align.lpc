/*
** FILE: _align.c  (a command)
** PURPOSE: Sets the "title" string of a wizard.
** CREATOR: Cyanide@QuestionMud
** CHANGES:
**   Apr 24 97    Cyanide    Created the file.
*/

int cmd_align (string str) {
    if (!str) {
	write ("You must include an argument with that command.\n");
	return 1;
    }

    if (strlen(str)>30) {
	write("Your alignment cannot be larger than 30 characters.\n");
	return 1;
    }

    this_player()->set("al_title", str);
    write("Your alignment has been set to \""+str+"\".\n");
    return 1;
}

string help() {
    return "Syntax: align alignment\n\n"+
    "This command is used to change your alignment text.\n";
}

