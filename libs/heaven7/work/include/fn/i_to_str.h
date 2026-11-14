#ifndef I_TO_STR_H
#define I_TO_STR_H

/* should work well to 999,999 but will bug out at 1.9 million */

string int_to_str(int i) { 
  string str, *units, *tens;
  int unit, ten, hundred, thousand, ten_thousand, hundred_thousand;

  str  = (unit < 0) ? "minus " : "";
  unit = (unit < 0) ? -i : i;

  i = unit; /* in case i is negative */

  units = ({
           "", "one", "two", "three", "four", "five",
           "six", "seven", "eight", "nine", "ten", "eleven",
           "twelve", "thirteen", "fourteen", "fifteen",
           "sixteen", "seventeen", "eighteen", "nineteen",
          });

  tens = ({
           "", "", "twenty", "thirty", "fourty", "fifty",
           "sixty", "seventy", "eighty", "ninety",
         });

  if(unit >= 100000) {
    hundred_thousand = unit/100000;
    unit = unit%100000;
    str += units[hundred_thousand]+" hundred";
  }
  if(unit >= 20000) {
    ten_thousand = unit/10000;
    unit = unit%10000;
    str += ((i >= 100000) ? " and " : "") + tens[ten_thousand];
  }
  if(unit >= 1000) {
    thousand = unit/1000;
    unit = unit%1000;
    str += (i >= 20000 && !ten_thousand) ? " and " : ((ten_thousand)?" ":"");
    str += units[thousand]+" thousand"; 
  }
  if(unit >= 100) {
    hundred = unit/100;
    unit = unit%100;
    str += ((i >= 1000) ? " " : "") + units[hundred]+" hundred";
  }
  if(unit >= 20) {
    ten = unit/10;
    unit = unit%10;
    str += ((i >= 100) ? " and " : "") + tens[ten];
  }
  str += ((i >= 100 && !ten) ? " and " :((ten) ? " " : "")) + units[unit]; 
  if(str == "") str = "no";
  return str;
}       

#endif /* I_TO_STR_H */
