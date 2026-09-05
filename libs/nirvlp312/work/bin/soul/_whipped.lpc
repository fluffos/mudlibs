inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You slightly cover your mouth and cough $H$*Whipped*$N$#RET#You say, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n", "#MN# slightly covers #MP# mouth and coughs $H$*Whipped*$N$#RET#MN# says, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n");
       target("You look at #TN# and cough $H$*Whipped*$N$#RET#You say, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n", "#MN# looks at #TN# and coughs $H$*Whipped*$N$#RET#MN# says, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n", "#MN# looks at you and coughs $H$*Whipped*$N$#RET#MN# says, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n");
       afar("You look at #TN# from afar and cough $H$*Whipped*$N$#RET#You tell #TN#, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n", "#MN# looks at you from afar and coughs $H$*Whipped*$N$#RET#MN# tells you, \"Oh, excuse me.  Darn allergies.\" $HC$=($N$\n");
    }
}

int
cmd_whipped(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
