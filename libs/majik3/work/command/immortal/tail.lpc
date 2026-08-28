int main (string str) {
    string *lines;
    int i;

    if (!str || str == "") {
	write ("Usage: tail <filename>\n");
	return 1;
    }
    if (!absolute_path(str)) { 
	str = THIS->query_cwd() + str ;
    }
    str = resolve_path(str) ;
    if (file_size(str)<0) {
	notify_fail (str + ": No such file or directory.\n");
	return 0 ;
    }
    lines = explode(read_file(str), "\n");
    for (i=sizeof(lines)-20; i<sizeof(lines); i++)
	message("write", lines[i]+"\n", this_player());
    return 1 ;
}

