#!/usr/bin/perl

$foo = @ARGV[0];

# first read the file, I am too lazy to use temp files.
open (IN, $foo);
while (<IN>) {
  # I assume all "*"'s in the line with the action are to be removed, 
  # or rather, the first one, not the possible comment.
  if (/add_action/) {
    s/\*//;
    print;
  }
  push @file, $_;
}
close (IN);

open (OUT, ">$foo");
foreach (@file) {
  print OUT;
}
close (OUT);
