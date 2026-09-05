/**
 * A library for (de)serializing LPC data structures to JSON.
 * Copied from Lost Souls.
 *
 * @alias JSONLib
 */
#pragma no_clone

/**
 * json.c
 *
 * LPC support functions for JSON serialization and deserialization.
 * Attempts to be compatible with reasonably current FluffOS and LDMud
 * drivers, with at least a gesture or two toward compatibility with
 * older drivers.
 *
 * Web site for updates: http://lostsouls.org/grimoire_json
 *
 * mixed json_decode(string text)
 *     Deserializes JSON into an LPC value.
 *
 * string json_encode(mixed value)
 *     Serializes an LPC value into JSON text.
 *
 * v1.0: initial release
 * v1.0.1: fix for handling of \uXXXX on MudOS
 * v1.0.2: define array keyword for LDMud & use it consistently
 *
 * LICENSE
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Thaumatic Systems, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifdef MUDOS
#define strstr                      strsrch
#define raise_error                 error
#define member(x, y)                member_array(y, x)
#define to_string(x)                ("" + (x))
#else // MUDOS
#include <sys/lpctypes.h>
#define replace_string(x, y, z)     implode(explode((x), (y)), (z))
#define in                          :
#ifndef array
#define array                       *
#endif // !array
#endif // MUDOS

#define JSON_DECODE_PARSE_TEXT      0
#define JSON_DECODE_PARSE_POS       1
#define JSON_DECODE_PARSE_LINE      2
#define JSON_DECODE_PARSE_CHAR      3

#define JSON_DECODE_PARSE_FIELDS    4

private mixed json_decode_parse_value(mixed array parse);
private varargs mixed json_decode_parse_string(mixed array parse, int initiator_checked);

private void json_decode_parse_next_char(mixed array parse) {
    parse[JSON_DECODE_PARSE_POS]++;
    parse[JSON_DECODE_PARSE_CHAR]++;
}

private void json_decode_parse_next_chars(mixed array parse, int num) {
    parse[JSON_DECODE_PARSE_POS] += num;
    parse[JSON_DECODE_PARSE_CHAR] += num;
}

private void json_decode_parse_next_line(mixed array parse) {
    parse[JSON_DECODE_PARSE_POS]++;
    parse[JSON_DECODE_PARSE_LINE]++;
    parse[JSON_DECODE_PARSE_CHAR] = 1;
}

private int json_decode_hexdigit(int ch) {
    switch(ch) {
    case '0'    :
        return 0;
    case '1'    :
    case '2'    :
    case '3'    :
    case '4'    :
    case '5'    :
    case '6'    :
    case '7'    :
    case '8'    :
    case '9'    :
        return ch - '0';
    case 'a'    :
    case 'A'    :
        return 10;
    case 'b'    :
    case 'B'    :
        return 11;
    case 'c'    :
    case 'C'    :
        return 12;
    case 'd'    :
    case 'D'    :
        return 13;
    case 'e'    :
    case 'E'    :
        return 14;
    case 'f'    :
    case 'F'    :
        return 15;
    }
    return -1;
}

private varargs int json_decode_parse_at_token(mixed array parse, string token, int start) {
    int i, j;
    for(i = start, j = strlen(token); i < j; i++)
        if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS] + i] != token[i])
            return 0;
    return 1;
}

private varargs void json_decode_parse_error(mixed array parse, string msg, int ch) {
    if(ch)
        msg = sprintf("%s, '%c'", msg, ch);
    msg = sprintf("%s @ line %d char %d\n", msg, parse[JSON_DECODE_PARSE_LINE], parse[JSON_DECODE_PARSE_CHAR]);
    raise_error(msg);
}

private mixed json_decode_parse_object(mixed array parse) {
    mapping out = ([]);
    int done = 0;
    mixed key, value;
    int found_non_whitespace, found_sep, found_comma;
    json_decode_parse_next_char(parse);
    if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]] == '}') {
        done = 1;
        json_decode_parse_next_char(parse);
    }
    while(!done) {
        found_non_whitespace = 0;
        while(!found_non_whitespace) {
            switch(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]]) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
#ifdef MUDOS
            case 0x0c   :
#else // MUDOS
            case '\f'   :
#endif // MUDOS
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                found_non_whitespace = 1;
                break;
            }
        }
        key = json_decode_parse_string(parse);
        found_sep = 0;
        while(!found_sep) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ':'    :
                found_sep = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
#ifdef MUDOS
            case 0x0c   :
#else // MUDOS
            case '\f'   :
#endif // MUDOS
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        value = json_decode_parse_value(parse);
        found_comma = 0;
        while(!found_comma && !done) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ','    :
                found_comma = 1;
                json_decode_parse_next_char(parse);
                break;
            case '}'    :
                done = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
#ifdef MUDOS
            case 0x0c   :
#else // MUDOS
            case '\f'   :
#endif // MUDOS
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        out[key] = value;
    }
    return out;
}

private mixed json_decode_parse_array(mixed array parse) {
    mixed array out = ({});
    int done = 0;
    int found_comma;
    json_decode_parse_next_char(parse);
    if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]] == ']') {
        done = 1;
        json_decode_parse_next_char(parse);
    }
    while(!done) {
        mixed value = json_decode_parse_value(parse);
        found_comma = 0;
        while(!found_comma && !done) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ','    :
                found_comma = 1;
                json_decode_parse_next_char(parse);
                break;
            case ']'    :
                done = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
#ifdef MUDOS
            case 0x0c   :
#else // MUDOS
            case '\f'   :
#endif // MUDOS
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        out += ({ value });
    }
    return out;
}

private varargs mixed json_decode_parse_string(mixed array parse, int initiator_checked) {
    int esc_state;
    string out = "";
    if(!initiator_checked) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        if(!ch)
            json_decode_parse_error(parse, "Unexpected end of data");
        if(ch != '"')
            json_decode_parse_error(parse, "Unexpected character", ch);
    }
    json_decode_parse_next_char(parse);
    esc_state = 0;
    while(1) {
        int char = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        if (!char) {
            json_decode_parse_error(parse, "Unexpected end of data");
        } else if (esc_state) {
            switch(char) {
            case '\\'       :
                out += "\\";
                break;
            case '"'        :
                out += "\"";
                break;
            case 'b'        :
                out += "\b";
                break;
            case 'f'        :
#ifdef MUDOS
                out += "\x0c";
#else // MUDOS
                out += "\f";
#endif // MUDOS
                break;
            case 'n'        :
                out += "\n";
                break;
            case 'r'        :
                out += "\r";
                break;
            case 't'        :
                out += "\t";
                break;
            case 'u'        :
                string hex = parse[JSON_DECODE_PARSE_TEXT]
                                  [parse[JSON_DECODE_PARSE_POS] + 1..
                                   parse[JSON_DECODE_PARSE_POS] + 5];
                int array nybbles = allocate(4);
                int array bytes = allocate(2);
                for(int k = 0; k < 4; k++)
                    if((nybbles[k] = json_decode_hexdigit(hex[k])) == -1)
                        json_decode_parse_error(parse, "Invalid hex digit", hex[k]);
                bytes[0] = (nybbles[0] << 4) | nybbles[1];
                bytes[1] = (nybbles[2] << 4) | nybbles[3];
                if(member(bytes, 0) != -1)
                    bytes -= ({ 0 });
#ifdef MUDOS
                out = sprintf("%s%@c", out, bytes);
#else // MUDOS
                out += to_string(bytes);
#endif // MUDOS
                json_decode_parse_next_chars(parse, 4);
                break;
            default:
                out = sprintf("%s%c", out, char);
                break;
            }
            esc_state = 0;
        } else {
            switch(char) {
            case '\\'       :
                esc_state = 1;
                break;
            case '"'        :
                json_decode_parse_next_char(parse);
                return out;
            default:
                out = sprintf("%s%c", out, char);
                break;
            }
        }
        json_decode_parse_next_char(parse);
    }
    return out;
}

private mixed json_decode_parse_number(mixed array parse) {
    int from = parse[JSON_DECODE_PARSE_POS];
    int to = -1;
    int dot = -1;
    int exp = -1;
    int first_ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
    int ch;
    string number;
    switch(first_ch) {
    case '-'            :
        {
            int next_ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS] + 1];
            if(next_ch != '0')
                break;
            json_decode_parse_next_char(parse);
        }
        // Fallthrough
    case '0'            :
        json_decode_parse_next_char(parse);
        ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        if(ch) {
            if((ch == ',') || (ch == '}')) {
                return 0;
            } else if(ch != '.') {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
            dot = parse[JSON_DECODE_PARSE_POS];
        }
        break;
    }
    json_decode_parse_next_char(parse);
    while(to == -1) {
        ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case '.'        :
            if(dot != -1 || exp != -1)
                json_decode_parse_error(parse, "Unexpected character", ch);
            dot = parse[JSON_DECODE_PARSE_POS];
            json_decode_parse_next_char(parse);
            break;
        case '0'        :
        case '1'        :
        case '2'        :
        case '3'        :
        case '4'        :
        case '5'        :
        case '6'        :
        case '7'        :
        case '8'        :
        case '9'        :
            json_decode_parse_next_char(parse);
            break;
        case 'e'        :
        case 'E'        :
            if(exp != -1)
                json_decode_parse_error(parse, "Unexpected character", ch);
            exp = parse[JSON_DECODE_PARSE_POS];
            json_decode_parse_next_char(parse);
            break;
        case '-'        :
        case '+'        :
            if(exp == parse[JSON_DECODE_PARSE_POS] - 1) {
                json_decode_parse_next_char(parse);
                break;
            }
            // Fallthrough
        default         :
            to = parse[JSON_DECODE_PARSE_POS] - 1;
            if(dot == to || to < from)
                json_decode_parse_error(parse, "Unexpected character", ch);
            break;
        }
    }
    number = parse[JSON_DECODE_PARSE_TEXT][from .. to];
    if(dot != -1 || exp != -1)
        return to_float(number);
    else
        return to_int(number);
}

private mixed json_decode_parse_value(mixed array parse) {
    for(;;) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case 0          :
            json_decode_parse_error(parse, "Unexpected end of data");
        case '{'        :
            return json_decode_parse_object(parse);
        case '['        :
            return json_decode_parse_array(parse);
        case '"'        :
            return json_decode_parse_string(parse, 1);
        case '-'        :
        case '0'        :
        case '1'        :
        case '2'        :
        case '3'        :
        case '4'        :
        case '5'        :
        case '6'        :
        case '7'        :
        case '8'        :
        case '9'        :
            return json_decode_parse_number(parse);
        case ' '        :
        case '\t'       :
        case '\r'       :
            json_decode_parse_next_char(parse);
            break;
#ifdef MUDOS
        case 0x0c       :
#else // MUDOS
        case '\f'       :
#endif // MUDOS
        case '\n'       :
            json_decode_parse_next_line(parse);
            break;
        case 't'        :
            if(json_decode_parse_at_token(parse, "true", 1)) {
                json_decode_parse_next_chars(parse, 4);
                return 1;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        case 'f'        :
            if(json_decode_parse_at_token(parse, "false", 1)) {
                json_decode_parse_next_chars(parse, 5);
                return 0;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        case 'n'        :
            if(json_decode_parse_at_token(parse, "null", 1)) {
                json_decode_parse_next_chars(parse, 4);
                return 0;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        default         :
            json_decode_parse_error(parse, "Unexpected character", ch);
        }
    }
    return 0;
}

private mixed json_decode_parse(mixed array parse) {
    mixed out = json_decode_parse_value(parse);
    for(;;) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case 0          :
            return out;
        case ' '        :
        case '\t'       :
        case '\r'       :
            json_decode_parse_next_char(parse);
            break;
#ifdef MUDOS
        case 0x0c       :
#else // MUDOS
        case '\f'       :
#endif // MUDOS
        case '\n'       :
            json_decode_parse_next_line(parse);
            break;
        default         :
            json_decode_parse_error(parse, "Unexpected character", ch);
        }
    }
    return 0;
}

/**
 * Converts the passed JSON (JavaScript Object Notation; see
 * http://json.org/) string to an LPC value and returns it.
 *
 * The JSON values that map inexactly to LPC are true (which maps to 1), false
 * (which maps to 0) and null (which also maps to 0).  As most JSON platforms
 * use higher-precision floating-point numbers than most LPC platforms, loss
 * of floating-point precision should also be anticipated.  Also, as JSON
 * strings are UTF-8 encoded, an LPC driver which isn't prepared to handle
 * UTF-8 may encounter issues with them.
 *
 * @param  text a string containing valid JSON
 * @return      an LPC value
 */
mixed json_decode(string text) {
    mixed array parse = allocate(JSON_DECODE_PARSE_FIELDS);
    parse[JSON_DECODE_PARSE_TEXT] = text;
    parse[JSON_DECODE_PARSE_POS] = 0;
    parse[JSON_DECODE_PARSE_CHAR] = 1;
    parse[JSON_DECODE_PARSE_LINE] = 1;
    return json_decode_parse(parse);
}

/**
 * Returns a string attempting to represent the passed value in JSON
 * (JavaScript Object Notation; see http://json.org/).
 *
 * The data types which map well from LPC to JSON are single-value mappings
 * with string keys (which are represented as objects), arrays, strings,
 * ints, and floats.
 *
 * Many LPC values, including objects, closures, quoted arrays, and symbols,
 * have no valid JSON representation.  json_encode() uses "null" for these.
 * Non-string mapping keys also have no valid JSON representation; these
 * are skipped.
 *
 * json_encode() represents zero-width mappings as JSON arrays and
 * multivalue mappings as if the value sets were arrays of values.  These
 * representations are inexact and do not result in restoration of the
 * original value via json_decode().
 *
 * If json_encode() encounters a self-referential data structure, it will
 * use "null" for inner references to the structure (instead of recursing
 * infinitely).
 *
 * @param  value    an LPC value to serialize
 * @param  pointers used for recursive calls to keep track of pointers.
 *                  external callers may omit
 * @return          a string containing the JSON respresentation of value
 */
varargs string json_encode(mixed value, mixed array pointers) {
#ifdef MUDOS
    if(undefinedp(value))
        return "null";
    if(intp(value) || floatp(value))
#else // MUDOS
    switch(typeof(value)) {
    case T_NUMBER   :
    case T_FLOAT    :
#endif // MUDOS
        return to_string(value);
#ifdef MUDOS
    if(stringp(value)) {
#else // MUDOS
    case T_STRING   :
#endif // MUDOS
        if(member(value, '"') != -1)
            value = replace_string(value, "\"", "\\\"");
        value = sprintf("\"%s\"", value);
        if(member(value, '\\') != -1) {
            value = replace_string(value, "\\", "\\\\");
            if(strstr(value, "\\\"") != -1)
                value = replace_string(value, "\\\"", "\"");
        }
        if(member(value, '\b') != -1)
            value = replace_string(value, "\b", "\\b");
#ifdef MUDOS
        if(member(value, 0x0c) != -1)
            value = replace_string(value, "\x0c", "\\f");
#else // MUDOS
        if(member(value, '\f') != -1)
            value = replace_string(value, "\f", "\\f");
#endif // MUDOS
        if(member(value, '\n') != -1)
            value = replace_string(value, "\n", "\\n");
        if(member(value, '\r') != -1)
            value = replace_string(value, "\r", "\\r");
        if(member(value, '\t') != -1)
            value = replace_string(value, "\t", "\\t");
        return value;
#ifdef MUDOS
    }
    if(mapp(value)) {
        string out;
        int ix = 0;
        if(pointers) {
            // Don't recurse into circular data structures, output null for
            // their interior reference
            if(member(pointers, value) != -1)
                return "null";
            pointers += ({ value });
        } else {
            pointers = ({ value });
        }
        foreach(mixed k, mixed v in value) {
            // Non-string keys are skipped because the JSON spec requires that
            // object field names be strings.
            if(!stringp(k))
                continue;
            if(ix++)
                out = sprintf("%s,%s:%s", out, json_encode(k, pointers), json_encode(v, pointers));
            else
                out = sprintf("%s:%s", json_encode(k, pointers), json_encode(v, pointers));
        }
        return sprintf("{%s}", out);
    }
#else // MUDOS
    case T_MAPPING  :
        {
#ifdef __LDMUD__
            int width = widthof(value);
#else // __LDMUD__
            int width = get_type_info(value, 1);
#endif // __LDMUD__
            switch(width) {
            case 1      :
                {
                    string out = "";
                    int ix = 0;
                    if(pointers) {
                        // Don't recurse into circular data structures, output null for
                        // their interior reference
                        if(member(pointers, value) != -1)
                            return "null";
                        pointers += ({ value });
                    } else {
                        pointers = ({ value });
                    }
                    foreach(mixed k, mixed v : value) {
                        // Non-string keys are skipped because the JSON spec requires that
                        // object field names be strings.
                        if(!stringp(k))
                            continue;
                        if(ix++)
                            out = sprintf("%s,%s:%s", out, json_encode(k, pointers), json_encode(v, pointers));
                        else
                            out = sprintf("%s:%s", json_encode(k, pointers), json_encode(v, pointers));
                    }
                    return sprintf("{%s}", out);
                }
            default     :
                // Multivalue mappings are represented using arrays for the value sets.
                // This isn't a reversible representation, so it's fairly problematic, but
                // it seems marginally better than just dropping the values on the floor.
                {
                    mixed array values;
                    string out;
                    int ix = 0;
                    if(pointers) {
                        // Don't recurse into circular data structures, output null for
                        // their interior reference
                        if(member(pointers, value) != -1)
                            return "null";
                        pointers += ({ value });
                    } else {
                        pointers = ({ value });
                    }
                    values = allocate(width);
                    foreach(mixed k, mixed v1, mixed v2 : value) {
                        // Non-string keys are skipped because the JSON spec requires that
                        // object field names be strings.
                        if(!stringp(k))
                            continue;
                        values[0] = v1;
                        values[1] = v2;
                        for(int w = 2; w < width; w++)
                            values[w] = value[k, w];
                        if(ix++)
                            out = sprintf("%s,%s:%s", out, json_encode(k, pointers), json_encode(values, pointers));
                        else
                            out = sprintf("%s:%s", json_encode(k, pointers), json_encode(values, pointers));
                    }
                    return sprintf("{%s}", out);
                }
            case 0      :
                break;
            }
        }
#endif // MUDOS
#ifdef MUDOS
    if(arrayp(value))
#else // MUDOS
    case T_POINTER  :
#endif // MUDOS
        {
            string out;
            int ix = 0;
            if(pointers) {
                // Don't recurse into circular data structures, output null for
                // their interior reference
                if(member(pointers, value) != -1)
                    return "null";
                pointers += ({ value });
            } else {
                pointers = ({ value });
            }
            foreach(mixed v in value)
                if(ix++)
                    out = sprintf("%s,%s", out, json_encode(v, pointers));
                else
                    out = json_encode(v, pointers);
            return sprintf("[%s]", out);
        }
#ifndef MUDOS
    }
#endif // !MUDOS
    // Values that cannot be represented in JSON are replaced by nulls.
    return "null";
}