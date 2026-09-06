#define INTERMUD3       "/secure/sockets/i3/intermud3"

int main(string str)
{
    string it;
    if (!str) {
        msg("Which mud do you want to know about? (Type ~CCOMimuds~CDEF for a list.)");
        return 1;
    }

    it = INTERMUD3 -> get_mud_name(str);
    if (!it) {
	msg("Unknown mud: " + str);
        return 1;
    }
    if (!INTERMUD3 -> query_mud_info(it)[11]["who"]) {
        msg(it + " does not support rwho.");
	return 1;
    }

    INTERMUD3->send_who_request(it);
    write("Request transmitted.\n");
    return 1;
}
