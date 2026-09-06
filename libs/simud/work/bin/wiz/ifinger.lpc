#define INTERMUD3       "/secure/sockets/i3/intermud3"

int main(string str)
{
    string who, it;
    if (!str || sscanf(str, "%s@%s", who, str) != 2) {
        msg("Correct format is ~CCOMifinger <who>@<mud>~CDEF.");
        return 1;
    }
    it = INTERMUD3 -> get_mud_name(str);
    if (!it) {
        msg("Unknown mud: " + str);
	return 1;
    }
    if (!INTERMUD3 -> query_mud_info(it)[11]["finger"]) {
        msg(str + " does not support intermud finger.\n");
	return 1;
    }
    INTERMUD3 -> send_finger_request(who, it);
    write("Request transmitted.\n");
    return 1;
}
