inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"It must be inordinately taxing to be such a boob.\"$N$\n", "#MN# says, \"It must be inordinately taxing to be such a boob.\"$N$\n");
       target("You say, \"#TN#, it must be inordinately taxing to be such a boob.\"#RET##TN# agrees, \"You have no idea.\"$N$\n", "#MN# says, \"#TN#, it must be inordinately taxing to be such a boob.\"#RET##TN# agrees, \"You have no idea.\"$N$\n", "#MN# says, \"#TN#, it must be inordinately taxing to be such a boob.\"#RET##You agree, \"You have no idea.\"$N$\n");
       afar("From afar, you comment to #TN#, \"It must be inordinately taxing to be such a boob.\"#RET##TN# agrees, \"You have no idea.\"$N$\n", "From afar, #MN# comments, \"It must be inordinately taxing to be such a boob.\"#RET##You agree, \"You have no idea.\"$N$\n");
    }
}

int
cmd_boob(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
