inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stick your arms out and run around the room making engine noises.\n", "#MN# sticks #MP# arms out and runs around the room making engine noises.\n");
       target("You stick your arms out and annoyingly run around #TN# making engine noises.\n", "#MN# sticks #MP# arms out and annoyingly runs around #TN# while making engine noises.\n", "#MN# sticks his arms out and annoyingly runs around you while making engine noises.\n");
       afar("You stick out your arms and start to make engine noises.\n\Yeah... right.\n", "0\n");
    }
}

int
cmd_airplane(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
