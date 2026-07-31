#!/usr/bin/perl
#
# Script to remove long_night from rooms.
#
#	Daniel Q. Yu 
#	06/19/2001
#

#
# Program usage check
#
if(scalar(@ARGV) < 2 || $ARGV[0] eq '-h' || ($ARGV[0] ne '-d' && $ARGV[0] ne '-f')) {
   &ProgUsage;
}

#
# Check options.
#



sub ProgUsage{
   print("\nUsage: 	remove_long_night.pl [options] file1 file2 file3 ... \n");
   print("   -d	file1, file2 etc are directory names, modify all files under dirs.\n");
   print("   -f	file1, file2 etc are file names, modify those files .\n");
}
