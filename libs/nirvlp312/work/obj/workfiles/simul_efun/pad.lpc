/*
 * pad sefun for compatibility
 * Rumplemintz
 */

varargs string pad(mixed str, int len, int padchar) {
    string sp_format;

    str = to_string(str);

    if (!padchar) padchar = 32;

    if (len < 0) {
        if (padchar) {
            sp_format = "%' '*.*s";
            sp_format[2] = padchar;
            return sprintf(sp_format, -len, -len, str);
        }
        return sprintf("%*.*s", -len, -len, str);
    }
    if (padchar) {
        sp_format = "%' '-*.*s%s";
        sp_format[2] = padchar;
        return sprintf(sp_format, len, len, str, "");
    }
    return sprintf("%-*.*s%s", len, len, str, "");
}

