#pragma strong_types
#pragma save_types

#define MAX_LOG_SIZE 50000

void
log_file(string file,string str)
{
    string file_name;
    int *st;

    file_name = "/log/" + file;

    if (sizeof(regexp(({file}), "/")) || file[0] == '.' || sizeof(file) > 30 )
    {
	write("Illegal file name to log_file("+file+")\n");
	return;
    }

#ifdef AMYLAAR
    if ( sizeof(st = get_dir(file_name,2) ) && st[0] > MAX_LOG_SIZE) {
	catch(rename(file_name, file_name + ".old")); /* No panic if failure */
    }
#endif

    if (previous_object()) set_this_object(previous_object());
    write_file(file_name, str);
}
