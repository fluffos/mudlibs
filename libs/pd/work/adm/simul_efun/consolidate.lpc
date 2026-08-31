#define NUMBER ({ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" })

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
                  return sprintf("%s million %s", cardinal(a),cardinal(x));
                else return sprintf("%s million", cardinal(a));
            }
            else if(a = x / 1000) {
                if(x = x % 1000)
                  return sprintf("%s thousand %s", cardinal(a),cardinal(x));
                else return sprintf("%s thousand", cardinal(a));
            }
            else if(a = x / 100) {
                if(x = x % 100)
                  return sprintf("%s hundred %s", cardinal(a),cardinal(x));
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
    string tmp, atmp;
    string *words;
    int i, y;

    if(x==1 || !str || str == "") return str;
    i = sizeof(words = explode(str, " "));
    if (words[i-1][0]=='(')
     {
      atmp = words[i-1];
      words[i-1]="";
      i -=1;
     }

    if((tmp = lower_case(words[0])) == "a" || tmp == "an" || tmp =="the")
      i = sizeof(words = words[1..i-1]);
    if((y=member_array("of", words))  > 0)
        words[y-1] = pluralize(words[y-1]);
    else words[i-1] =  pluralize(words[i-1]);
    tmp = cardinal(x)+" ";

if (atmp)
     return tmp+implode(words, " ")+" "+atmp;
   return tmp+implode(words, " ");
}

string *consolidate_string(string *str)
{
 mapping inv=([]);
 string *out=({}), *key;
 int i;
  
//  if (!str || str = ({})) return ({});
//  if (!i = sizeof(str))   return ({});
  i = sizeof(str);
  while(i--)
   {
    if (!inv[ str[i] ])
      inv[ str[i] ] = 1;
     else
      inv[ str[i] ]++;
   }
  key = keys(inv);
  i = sizeof(key);
  while(i--)
  out += ({ consolidate( inv[ key[i] ], key[i] ) });
 
 return out;
}
