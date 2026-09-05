inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Jab who?\n", "0\n");
       target("You jab #TN# in both eyes!\n", "#MN# jabs #TN# in both eyes!\n", "#MN# jabs you in both eyes!\n(Try typing 'bridget' next time to be prepared)\n");
       afar("You jab #TN# in both eyes from afar!\n", "#MN# jabs you in both eyes from afar!\n(Better be prepared with a 'bridget' next time)\n");
    }
}

int
cmd_jab(string arg)
{
  object dood;
  if(arg && (dood = find_player(arg)))
  {
    int i;
    if("/bin/play/_bridget"->query_bridge(dood))
    {
      tell_object(dood, "You BLOCK the eye-jab successfully.\nNyuk nyuk.\n");
      write("Your attempted jab is FOILED by "+(string)dood->query_name() +
     "'s EYEBRIDGE!!!\n");
     emit_channel("junk", "\
(junk) "+(string)this_player()->query_name()+" and "+(string)dood->query_name()+
" just engaged in a classic, yet completely assinine Three Stooges Routine[tm].\n");
     return 1;
    }
  }
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
