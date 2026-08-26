/* upgrade command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd( string str ) {
  seteuid( geteuid(TP) );
  call_out( (: call_other, "/secure/upgrade", "new_player", TP :), 0 );
  return 1;
} /* cmd() */
