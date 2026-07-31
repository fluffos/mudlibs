
#!/bin/perl -w

init_words();
print ("What is your name \n");
chomp ($name = <STDIN>);
if ($name =~ /^scott\b/i) {
	print ("Thank God, $ name you are here\n");
}else
{
	print("Now, give me your secret code \n");
	chomp($guess = <STDIN>);
	while(!good_name($name,$guess)) {
		print ("Wrong, guess again: \n");
		chomp($guess = <STDIN>);
	}
	print ("Welcome, $name! Come on in! \n");
}

sub good_name{

	my($somename, $somecode) = @_;
	$somename =~ s/\W.*//;
	$somename =~ tr/A-Z/a-z/;
	if (($words{$somename} || "DefaultCode") eq $somecode  ) {
		return 1;
	}
	open MAIL, "|mail suu\@fengyun.com" || die("cannot open mail $! \n");
	print MAIL "Bad news, $somename guess your code with $somecode";
	close MAIL;
	return 0;
}

#$mname =~ s/\W.*//;
#$mname =~ tr/A-Z/a-z/;

sub init_words{
	open(WORDLIST, "words") || die("cannot open word list $!"); 
	if (-M WORDLIST > 7.0) {
		die("Sorry, the wordlist is older than 7 days");
	}
	while (defined($name = <WORDLIST>)) {
		chomp($name);
		$word = <WORDLIST>;
		chomp($word);
		$words{$name} = $word;
	}
	close (WORDLIST) || die("cannot close word list");
}