inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: \"BOO-YA!\"$N$\n", "#MN# goes: \"BOO-YA!\"$N$\n");
       target("You get into #TN#'s face and go: \"BOO-YA!\"$N$\n", "#MN# gets into #TN#'s face and goes: \"BOO-YA!\"$N$\n", "#MN# gets into your face and goes: \"BOO-YA!\"$N$\n");
       afar("From afar, You get into #TN#'s face and go: \"BOO-YA!\"$N$\n", "From afar, #MN# gets into your face and goes: \"BOO-YA!\"$N$\n");
    }
}

int
cmd_booya(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
