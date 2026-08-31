#include <std.h>

inherit DAEMON;

//trip quotation comments on " when commentLevel == 0
//trip line comments on // when commentLevel <2
//trip block comments on / * when commentLevel <2

//0 for no commenting currently
//1 for quotation comments -- do not continue until a " has been reached
//2 for line comments -- do not continue until a \n has been reached
//3 for block comments -- do not continue until a */ has been reached
int commentLevel;

string* nests = ({ });

//colors that will be used for nesting levels.
//Will be retrieved with
//colorLevels[sizeof(nests)%sizeof(colorLevels)]
string* colorLevels = ({
 "",
 "%^BOLD%^%^RED%^",
 "%^BOLD%^%^BLUE%^",
 "%^BOLD%^%^GREEN%^",
 "%^BOLD%^%^CYAN%^",
 "%^ORANGE%^",
 "%^CYAN%^",
 "%^GREEN%^",
 "%^BOLD%^%^BLACK%^",
 "%^YELLOW%^",
 "%^RED%^",
 "%^BLUE%^",
 "%^BOLD%^",
});

mapping nestOpeners = ([
 "(" : "round",
 "[" : "square",
 "{" : "curly",
]);

mapping nestClosers = ([
 ")" : "round",
 "]" : "square",
 "}" : "curly",
]);

//todo: fix the following:
// /* */ code

string colorNest(string inStr) {
  string outStr = "";
  nests = ({ });

  for(int i = 0; i < sizeof(inStr); i++) {
    //check for beginning of block comments
    if(commentLevel != 3 && i+1 < sizeof(inStr)) {
      if(inStr[i..i] == "//" && inStr[i+1..i+1] == "*") {
	outStr += "//" + "*";
	commentLevel = 3;
	i++;
	continue;
      }
    }

    if(commentLevel) {
      outStr += inStr[i..i];
      if(i+1 == sizeof(inStr)) break;

      //check for end of block comments
      if(commentLevel == 3) {
	if(inStr[i..i] == "*" && inStr[i+1..i+1] == "//") {
	  outStr += "//";
	  commentLevel = 0;
	  continue;
	}
      }

      //check for end of line comments
      else if(commentLevel == 2) {
	if(inStr[i..i+1] == "\n") {
	  outStr += "n";
	  commentLevel = 0;
	  continue;
	}
      }

      //check for end of quote comments
      else {
	if(inStr[i] == '"' ) {
	  commentLevel = 0;
	  continue;
	}
      }

      continue;
    }

    else {
      //no current comment type

      //check for beginning of line/quote comments
      if(commentLevel < 2 && i+1 < sizeof(inStr)) {
	if(inStr[i..i] == "//" && inStr[i+1..i+1] == "//") {
	  commentLevel = 2;
	  outStr += "////";
	  i++;
	  continue;
	}
	if(inStr[i] == '"') {
	  outStr += inStr[i..i];
	  commentLevel = 1;
	  continue;
	}
      }

      //do nested level coloring
      if(nestOpeners[inStr[i..i]]) {
        nests += ({ nestOpeners[inStr[i..i]] });
	outStr += colorLevels[sizeof(nests)%sizeof(colorLevels)];
	outStr += inStr[i..i];
	outStr += "%^RESET%^";
	continue;
      }
      else if(nestClosers[inStr[i..i]]) {
        if(sizeof(nests)<1) { outStr += "\nError. Closing "+nestClosers[inStr[i..i]]+" found where there should be none."; break; }
        if(nests[<1] != nestClosers[inStr[i..i]]) {
          outStr += "\nError. Encountered closing "+nestClosers[inStr[i..i]]+", expected closing "+nests[<1];
	  break;
	}
	outStr += colorLevels[sizeof(nests)%sizeof(colorLevels)];
	outStr += inStr[i..i];
	outStr += "%^RESET%^";
	nests = nests[0..<2];
        continue;
      }
      else outStr += inStr[i..i];
    }

  }

  return outStr;
}
