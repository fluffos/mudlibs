#!/usr/bin/perl -w
$template = "int __SPELL__(object caster, mapping sinfo)\n{\n  write(\"__SPELL__ gespellt.\");\n  return ERFOLG;\n}";
while(<>)
{
  chomp;
  open OUT, ">", "$_.c";
  $text = $template;
  $text =~ s/__SPELL__/$_/g;

  print OUT "// !!Spellfun generiert von fun_to_spell.pl!!\n";
  print OUT $text;
  close OUT;
}
