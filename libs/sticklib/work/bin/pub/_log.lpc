nomask status log_cmd()
{
    string name, filename;

    name = (string)this_player()->query_real_name();
    if (file_size(filename = "/log/history/"+name[0..0]+"/"+name) < 0)
	return notify_fail("No log exists.\n"), 0;

    this_player()->more(explode(read_file(filename), "\n"));
    return 1;
}
