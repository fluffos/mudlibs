int file_time(string path);
varargs void log_file(string file, string str, status no_trunc);
int copy_file(string source, string dest);
varargs int tail(string file, int len);
int truncate_file(string file, int position);

