#!/usr/bin/perl -w

print "Regular Expression \n";
$loop = 1;
while ($loop)
{
	print "Please input a string to match:\n";
	#chomp($StoMatch =<STDIN>);
	$StoMatch =<STDIN>;
	print "Please input a match pattern: \n";
	chomp($Pattern = <STDIN>);
	if ($StoMatch =~ m#$Pattern#) {          # does the input begin with a y?
		print "Yes, the string $StoMatch matches the pattern $Pattern. \n";
		$loop = 0;
	}else
	{
		print "$StoMatch doesn't match the pattern $Pattern.try again\n";
		$loop = 1;
	}
}
