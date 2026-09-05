inherit "/bin/std";

void
reset(int x)
{
    if(!x)
    {
      ::reset();
      nontarget("You ack.\n", "#MN# acks.\n");
      target("You ack at #TN#.\n", "#MN# acks at #TN#.\n", "#MN# acks at you.\n");
      afar("You ack at #TN# from afar.\n", "#MN# acks at you from afar.\n");
    }
}

int
cmd_ack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
