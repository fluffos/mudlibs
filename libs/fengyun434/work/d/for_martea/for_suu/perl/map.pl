#!/usr/bin/perl -w
%rooms = ();
@all = ();
%alltosub = ();
@directions = qw(north east south west northeast northwest southeast southwest northup northdown southup southdown eastup eastdown westup westdown up down);
@dirShort{@directions} = qw(n e s w ne nw se sw nu nd su sd eu ed wu wd u d);
$FY_AREA_DIR = "/u/fengyun/fy4/fy/d/";
$dir = $ARGV[0] or die(" You need specify which area you need to map.\n");
if (-d $FY_AREA_DIR.$dir) 
{
	@files =glob($FY_AREA_DIR.$dir."/*.c");
	foreach $file (@files) 
	{
		# get any one of the room file
		if (IsRoom($file))
		{
			VisitRoom($file);
			$all[0][0] = $file;
			$alltosub{$file} = "0:0";
			last;
		}
	}
	printmap();
}else
{
	die("Directory $FY_AREA_DIR".$dir." doesn't exist. \nYou don't have area $dir under d\n");
}

sub IsRoom
{
	my ($filename) = $_[0];
	open(ROOM,$filename) || die("Cannot open file $filename. $!\n");
	#open(ROOM,$filename) || return 0;
	while(<ROOM>)
	{
		if ($_ =~ /^[ \r\t]*inherit[ \r\t]*ROOM/) 
		{
			close(ROOM);
			return 1;
		}
	}
	close(ROOM);
	return 0;
	
}


sub VisitRoom
{
	local ($filename) = $_[0];
	if (defined($rooms{$filename}) && $rooms{$filename} eq "visited") 
	{
		return;
	}
	if (!IsRoom($filename)) {return;}
	$rooms{$filename} = "visited";
	open(ROOM,$filename) || die("Cannot open file $filename. $!\n");
	#open(ROOM,$filename) || return;
	local (%exits) = ();
	my ($roomname) = "";

	my(@subscript) = split(/:/,$alltosub{$filename});
	my($x) = $subscript[0];
	my($y) = $subscript[1];
	my($PrePendCol) = 0;
	my($PrePendRow) = 0;
	my($PendCol) = 0;
	my($PendRow) = 0;

	while(<ROOM>)
	{

		if (!$roomname && $_ =~ /^[ \r\t]*set[ \r\t]*\([ \r\t]*\"short\"[ \r\t]*,[ \r\tA-Z]*\"(.*)\"/) {
			$roomname = $1;
		}
		
		foreach $direction (@directions) 
		{
			if (GetExits($direction)) {
				last;
			}
		}
	}	
	close(ROOM) || die("Cannot close file $filename. $!\n");
	foreach $exitdir (keys(%exits)) {		
		if ($exitdir eq "west" || $exitdir eq "westup" || $exitdir eq "westdown")
		{
			if (!$PrePendCol) 
			{
				$PrePendCol = 1;
				$y++;
				$alltosub{$filename} = "$x:$y";
				my ($i) = 0;
				for ($i = 0; $i< $#all ; $i++) 
				{
					if ($i == $x) 
					{
						$all[$i] = ("$roomname:$exitdir",$all[$i]);
					}
					else
					{
						$all[$i] = ("",$all[$i]);
					}
				}

			}
			else
			{
				$all[$x][$y-1] =  $all[$x][$y-1]."=$roomname:$exitdir";
			}
		}

		if ($exitdir eq "east" || $exitdir eq "eastup" || $exitdir eq "eastdown")
		{
			if (!$PendCol) 
			{
				$PendCol = 1;
				my ($i) = 0;
				for ($i = 0; $i< $#all ; $i++) 
				{
					if ($i == $x) 
					{
						$all[$i] = ($all[$i],"$roomname:$exitdir");
					}
					else
					{
						$all[$i] = ($all[$i],"");
					}
				}

			}
			else
			{
				$all[$x][$y+1] =  $all[$x][$y+1]."=$roomname:$exitdir";
			}
		}

		if ($exitdir eq "north" || $exitdir eq "northup" || $exitdir eq "northdown" || $exitdir eq "up")
		{
			if (!$PrePendRow) 
			{
				$PrePendRow = 1;
				$x++;
				$alltosub{$filename} = "$x:$y";
				my ($i) = 0;
				my(@temp) = $all[$x-1];
				for ($i = 0;$i <$#temp ; $i++) {
					if ($i = $y) {
						$temp[$i] = "";
					}else{
						$temp[$i] = "$roomname:$exitdir";
					}

				}
				@all = (\@temp,@all);
			}
			else
			{
				$all[$x-1][$y] =  $all[$x-1][$y]."=$roomname:$exitdir";
			}
		}
		if ($exitdir eq "south" || $exitdir eq "southup" || $exitdir eq "southdown" || $exitdir eq "down")
		{
			if (!$PendRow) 
			{
				$PendRow = 1;
				my ($i) = 0;
				my(@temp) = $all[$x];
				for ($i = 0;$i <$#temp ; $i++) {
					if ($i = $y) {
						$temp[$i] = "";
					}else{
						$temp[$i] = "$roomname:$exitdir";
					}

				}
				@all = (@all,\@temp);
			}
			else
			{
				$all[$x+1][$y] =  $all[$x-1][$y]."=$roomname:$exitdir";
			}
		}
#		if ($exitdir eq "northeast") {
#			if ($PrePendRow && $PrePendCol) {
#				$all[$x-1][$y-1] = $all[$x-1][$y-1]."$roomname:$exitdir";
#				next;
#			}
#			#if row is already prepend then prepend col
#			if ($PrePendRow) {
#				$PrePendCol = 1;
#				$y++;
#				$alltosub{$filename} = "$x:$y";
#				my ($i) = 0;
#				for ($i = 0; $i< $#all ; $i++) 
#				{
#					if ($i == $x-1) 
#					{
#						$all[$i] = ("$roomname:$exitdir",$all[$i]);
#					}
#					else
#					{
#						$all[$i] = ("",$all[$i]);
#					}
#				}
#
#				next;
#			}
#			if ($PrePendCol) {
#				$PrePendRow = 1;
#				$x++;
#				$alltosub{$filename} = "$x:$y";
#				my ($i) = 0;
#				my(@temp) = $all[$x-1];
#				for ($i = 0;$i <$#temp ; $i++) {
#					if ($i = $y-1) {
#						$temp[$i] = "";
#					}else{
#						$temp[$i] = "$roomname:$exitdir";
#					}
#
#				}
#				@all = (\@temp,@all);
#				next;
#			}

#		}
	
		VisitRoom($exits{$exitdir});
	}
	#print MAPFILE $filename." ".$roomname."\n";
	#$roomname = "";
	close(ROOM);
}

sub GetExits
{
	$ExitDirection = $_[0];
	if ($_ =~ /^[ \r\t]*\"$ExitDirection\"[ \r\t]*:[ \r\t]*(.*)\"(.*)\"/) 
	{
		if ($1 eq "__DIR__") 
		{
			$exits{$ExitDirection} = $FY_AREA_DIR.$dir."/".$2.".c";
		}else
		{
			print ("room $filename connect to area outside $dir. \n");
		}
	}
}


sub printmap
{
	open(MAPFILE,">".$dir.".map") || die("You don't have right to create map file. $!\n");
	for ($i = 0; $i < $#all ;$i++) {
		foreach $roomname ($all[$i]) {
			print MAPFILE $roomname."\t";
		}
		print MAPFILE "\n";

	}
	close(MAPFILE);
}