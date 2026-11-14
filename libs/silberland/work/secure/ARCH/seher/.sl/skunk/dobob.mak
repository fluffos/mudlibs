/def baba = -:winkt und sagt artig baba%;umarm elena%;kuess elena%;knuddel elena%;rumarm elena%;rwuschel elena%;fwink%;dwink%;schlaf ein%;

/def autopanzer_ein = /def -p300 -t'*Dein Elementarpanzer loest sich in die einzelnen Elemente auf.*' autopanzer = ziehe schuppenpanzer an
/def autopanzer_aus = /undef autopanzer
/def panzer = /autopanzer_ein%;ziehe schuppenpanzer aus%;elpa%;/repeat -00:00:04 1 ziehe schuppenpanzer an%;

/def -p20 -F -aCbggreen -mregexp -t"^  Du" autospell = /spell
/def spell = guck%;erzs
/def newspell = /def spell = guck%%;%{1}%%;
;/def -p20 -F -aCbgred -mregexp -t"^  [Der|Die|Das|Eine|Ein]" getroffen
;/def -p20 -F -t"*Du hast nicht genuegend Magiepunkte.*" magieaus = zueck degen

/load sl.mak
/load gross.mak
/load farben.mak
/pre lpmp
/vors 50
kwer

