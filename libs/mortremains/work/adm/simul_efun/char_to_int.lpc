// This function takes a string of a numeral, and turns it into
// the appropriate single digit.  Non-integers return 0, and
// multiple characters return only the first digit. Negative
// integers are supported.
// Pretty much useless, but vital for the atoi() function that
// Cyanide ressurected on 8 Jul 97.
// This was also written by Cyanide@Nightfall's Keep, 9 July 1997

int char_to_int (string char) {
  int numb = 1;


  if (strlen(char) > 1) {
    if (char[0..0]=="-") {
      numb = -1;
      char = char[1..1];
    } else {
      char = char[0..0];
    }
  }

  switch (char) {
    case "0" : numb*=0; break;
    case "1" : numb*=1; break;
    case "2" : numb*=2; break;
    case "3" : numb*=3; break;
    case "4" : numb*=4; break;
    case "5" : numb*=5; break;
    case "6" : numb*=6; break;
    case "7" : numb*=7; break;
    case "8" : numb*=8; break;
    case "9" : numb*=9; break;
    default: numb*=0; break;
  }


  return numb;
}              
