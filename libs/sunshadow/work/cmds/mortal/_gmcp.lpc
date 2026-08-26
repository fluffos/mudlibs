// A simple command to check your GMCP status
// Might later be used to configure GMCP settings, if not done over GMCP
// By Spade, 22 July 2022

int cmd_gmcp(string str)
{
    object me = this_player();

    message("info", "Your GMCP status is: " + me->query_gmcp_enabled(), me);

    return 1;
}