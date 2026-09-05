inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You make a lame rimshot noise for yourself.  Man that was clever!$N$\n", "$MN$ makes a lame rimshot noise for $MO$self.  $CMS$ sure thinks $MS$'s clever.$N$\n");
       target("You make a lame rimshot noise for $TN$, and leave it to $TO$ to decide whether you're being sarcastic.$N$\n", "$MN$ makes a lame rimshot noise in $TN$'s honor.$N$\n", "$MN$ makes a lame rimshot noise for you.  $CTS$ must really think you're clever.$N$\n");
       afar("From afar, you make a lame rimshot noise for $TN$, and leave it to $TO$ to decide whether you're being sarcastic.$N$\n", "From afar, $MN$ makes a lame rimshot noise for you.  $CTS$ must really think you're clever.$N$\n");
    }
}

int
cmd_rimshot(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
