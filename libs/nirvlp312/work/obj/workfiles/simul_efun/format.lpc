/*
 * format sefun for compatibility
 * Rumplemintz
 */

#define TEXT_WIDTH 70

varargs string format(string text, int width) {
    if (width < 0)
        raise_error("Bad width given to format(); must be >= 0.\n");
    return sprintf("%*-=s", width || TEXT_WIDTH, text);
}

