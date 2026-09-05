inherit "/bin/std";

void
reset(int x)
{
   if(!x) {
      ::reset();
      nontarget("You spank yourself!$N$\n", "#MN# spanks #MO#self.$N$\n");
      target("You spank #TN#!$N$\n", "#MN# spanks #TN#!$N$\n", "#MN# spanks you!$N$\n");
      afar("You spank #TN# from afar!$N$\n", "#MN# spanks you from afar!#RET#$N$\n");
   }
}

int
cmd_spank(string arg)
{
   if(arg == "katya" && (string)this_player()->query_real_name() != "vertebraker")
      arg = 0;
   return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
