// File: Numbers.h
// Purpose: Turns any int (less than 1 billion) into it's 
//     equivalent string name ( 1 == "one", etc. )
// Credits:
//    23 Apr 98   Cyanide created the file.

#define ONES ({ "","one","two","three","four","five","six", \
             "seven","eight", "nine", "ten", "eleven", "twelve", \
             "thirteen", "fourteen", "fifteen", "sixteen", \
             "seventeen", "eighteen", "ninteen" })
#define TENS ({ "","ten","twenty","thirty","forty","fifty", \
             "sixty","seventy","eighty","ninty" })

string number(int i) {
    string str;

    switch (i) {
    case 0 : str = "zero"; break;
    case 1..19 : str = ONES[i]; break;
    case 20..99 : str = TENS[i/10] + "-" + ONES[i%10];
        break;
    case 100..999 : str = number(i/100)+ " hundred " +
         number(i%100);
        break;
    case 1000..999999 : str = number(i/1000)+ " thousand " +
         number(i%1000);
        break;
    case 1000000..999999999 : str = number(i/1000000)+ 
         " million " + number(i%1000000);
        break;
    default : sscanf(i, "%d", str);
    }

    return str;
}

/* EOF */
