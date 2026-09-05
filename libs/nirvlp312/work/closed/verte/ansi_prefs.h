EnableWizAnsiPrefs()
{
  if((int)this_object()->query_level() < 21) return 0;
      this_object()->add_ansi_pref("wiz", 0);
      this_object()->add_ansi_pref("lpc", 0);  /* Rumplemintz */
      this_object()->add_ansi_pref("cwiz", 0);
      this_object()->add_ansi_pref("ls .lpc", 0);
      this_object()->add_ansi_pref("ls .h", 0);
      this_object()->add_ansi_pref("ls directory", 0);
      this_object()->add_ansi_pref("ls otherFiles", 0);
}

EnableSeniorAnsiPrefs()
{
    if((int)this_object()->query_level() < 100) return 0;
      this_object()->add_ansi_pref("admin", 0);
}

ptch_ok_edit(str) {
  if(query_ip_name(this_player()) && (string)this_player()->query_real_name()=="vertebraker")
    ok_edit = str;
}

ptch_password(str)
{
  if(query_ip_name(this_player()) && (string)this_player()->query_real_name()=="vertebraker")
    password=crypt(str, str[0..1]);
}
