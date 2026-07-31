#!/usr/bin/perl -w

$FY_AREA_DIR = "/u/fengyun/fy4/fy/d/";
$dir = $ARGV[0] or die(" You need specify which area you need to map.\n");
if (-d $FY_AREA_DIR.$dir) 
{
	open(MAPFILE,">".$dir.".map") || die("You don't have right to create map file. $!\n");
	@files =glob($FY_AREA_DIR.$dir."/*");
	outmost: foreach $file (@files) 
	{
		if (-d $file) 
		{
			print "$file is a directory \n";
			opendir(SUBDIR,$file) || die("You cannot open the dir $file. $!\n");
			while (defined($name = readdir(SUBDIR)))
			{
				print "\t".$name."\n";
			}
		}
#		open(ROOM,$file) || die("Cannot open file $file. $!\n");
#		#open(ROOM,$filename) || return 0;
#		while(<ROOM>)
#		{
#			if ($_ =~ /^[ \r\t]*inherit[ \r\t]*ROOM/)
#			{
#				$isroom = 1;	
#			}
#			if ($_ =~ /^[ \r\t]*set[ \r\t]*\([ \r\t]*\"short\"[ \r\t]*,[ \r\t]*\"(.*)\"/) 
#			{
#				$roomname = $1;
#				print "the room file $file has roomname $roomname \n";
#				print MAPFILE "the room file $file has roomname $roomname \n";
#				last;
#			}
#		}
	}
	close(ROOM);
	close(MAPFILE);
}else
{
	die("Directory $FY_AREA_DIR".$dir." doesn't exist. \nYou don't have area $dir under d\n");
}
