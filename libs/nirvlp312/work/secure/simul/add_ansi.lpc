#include "/include/ansi.h"

string ansi_extract(string str, int from, int to) {
  string tmp, runner, rest;
  int total;

  runner = str + "";
  total = 0;
  while(sscanf(runner, "%s" + ESC + "%sm%s", runner, tmp, rest) == 3) {
    runner += rest;
    total += strlen(ESC) + strlen(tmp) + 1;
  }
  return str[from..to+total] + OFF;
}

int add_ansi(string msg) {
  string tmp, runner, rest;
  int total;

  runner = msg + "";
  total = 0;
  while(sscanf(runner, "%s" + ESC + "%sm%s", runner, tmp, rest) == 3) {
    runner += rest;
    total += strlen(ESC) + strlen(tmp) + 1;
  }
  return total;
}

