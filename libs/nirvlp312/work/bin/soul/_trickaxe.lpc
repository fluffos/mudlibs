inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You glance around furtively.#RET#You whisper: \"It's a trick. Get an axe.\"$N$\n", "#MN# glances around furtively.#RET##MN# whispers: \"It's a trick. Get an axe.\"$N$\n");
       target("You stare deep into #TN#'s soul...#RET#You whisper: \"It's a trick. Get an axe.\"$N$\n", "#MN# stares deep into #TN#'s soul...#RET##MN# whispers: \"It's a trick. Get an axe.\"$N$\n", "#MN# stares deep into your soul...#RET##MN# whispers: \"It's a trick. Get an axe.\"$N$\n");
       afar("You shout to #TN# from afar: \"IT'S A TRICK! GET AN AXE!!!!\"$N$\n", "#MN# shouts to you from afar: \"IT'S A TRICK! GET AN AXE!!!!\"$N$\n");
    }
}

int
cmd_trickaxe(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
