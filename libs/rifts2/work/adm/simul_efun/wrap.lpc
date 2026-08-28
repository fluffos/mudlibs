// A colour-sensitive wrap function from Beek.
// Modded by Diewarzau on 5/27/96

varargs string wrap(string str, int width, int indent) {
    int i, x, count, offset;
    int space = -1;
    string ret = "";
 
    if (!width)
        width = 75;

    x = strlen(str);
    for (i = 0; i < x; i++) {
        switch (str[i]) {
        case ' ':
            space = i;
            break;
        case '%':
            if (i != x - 1 && str[i + 1] == '^') {
                int stop = strsrch(str[i + 2..], "%^");
 
                if (stop != -1 && strsrch(str[i + 2..stop - 1], "\n") == -1) {
                    i += stop + 3;
                    continue;
                }
            }
            break;
        case '\n':
            ret += str[offset..i];
            if (i != x - 1) {
                count = indent;
                space = -1;
                if (indent)
                    ret += sprintf("%*s", indent, "");
            }
            offset = i + 1;
            continue;
        }
        if (count == width) {
            if (space == -1) {
                ret +=
                str[offset..i - 1] + sprintf("\n%*s%s", indent, "", str[i..i]);
            }
            else {
                ret +=
                str[offset..space - 1] + sprintf("\n%*s", indent, "");
                while (space < x && str[space] == ' ')
                    space++;
                i = space - 1;
            }
            count = indent;
            offset = i + 1;
            space = -1;
            continue;
        }
        count++;
    }
    return ret + str[offset..] + "\n";
}
