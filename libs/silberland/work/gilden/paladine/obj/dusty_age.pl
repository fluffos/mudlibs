#!/usr/bin/perl

use Date::Calc qw(Delta_Days Today); 

$x=Date::Calc::Delta_Days(1977,11,20, Today()); 
open(FILE, ">/mud/mudlib/gilden/paladine/log/dusty_age.txt");
print FILE "$x";
close (FILE);

