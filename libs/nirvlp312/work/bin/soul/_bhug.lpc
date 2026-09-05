inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You give yourself a giant bearhug!#RET#You gasp for air!$N$\n", "#MN# gives #MO#self a giant bearhug!#RET##CMN# gasps for air!$N$\n");
       target("You give #TN# a giant bearhug!#RET##CTN# gasps for air!$N$\n", "#MN# gives #TN# a giant bearhug!#RET##CTN# gasps for air!$N$\n", "#MN# gives you a giant bearhug!#RET#You gasp for air!$N$\n");
       afar("You give #TN# a giant bearhug from afar!#RET#You make #TN# gasp for air from afar!$N$\n", "#MN# gives you a giant bearhug from afar!#RET##CMN# makes you gasp for air from afar!$N$\n");
    }
}

int
cmd_bhug(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
