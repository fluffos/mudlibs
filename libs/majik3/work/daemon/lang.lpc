/* English-language-daemon

    Author: Alcal, 11. Jan 1998
*/
string *ones = ({ "zero", "one", "two", "three", "four", "five", "six", "seven",
  "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", });
string *tens = ({ "twenty", "thirty", "fourty", "fifty", "sixty", "seventy",
  "eighty", "ninety" });
mixed *bigs = ({
  ({ 1000000000, "billion" }),
  ({ 1000000, "million" }),
  ({ 1000, "thousand" }),
  ({ 100, "hundred" }),
});

string literate(int n) {
  string s;
  string *parts;
  int i;

  parts = ({ });

  if (n < 0) return "minus " + literate(-n);
  if (n < sizeof(ones)) return ones[n];

  for(i = 0; i < sizeof(bigs); i++) {
    if (n >= bigs[i][0]) {
      parts += ({ literate(n/bigs[i][0]) + " " + bigs[i][1] });
      n = n%bigs[i][0];
    }
  }

  if (n >= 20) {
    if (n%10 == 0) parts += ({ tens[(n/10) - 2] });
    else parts += ({ tens[(n/10) - 2] + "-" + literate(n%10) });

    n = 0;
  }

  if (n) parts += ({ literate(n) });

  if (sizeof(parts) == 0) return "(nan)";
  return implode(parts, ", ", " and ");
}

int main(string args) {
  int i;

  if (!args) return 0;

  sscanf(args, "%d", i);

  message("debug", literate(i) + "\n", THIS);
  return 1;
}
