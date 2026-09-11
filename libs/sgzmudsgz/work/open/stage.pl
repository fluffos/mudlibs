#!/usr/bin/perl
my($cvsRoot)     = '/home1/suede/cvsroot/';
my($exportDir)   = '/home1/lima/base/html/test/sgzweb/';
my($prefix) 	 = 'sgzweb/';
my($fileCapture) = 0;
my($files)       = "";
my(@importFiles) = qw();
my(@files1) = qw();
my(@files2) = qw();
my($subDir)      = "";

while(<STDIN>) {
    chop;
    if ($_ =~ /^Log Message:/) {
        $fileCapture = 0;
    } elsif ($_ =~ /^Update of /) {
        $subDir = $_;
        $subDir =~ s/^Update of $cvsRoot//;
    } elsif (($_ =~ /^Modified Files:/) ||
             ($_ =~ /^Added Files:/) ||
             ($_ =~ /^Removed Files:/)) {
        $fileCapture = 1;
    } elsif ($_ =~ /^(U|N) (\S+)$/) {
        my $fname = $2;
        $fname =~ s|/+|/|g;
        push(@importFiles,$fname);
    } elsif ($fileCapture) {
        $files .= $_;
    } 
}

# make argv[0] into a list of files
if ($ARGV[0] =~ /^(\S+?) (.+)$/) {
    my($dir) = $1;
    @files1 = split(' ',$2);
    @files1 = map { $dir.'/'.$_ } @files1;
}

# make the file capture files into a list of files
if ($files) {
    $files =~ s/\s+/ /g;
    $files =~ s/^\s+//g;
    @files2 = split(' ',$files);
    $subDir .= "/";

    if ($subDir eq "/") {
	$subDir = "";
    }
    
    @files2 = map { $subDir.$_ } @files2;
    @importFiles = (@importFiles, @files2);
}
# if imported list is there, use that
# otherwise, argv and capt list should be the same and we can use that

my($fileList,@fileList1);
if ($#importFiles >= 0) {
    @fileList1 = @importFiles;
} else {
    @fileList1 = @files1;
}
my($file) = "";
my(@fileList) = qw();

foreach $f (@fileList1) {
   if ($f =~ /^$prefix/) {
print "($f)\n";
	$f =~ s/^$prefix//;
	push (@fileList, $f);
   }
}
if (@fileList > 0) {
#
# remove any existing versions of the files
#
#unlink(map {$exportDir.'/'.$_ } @fileList);

#
# export the files
#
    $fileList = join(' ',@fileList);
    print "cd $exportDir; umask 002; /usr/bin/cvs update -d -P -D now $fileList\n";
    my($output) = `cd $exportDir; umask 002; /usr/bin/cvs -d /home1/suede/cvsroot update -d -P -D now $fileList`;
}