/**
 * The header file for newspapers.
 * Classes, and so forth.
 */

class issue {
  string *pages;
  int sold;
}

class paper {
  string name;
  int inception;
  string *owners;
  string *members;
  class issue *issues;
}