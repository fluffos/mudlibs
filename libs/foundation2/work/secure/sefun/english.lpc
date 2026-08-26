/*    /adm/simul_efun/english.c
 *    from Foundation II
 *    efuns for dealing with the oddity we know as the English language
 *    created by Descartes of Borg 940207
 */

string possessive_noun(mixed val) {
    if(objectp(val)) val = (string)val->GetName();
    else if(!stringp(val)) error("Bad argument 1 to possessive_noun().\n");
    switch(val[strlen(val)-1]) {
        case 'x': case 'z': case 's': return sprintf("%s'", val);
        default: return sprintf("%s's", val);
    }
}

string possessive(mixed val) {
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "his";
        case "female": return "her";
        default: return "its";
    }
}

string nominative(mixed val) {
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "he";
        case "female": return "she";
        default: return "it";
    }
}

string objective(mixed val) {
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "him";
        case "female": return "her";
        default: return "it";
    }
}

string reflexive(mixed val) { return sprintf("%sself", objective(val)); }

#define VOWELS ({"a","e","i","o","u"})

#define ABNORMAL ([ "moose":"moose", "mouse":"mice", "die":"dice", "index":"indices", "human":"humans", "sheep":"sheep", "fish":"fish", "child":"children", "ox":"oxen", "tooth":"teeth", "deer":"deer", "bus":"busses" ])

string pluralize(mixed single) {
    int x, i, y, ind;
    string str, tmp, tmp1;
    string *words;

    if(objectp(single)) {
        if(str = (string)single->query_plural_name()) return str;
        else str = (string)single->GetKeyName();
    }
    else if(stringp(single)) str = (string)single;
    else error("Bad argument 1 to pluralize()");
    if(!str) return str;
    i = sizeof(words = explode(str, " "));
    if(words[0] == "a" || words[0] == "an" || words[0] == "the")
      i = sizeof(words = words[1..(i-1)]);
    if((y=member_array("of", words)) > 0 || (y=member_array("Of",words))>0)
        str = words[ind = y-1];
    else str = words[ind = i-1];
    x = strlen(str);
    if(ABNORMAL[str]) return ABNORMAL[str];
    if(x > 2 && str[x-3..x-1] == "man") {
        words[ind] = str[0..x-3]+"en";
        return implode(words, " ");
      }
    if(x > 1) {
        tmp = str[x-2..x-1];
        switch(tmp) {
            case "ch": case "sh":
              words[ind] = sprintf("%ses", str);
              return implode(words, " ");
            case "ff": case "fe":
              words[ind] = sprintf("%sves", str[0..x-3]);
              return implode(words, " ");
            case "us":
              words[ind] = sprintf("%si", str[0..x-3]);
              return implode(words, " ");
            case "um":
              words[ind] = sprintf("%sa", str[0..x-3]);
              return implode(words, " ");
            case "ef":
              words[ind] = sprintf("%ss", str);
              return implode(words, " ");
        }
    }
    tmp = str[x-1..x-1];
    switch(tmp) {
        case "o": case "x": case "s":
          words[ind] = sprintf("%ses", str);
          return implode(words, " ");
        case "f":
          words[ind] = sprintf("%sves", str[0..x-2]);
          return implode(words, " ");
        case "y":
            if(member_array(str[x-2..x-2],VOWELS)!=-1)
                               words[ind] = sprintf("%ss",str);
            else
            words[ind] = sprintf("%sies", str[0..x-2]);
            return implode(words, " ");
    }
    words[ind] = sprintf("%ss", str);
    return implode(words, " ");
}

string cardinal(int x) {
    string tmp;
    int a;

    if(!x) return "zero";
    if(x < 0) {
        tmp = "negative ";
        x = absolute_value(x);
    }
    else tmp = "";
    switch(x) {
        case 1: return tmp+"one";
        case 2: return tmp+"two";
        case 3: return tmp+"three";
        case 4: return tmp+"four";
        case 5: return tmp+"five";
        case 6: return tmp+"six";
        case 7: return tmp+"seven";
        case 8: return tmp+"eight";
        case 9: return tmp+"nine";
        case 10: return tmp+"ten";
        case 11: return tmp+"eleven";
        case 12: return tmp+"twelve";
        case 13: return tmp+"thirteen";
        case 14: return tmp+"fourteen";
        case 15: return tmp+"fifteen";
        case 16: return tmp+"sixteen";
        case 17: return tmp+"seventeen";
        case 18: return tmp+"eighteen";
        case 19: return tmp+"nineteen";
        case 20: return tmp+"twenty";
        default:
            if(x > 1000000000) return "over a billion";
            else if(a = x /1000000) {
                if(x = x %1000000) 
                  return sprintf("%s million %s", cardinal(a), cardinal(x));
                else return sprintf("%s million", cardinal(a));
            }
            else if(a = x / 1000) {
                if(x = x % 1000) 
                  return sprintf("%s thousand %s", cardinal(a), cardinal(x));
                else return sprintf("%s thousand", cardinal(a));
            }
            else if(a = x / 100) {
                if(x = x % 100) 
                  return sprintf("%s hundred %s", cardinal(a), cardinal(x));
                else return sprintf("%s hundred", cardinal(a));
            }
            else {
                a = x / 10;
                if(x = x % 10) tmp = "-"+cardinal(x);
                else tmp = "";
                switch(a) {
                    case 2: return "twenty"+tmp;
                    case 3: return "thirty"+tmp;
                    case 4: return "forty"+tmp;
                    case 5: return "fifty"+tmp;
                    case 6: return "sixty"+tmp;
                    case 7: return "seventy"+tmp;
                    case 8: return "eighty"+tmp;
                    case 9: return "ninety"+tmp;
                    default: return "error";
                }
            }
    }
}

                
string consolidate(int x, string str) {
    string *words;
    string tmp;
    int i;

    if(x == 1) return str;
    i = sizeof(words = explode(str, " "));
    tmp = lower_case(words[0]);
    if(tmp == "a" || tmp == "an" || tmp == "the" || tmp == "one")
      words = words[1..i-1];
    return sprintf("%s %s", cardinal(x), pluralize(implode(words, " ")));
}
