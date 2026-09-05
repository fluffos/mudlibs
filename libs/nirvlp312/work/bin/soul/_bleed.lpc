inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You $R$bleed$N$ all over the place.$N$\n", "#MN# $R$bleeds$N$ all over the place.$N$\n");
       target("You $R$bleed$N$ all over #TN#.$N$\n", "#MN# $R$bleeds$N$ all over #TN#.$N$\n", "#MN# $R$bleeds$N$ all over you.$N$\n");
       afar("You $R$bleed$N$ all over #TN# from afar.$N$\n", "#MN# $R$bleeds$N$ all over you from afar.$N$\n");
    }
}

int
cmd_bleed(string arg)
{
    if((int)this_player()->query_hp() >= (int)this_player()->query_mhp())
      return (write("You aren't damaged and thus aren't bleeding.\n"), 1);
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }

int broadcast(string channel, string arg)
{
  if((int)this_player()->query_hp() >= (int)this_player()->query_mhp())
    return (write("You aren't damaged and thus aren't bleeding.\n"), 1);
  return ::broadcast(channel,arg);
}
