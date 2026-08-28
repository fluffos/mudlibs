main (string str)
{
  string logfile;

  logfile = "/log/" + str;

  if (file_size (logfile) < 0)
    notify_fail ("No such log file.\n");
  else
    tail (logfile);
  return 1;
}

