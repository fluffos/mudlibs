inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout, \"Motherfucker, I'm awesome!\"#RET#Nirvana responds, \"No you're not dude, don't lie!\"\n", "#MN# shouts, \"Motherfucker, I'm awesome!\"#RET#Nirvana responds, \"No you're not dude, don't lie!\"\n");
       target("You shout at #TN#, \"Motherfucker, I'm awesome!\"#RET##TN# responds, \"No you're not dude, don't lie!\"$N$\n", "#MN# shouts at #TN#, \"Motherfucker, I'm awesome!\"#RET##TN# responds, \"No you're not dude, don't lie!\"$N$\n", "#MN# shouts at you, \"Motherfucker, I'm awesome!\"#RET#You respond, \"No you're not dude, don't lie!\"$N$\n");
       afar("From afar, you shout at #TN#, \"Motherfucker, I'm awesome!\"#RET##TN# responds, \"No you're not dude, don't lie!\"$N$\n", "From afar, #MN# shouts at you, \"Motherfucker, I'm awesome!\"#RET#You respond, \"No you're not dude, don't lie!\"$N$\n");
    }
}

int
cmd_spose(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
