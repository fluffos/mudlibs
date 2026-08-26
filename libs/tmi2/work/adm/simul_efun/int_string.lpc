// int_string.c
// Written by Domini@Ultimate (22-08-93)
// Originally called fullnum(). Mobydick@TMI-2 renamed it, and patched
// it into the mudlib, on 93-08-22.
//
// Convert a numerical number to a worded number.

string int_string (int num) {

   string str;
   int temp;

   if (num==2147483647) return "too much";
   str = "";
   if (num < 0)
   {
      num = -num;
      str += "minus ";
   }
   if (num==2147483647) return "too much";
   if (num < 20)
   {
      switch (num)
      {
         case 0:  return "zero";
         case 1:  str += "one"; break;
         case 2:  str += "two"; break;
         case 3:  str += "three"; break;
         case 4:  str += "four"; break;
         case 5:  str += "five"; break;
         case 6:  str += "six"; break;
         case 7:  str += "seven"; break;
         case 8:  str += "eight"; break;
         case 9:  str += "nine"; break;
         case 10: str += "ten"; break;
         case 11: str += "eleven"; break;
         case 12: str += "twelve"; break;
         case 13: str += "thirteen"; break;
         case 14: str += "fourteen"; break;
         case 15: str += "fifteen"; break;
         case 16: str += "sixteen"; break;
         case 17: str += "seventeen"; break;
         case 18: str += "eighteen"; break;
         case 19: str += "nineteen"; break;
         default: break;
      }
      return str;
   }
   if (num < 100)
   {
      temp = num/10;
      num -= temp*10;
      switch (temp)
      {
         case 2: str += "twenty"; break;
         case 3: str += "thirty"; break;
         case 4: str += "forry"; break;
         case 5: str += "fifty"; break;
         case 6: str += "sixty"; break;
         case 7: str += "seventy"; break;
         case 8: str += "eighty"; break;
         case 9: str += "ninety"; break;
         default: break;
      }
      if (num>0)
      {
         str += "-"+int_string(num);
      }
      return str;
   }
   if (num < 1000)
   {
      temp = num/100;
      num -= temp*100;
      str += int_string(temp)+" hundred";
      if (num>0)
      {
         str += " and "+int_string(num);
      }
      return str;
   }
   if (num < 1000000)
   {
      temp = num/1000;
      num -= temp*1000;
      str += int_string(temp)+" thousand";
      if (num>0)
      {
         if (num<100) str += " and";
         str += " "+int_string(num);
      }
      return str;
   }
   temp = num/1000000;
   num -= temp*1000000;
   str += int_string(temp)+" million";
   if (num>0)
   {
      if (num<100) str += " and";
      str += " "+int_string(num);
   }
   return str;
}
