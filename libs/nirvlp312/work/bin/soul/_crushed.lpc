inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look crushed.\n", "#MN# looks crushed.\n");
       target("You look crushed because of #TN#.\n", "#MN# looks crushed because of #TN#.\n", "#MN# looks crushed because of you.\n");
       afar("You look crushed because of #TN#, from afar.\n", "#MN# looks crushed because of you, from afar.\n");
    }
}

int
cmd_crushed(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
