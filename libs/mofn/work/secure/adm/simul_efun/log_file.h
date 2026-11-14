private nosave mapping _log_file_info = ([ ]);
private nosave int _log_file_flush_id;

#define LOG_NAME(X) ((X[0] == '/') ? X : "/log/"+X)

// 5 minutes
#define DELAY_LOG_FLUSH 300

#define MAX_SIZE 50000

/**
 * This method flushes out all the buffered stuff for the log files.
 */
private void flush_log_files() {
   string fname;
   string data;

   _log_file_flush_id = 0;
   foreach (fname, data in _log_file_info) {
      if (file_size(LOG_NAME(fname)) > MAX_SIZE) {
         unguarded((: rm, LOG_NAME(fname)+".old" :));
         unguarded((: rename, LOG_NAME(fname), LOG_NAME(fname)+".old" :));
      }
      map_delete(_log_file_info, fname);
      unguarded((: write_file, LOG_NAME(fname), data :));
   }
   _log_file_info = ([ ]);
}

/**
 * This method writes a message out ot a log file.  The log files are
 * normally in "/log".  If a file doesn't start with '/ then "/log/" will be
 * preppended to it.
 * This does automatic removal of the log files after they get over
 * a certain length.  The fmt and args parameters are used to print the
 * actual message.
 * <p>
 * If more than one argument is passed to this function, then sprintf will
 * be used to print out the results.
 * <p>
 * ie: log_file("ROGER", "%s: frog and %s\n", ctime(time()), query_gumboot());
 *
 * @param name the name of the log file
 * @param fmt the format string
 * @param args the arguments to the sprintf
 */
varargs void log_file(string name, string fmt, mixed *args ...) {
  /* five screens */
  if ( strlen( fmt ) > 8000 ) { /* five screens */
    fmt = fmt[ 0 .. 7999 ] +"\n\nPlus more...\n\n";
  }
  //fmt = terminal_colour(fmt, ([]));
  if (!_log_file_flush_id) {
     _log_file_flush_id = call_out((: flush_log_files :), DELAY_LOG_FLUSH);
  }
  if (!_log_file_info[name]) {
     _log_file_info[name] = "";
  }
  if (sizeof(args)) {
    _log_file_info[name] += sprintf(fmt, args ...);
  } else {
    _log_file_info[name] += fmt;
  }
}
