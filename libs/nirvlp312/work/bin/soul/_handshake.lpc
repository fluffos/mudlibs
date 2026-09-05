inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your hands out.\n", "#MN# shakes out #MP# hands.\n");
       target("You shake #TN#'s hand.\n", "#MN# shakes #TN#'s hand.\n", "#MN# shakes your hand.\n");
       afar("You shake #TN#'s hand from afar.\n", "#MN# shakes your hand from afar.\n");
    }
}

int
cmd_handshake(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
