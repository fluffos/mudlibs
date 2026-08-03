#!/usr/bin/perl -w
#
# File: trans.pl
# 功能: 本檔案可以把 DOS 格式的換行(\r\n)，轉換成 Linux 系
#       統使用的換行字元(\n)
# 由 wade@Fantasy.Space 所提供
# 歡迎任意拷貝與使用
# 如有任何問題，請聯絡：jjchen@alumni.ice.ntnu.edu.tw
#
use File::Find;
@ARGV = ('.') unless @ARGV;

find (\&mychange, @ARGV);

sub mychange {
  my ($file, $tmp);

  $file = $_;
  if (-d $file) {
    return;
  }
  $tmp = "tmp.";
  open (FILE, "< $file") || die "Cannot open file $file: $!";
  open (TMP, "> $tmp") || die "Cannot open file $tmp: $!";
  while (<FILE>) {
    # 底下的 \r 就是元兇所在。
    s/\r//;
    print TMP $_;
  }
  close (FILE);
  close (TMP);
  unlink ($file);
  rename ($tmp, $file) || warn "Cannot rename $tmp to $file: $!";
}

