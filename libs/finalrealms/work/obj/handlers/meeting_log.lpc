#define FNAME "/log/heaven/meeting."

void create() {
  seteuid("Root");
}

void log_it(string junk) {
  string tm, dt;
  tm = ctime(time());
  if(tm[8..8] != " ")
    dt = tm[4..6]+tm[8..9];
  else
    dt = tm[4..6]+tm[9..9];

  if(file_name(previous_object()) != "/room/admin/meeting")
    return;

  write_file(FNAME+dt,junk);
}
