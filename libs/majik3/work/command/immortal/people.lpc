#define pline(x) message("0", x, THIS);

main() {
    object list;
    int i;
    string name, flags, level, room, host;

    list = users();

    pline ("^c0^cW^bb"+
"##. name       level idle hostname                  environment               ^c0\n");

    for(i=0; i<sizeof(list); i++) {
        if (!list[i]->query_name())
          continue;

        if (list[i]->query_name())
        name  = capitalize (list[i]->query_name());
        else
        name  = "-";

        if (!list[i]->query_ident() || list[i]->query_ident() == "unknown")
          host = query_ip_name (list[i]);
        else
          host = list[i]->query_ident() + "@" + query_ip_name (list[i]);

        if (!host)
          host = "-";

        host = replace_string(host, "\n", "");
        host = replace_string(host, "\r", "");
        host = replace_string(host, " ", "");
        host = replace_string(host, "\t", "");

        if (ENV(list[i]))
        room  = file_name (environment (list[i]));
        else
        room  = "-";

        flags = "";
        level = list[i]->query_security();

        if (room[0..6] == "/world/")
          room = "^" + room[7..];
        else if (room[0..5] == "/home/")
          room = "~" + room[6..];

        if (in_edit (list[i]))
          flags += "E";
        if (in_input (list[i]))
          flags += "B";
        if (query_idle (list[i]) >= 5 * 60)
          flags += "I";

        pline (sprintf("^cc%2d^c0. ^c1%-10s^c0 %5d %4d %-25s %-26s\n",
        i+1, lower_case(name[0..9]), level, query_idle (list[i]) ? query_idle (list[i]) / 60 :
        0, host[0..24], room[0..25]));
   }
   pline ("\n" + sizeof(users()) + " players connected.\n");
   return 1;
}
