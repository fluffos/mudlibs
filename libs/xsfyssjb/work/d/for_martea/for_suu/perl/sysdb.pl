#!/usr/bin/perl

setpwent();
while (@list = getpwent()) {
	#($login, $uid, $path) = @list[0,2,7];
	#print "${login}'s uid is $uid.  \n";
	$list = join(":",@list);
	print "$list \n";
}
endpwent();