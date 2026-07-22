#!/usr/bin/perl
#
# Script to find a string from files
#
#       - Daniel Q. Yu
#         07/02/2001
#

#
# Program usage check
#
if(scalar(@ARGV) < 2 || $ARGV[0] eq '-h') {
   &ProgUsage;
}

#
# Check options.
#
$SEARCH_STR = $ARGV[0];
$ROOTDIR = $ARGV[1];
$CHANGE_TO = $ARGV[2];
$LAST_CHANGE = "";
$CURRENT_DIR = "";
$NEXT_DIR = 0;

if($ARGV[3] eq "-y") {
	$AUTO_CONF = 1;
} else {
	$AUTO_CONF = 0;
}

if(-d $ROOTDIR) {
   &searchDir($SEARCH_STR, $ROOTDIR);
}

sub searchDir() {
   my($s_s, $s_d) = @_;
   opendir(DIR, $s_d);
   my @dirList = readdir(DIR);
   close(DIR);
   $NEXT_DIR = 0;
   $CURRENT_DIR = $s_d;
   foreach $file (sort sortDir @dirList) {
	  if($file ne "." && $file ne "..") {
		 $file = "$s_d/$file";
		 if(-d $file) {
			&searchDir($s_s, $file);
                        $CURRENT_DIR = $s_d;
		 } else {
		     &searchFile($s_s, $file);
                     if($NEXT_DIR == 1) {
                        return;
                     }
		 }
	  }
   }
}

sub searchFile() {
   my($s_s, $s_f) = @_;
   open(IN, "$s_f");
   my @LINES = <IN>;
   close(IN);
   my $changed  = 0;
   my $conf = "";
   for(my $i=0; $i<scalar(@LINES); $i++) {
	  if($LINES[$i] =~ /$s_s/) {
		 print("\n\n$s_f \n");
		 if($i - 3 >= 0) {
			print("    $LINES[$i-3]"); 
			print("    $LINES[$i-2]"); 
			print("    $LINES[$i-1]"); 
		 } elsif($i - 2 >= 0) {
			print("    $LINES[$i-2]"); 
			print("    $LINES[$i-1]"); 
		 } elsif($i - 1 >= 0) {
			print("    $LINES[$i-1]"); 
		 }
		 print("--> $LINES[$i]");
		 if($i + 1 < scalar(@LINES)) {
			print("    $LINES[$i + 1]");
		 }
		 if($i + 2 < scalar(@LINES)) {
			print("    $LINES[$i + 2]");
		 }
		 if($i + 3 < scalar(@LINES)) {
			print("    $LINES[$i + 3]");
		 }
		 if($CHANGE_TO ne "") {
			$newLine = $LINES[$i];
			$newLine =~ s/$s_s/$CHANGE_TO/g;
			print("\nTO:  $newLine"); 
			if($AUTO_CONF != 1) {
				print("\nDO YOU WANT TO CHANGE (y/N/o/a/l/nd) ?\n===> ");
				$conf = <STDIN>;
				chop($conf);
                                if($conf eq "nd") {
                                    $NEXT_DIR = 1;    
                                    return;
				} elsif($conf    eq "y" || $conf eq "Y") {
					$LINES[$i] = $newLine;
					$changed = 1;
					print("CHANGES CONFIRMED!\n");
					$LAST_CHANGE = $newLine;
				}  elsif($conf eq "o" || $conf eq "O" || $conf eq "a" || $conf eq "A") {
					my $conf2   = "n";
					my $newText = "";
					if($conf ne "a" && $conf ne "A") {  
						$newLine =  "";
					}
					while($conf2 eq "n" || $conf2   eq "N") {
						print("\nENTER TEXT FOR THIS LINE:\n");
						do {
							if($newText ne "") {
								$newLine = "$newLine$newText\n";
							}
							print("===> ");
							$newText = <STDIN>;
							chop($newText);
						} while ($newText ne "");
						print("\nTO:  $newLine\nIS  THIS OK (y/N/q)?\n===> ");
						$conf2 = <STDIN>;
						chop($conf2);
					}
					if($conf2 eq "y" || $conf2 eq "Y") {
						$LINES[$i]  = $newLine;
						$changed =  1;
						print("CHANGES  CONFIRMED!\n");
						$LAST_CHANGE = $newLine;
					}
				} elsif($conf eq "l" || $conf eq "L") {
					my $conf3 = "n";
					print("TO:  $LAST_CHANGE\nCHANGE TO LAST CHANGED (y/N):\n===> ");
					$conf3 = <STDIN>;
					chop($conf3);
					if($conf3 eq "y" || $conf3 eq "Y") {
						$LINES[$i]  = $LAST_CHANGE;
						$changed =  1;
						print("CHANGES  CONFIRMED!\n");
					}
			   } else {
				  print("CHANGES CANCELLED!\n");
			   }
			} else {
			   $LINES[$i] = $newLine;
			   $changed = 1;
			}
		 }
	  } 
   }
   if($changed == 1) {
	  system("/bin/cp $s_f $s_f.abk");
	  open(OUT, ">$s_f");
	  print(OUT @LINES);
	  close(OUT);
   }
}

sub ProgUsage(){
   print("\nUsage:      search_string.pl \"pattern\" directory [changeTo] [-y]\n");
   print("   pattern    : The pattern you want to search for\n");
   print("   directory  : The directory/file you want to search from.\n");
   print("   changeTo   : Change to this string.\n");
   print("   -y     : Auto confirm.\n");
}


sub sortDir {
    my $fa = "$CURRENT_DIR/$a";
    my $fb = "$CURRENT_DIR/$b";
    if(-d $fa) {
        if(-d $fb) {
            return $a cmp $b;
        } else {
            return -1;
        }
    } else {
        if(-d $fb) {
            return 1;
        } else {
            return $a cmp $b;
        }
    }  
}
