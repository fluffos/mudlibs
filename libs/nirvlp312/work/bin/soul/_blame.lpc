inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around for someone to blame.$N$\n", "$MN$ glares around as though looking for someone.$N$\n");
       target("You raise your finger and point at #TN#.#RET#You announce, \"I blame you!\"$N$\n", "#MN# raises #MP# finger and points at #TN#.#RET##CMS# announces, \"I blame you!\"$N$\n", "#MN# raises #MP# finger and points at you.#RET##CMS# announces, \"I blame you!\"$N$\n");
       afar("From afar, you blame #TN#.$N$\n", "From afar, you can sense that #MN# blames you.$N$\n");
    }
}

int
cmd_blame(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
