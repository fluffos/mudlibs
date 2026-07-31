#!/usr/bin/perl
foreach $key (sort keys %ENV) {
#	print "$key:    ".$EVN{$key}."\n";
}

open (WHO,"who|");
while (<WHO>) {
    unless (/fred/) { # don't show fred
        print $_;
    }
}
close WHO;

if (!(defined($child_pid = fork()))) {
	die ("Cannot fork $! \n");
} elsif ($child_pid){
	exec ("date");
	die ("Cannot execute date $!");
}else{
	waitpid($child_pid,0);
}