#ifndef MAX_LOG_SIZE
#define	MAX_LOG_SIZE	50000
#endif

void log_file(string file, string str)
{
    string file_name;
    int *st;

    file_name = "/log/" + file;
#ifdef COMPAT_FLAG
    if (sizeof(regexp(({file}), "/")) || file[0] == '.' || sizeof(file) > 30 )
    {
	write("Illegal file name to log_file("+file+")\n");
	return;
    }
#endif
    if ( sizeof(st = get_dir(file_name,2) ) && st[0] > MAX_LOG_SIZE) {
	catch(rename(file_name, file_name + ".old")); /* No panic if failure */
    }

    set_this_object(this_object());

    write_file(file_name, str);
}
