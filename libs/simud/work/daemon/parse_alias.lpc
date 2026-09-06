/** A single function, parse_alias, used to handle complex alias
 * types. This code is from wallowing.whatever.net.au 2000
 * (Thanks Stormdragon), slightly modified by Acius.
 */

/** Converts the command in \a com according to the
 * alias templated in \a str into a normal command
 * string. Substring substitution with $1, $2, $* or
 * $ARG1, $ARG2, $ARG* etc. is possible.
 *
 * If query_verb() is for some reason invalid, you may
 * pass a verb in as the optional third parameter.
 */
varargs string parse_alias(string str, string com, string verb) {
  string *bits, *args, rest, out;
  int i,n, arg_num, high_arg;
  status dollar, args_used;

  if( !verb ) verb = query_verb();

  str = implode( explode(str, "$"), "~ARG" );
  bits = explode(str, "~ARG");
  if( sizeof(bits) == 1 ) return str + (com?" "+com:"");
  if (!com)
    args = ({});
  else
    args = explode(com, " ");
  out = "";
  high_arg = -1;
  n = sizeof(bits);
  if (bits[0]=="") {
    if (n<2) {
      return str;
    }
    bits = bits[1..];
    n--;
  }
  for(i=0;i<n;i++) {
    if (!strlen(bits[i])) {
      if (dollar) {
        bits[i]="~ARG";
        dollar = 0;
      }
      else
        dollar = 1;
    }
    else {
      if (dollar) {
        msg("~CWRNalias error~CDEF: Your alias contains an unnumbered ~ARG or $.",13);
        return 0;
      }
      if (bits[i][0]=='*') {
        args_used = 1;
        out += implode(args[(high_arg+1)..], " ");
        bits[i]=bits[i][1..];
      }
      else if (sscanf(bits[i], "%d%s", arg_num, rest) == 2) {
        if (!arg_num)
          out += verb;
        else {
          if (arg_num > sizeof(args)) {
            msg("~CWRNalias error~CDEF: Your alias asks for argument number "+arg_num+", but your command only gives "+sizeof(args)+".",13);
            return 0;
          }
          arg_num--;
          if (arg_num < 0) {
            msg("~CWRNalias error~CDEF: You specified a negative argument index "+arg_num+".",13);
            return 0;
          }
          if (arg_num > high_arg)
            high_arg = arg_num;
          out+=args[arg_num];
          bits[i]=rest;
        }
      }
    }
    if (strlen(bits[i])) {
      out+=bits[i];
    }
  }
  if (dollar) {
    msg("~CWRNalias error~CDEF: Your alias contains an unnumbered ~ARG or $.",13);
    return 0;
  }
  if ((high_arg < (sizeof(args)-1)) && !args_used) {
    if (sizeof(args[(high_arg+1)..]))
      out = implode( ({ out }) + args[(high_arg+1)..], " ");
  }
  return out;
}
