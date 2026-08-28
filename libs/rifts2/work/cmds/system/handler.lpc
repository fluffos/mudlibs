//  Generic error handler for commands.

void handle_error(string res, object tp, string report) {
  if(!strlen(res) || lower_case(res[0..0]) != "y") {
    write("Error report not displayed.");
    tp->set("error report", 0);
    return;
  }
  if(!report) {
    write("No error report available.");
    return;
  }
  write("Error report:\n");
  tp->more(explode(report, "\n"));
  tp->set("error report", 0);
  return;
}

