string autol;
string filen;

set_autol(str) { autol = str; }
set_filen(str) { filen = str; }

save_me() {
  if(!autol || autol == "") return 0;
  save_object("room/prison/"+filen);
}
restore_me() {
  restore_object("room/prison/"+filen);
}
send_autol() {
  return autol;
  autol = 0;
  filen = 0;
  save_me();
}
