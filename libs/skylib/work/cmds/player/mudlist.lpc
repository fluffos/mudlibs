inherit COMMAND_BASE;

string query_usage() {
  return "mudlist -dimntsS [mud]\n\n"
         "  -d[driver]      Driver filter\n"
         "  -i[ip]          IP filter\n"
         "  -m[mudlib]      Mudlib filter\n"
         "  -n[name]        Name filter\n"
         "  -t[type]        Type filter\n"
         "  -s[status]      Status filter\n"
         "  -S[services]    Available service filter:\n"
         "      a - auth      n - new\n"
         "      A - amcp      N - NNTP\n"
         "      c - channel   P - FTP\n"
         "      e - emote     r - RCP\n"
         "      f - finger    s - SMTP\n"
         "      F - file      t - tell\n"
         "      h - HTTP      u - ucache\n"
         "      l - locate    w - who\n"
         "      m - mail\n";
} /* query_usage() */

int cmd(string arg) {
  mapping flags = ([ ]);
  string *parts, *mud = ({ }), str = ""; 

  notify_fail(query_usage());

  if (!arg) {
    tell_object(TP, INTERMUD_H -> mudlist(mud, flags));  
    return 1;
  }

  // Strip WS
  for (int i = 0; i < strlen(arg); i++)
    if (arg[i] == ' ') {
      if (arg[i + 1] != ' ')
        str += sprintf("%c", arg[i]);
    } else {
      str += sprintf("%c", arg[i]);
    }

  parts = explode(str, " ");

  for (int j = 0; j < sizeof(parts); j++)
    if (parts[j][0] == '-')
      switch (parts[j][1]) {
        default:
          tell_object(TP, "Invalid flag.\n"
                      "Type 'mudlist -h' for help.\n");
          return 1;
        case 'h':  
          return 0;
        case 'd':  case 'i':  case 'm':  
        case 'n':  case 't':  case 's':
          flags[sprintf("%c", parts[j][1])] = parts[j][2..];
          break;
        case 'S':  // Services
          flags["S"] = ({ });

          for (int k = 2; k < sizeof(parts[j]); k++)
            switch (parts[j][k]) {
              default:
                tell_object(TP, "Invalid intermud service specified.\n"
                            "Type 'mudlist -h' for help.\n");
                return 1;
              case 'a':  case 'A':  case 'c':  case 'e':  case 'f':  
              case 'F':  case 'h':  case 'l':  case 'm':  case 'n':
              case 'N':  case 'P':  case 'r':  case 's':  case 't':
              case 'u':  case 'w':
                flags["S"] += ({ sprintf("%c", parts[j][k]) });
            }

          if (!sizeof(flags["S"]))
            map_delete(flags, "S");
      }
    else
      mud += ({ parts[j] });

  tell_object(TP, INTERMUD_H -> mudlist(implode(mud, " "), flags));
  return 1;
} /* cmd() */
