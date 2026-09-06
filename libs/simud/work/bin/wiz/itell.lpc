#define INTERMUD3   "/secure/sockets/i3/intermud3"

int main(string str)
{
    int sanity = 0;
    string mud, it, real_mud, ukmud;
    if (!str || (sscanf(str, "%s@%s: %s", it, mud, str) != 3 && sscanf(str, "%s@%s %s", it, mud, str) != 3) )
        return 0;
    ukmud = mud;
    real_mud = INTERMUD3 -> get_mud_name(mud);
    while (!real_mud && sanity++ < 30) {
        mud += "."+explode(str," ")[0];
        str = implode(explode(str," ")[1..]," ");
        real_mud = INTERMUD3 -> get_mud_name(mud);
    }
    if (!real_mud) {
        msg("Unknown mud: " + ukmud + "\n");
   return 1;
    }
    if (!str) {
        msg("Silly, you need to tell me what to tell them :P");
    }
    if (!INTERMUD3 -> query_mud_info(real_mud)[11]["tell"]) {
        msg(real_mud + " does not support intermud tells.\n");
   return 1;
    }
    INTERMUD3 -> send_tell(it, real_mud, str);
    write("Ok.\n");
    return 1;
}

