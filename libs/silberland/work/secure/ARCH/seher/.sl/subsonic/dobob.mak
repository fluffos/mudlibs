/def baba = -:winkt und sagt artig baba%;umarm elena%;kuess elena%;knuddel elena%;rumarm elena%;rwuschel elena%;fwink%;dwink%;schlaf ein%;

/def autopanzer_ein = /def -p300 -t'*Dein Elementarpanzer loest sich in die einzelnen Elemente auf.*' autopanzer = ziehe schuppenpanzer an
/def autopanzer_aus = /undef autopanzer
/def panzer = /autopanzer_ein%;ziehe schuppenpanzer aus%;elpa%;/repeat -00:00:04 1 ziehe schuppenpanzer an%;

/def harfe1 = zuecke harfe%;spiele windmelodie fuer %{1}%;stecke harfe weg
/def harfe2 = zuecke harfe%;spiele windattacke fuer %{1}%;stecke harfe weg

/def -b'^x' xr = /if (lebp>70) \
                   ziehe kristallring aus%;ziehe astralring an%; \
                   xr%; \
                   ziehe astralring aus%;ziehe kristallring an%; \
                 /else \
                   /echo nicht wirklich oder???%; \
                 /endif
            

/def -p100 -F -mregexp -t'^Es gibt [a-z]+ sichtbare(|n) Ausga(e|)ng(e|)' autoturein = /autorein
/def autorein =
/def rein = /def autorein = %*

/def nehmen_aus = /edit -c0 autonehmen1%;/edit -c0 autonehmen2%;/edit -c0 autonehmen3%;
/def nehmen_ein = /edit -c100 autonehmen1%;/edit -c100 autonehmen2%;/edit -c100 autonehmen3%;
/def -p15 -au -mregexp -t'^Du nimmst .* ([A-Z][a-z]+).' autonehmen1 = e %P1 
/def -p20 -au -mregexp -t'^Du nimmst [0-9]+ ([A-Z][a-z]+).' autonehmen2 = geld 
/def -p10 -au -mregexp -t'^Du nimmst ([A-Z][a-z]+).' autonehmen3 = e %P1
/nehmen_aus
/def -b'^[[24~' nal = /repeat -00:00:01 1 /nehmen_aus%;/nehmen_ein%;nal %1%;
/def -b'^[[23~' na = /repeat -00:00:01 1 /nehmen_aus%;/nehmen_ein%;na%;

/def -p20 -F -auCbggreen -mregexp -t"^  Du " autospell = /spell
/def savespell = windstoss
/def spell = /savespell
/def newspell = /def savespell = %{1}

;/def -p15 -F -aCbgred -mregexp -t"^  [Der|Die|Das]" getroffen
;/def -p20 -F -t"*Du hast nicht genuegend Magiepunkte.*" magieaus = zueck degen

/def beep1 = /repeat 1 /beep
/def beep2 = /repeat 2 /beep
/def beep3 = /repeat 3 /beep
/def -p20 -F -t"*teilt Dir mit: ping*" pingme = /beep%;/beep1%;

/def -b'[21~' apfelessen = aus 2 apfel%;iss apfel%;
/def -p1 -t'*Uff, das bekommst Du nicht mehr *' einapfel2 = ein 2 apfel%;

/def pflueck = /repeat -00 100 schuettel baum%;\
               /repeat -00:00:10 1 /undef einapfel%;\
               /def -p1 -t"*Ploetzlich faellt ein Apfel herab. \
                             Du steckst ihn sofort ein.*" \
                              einapfel = ein 2 apfel%;

/def -b'^[^[' escesc = /dc%;/repeat 1 /retryein%;
/def retryein = /def -b'^[^[' escesc = /retry%%;/repeat 1 /dcein%%;
/def dcein = /def -b'^[^[' escesc = /dc%%;/repeat 1 /retryein%%;
            
/def -b'^[[20~' panzerimkampf = /def spell =%;\
                                /repeat -0:0:6 1 /def spell=/savespell%;\
                                /panzer
/def -b'^[[19~' fhimkampf = /def spell =%;\
                            /repeat -0:0:5 1 /def spell=/savespell%;\
                            fh

/def -b'^[[18~' laehmeimkampf = /def spell =%;\
                                /repeat -0:0:5 1 /def spell=/savespell%;\
                                laehme

/def robe = ziehe umhang aus%;\
            steck umhang in beutel 3%;\
            nimm zauberrobe aus beutel 3%;\
            ziehe zauberrobe an%;
/def buntu = ziehe robe aus%;\
             steck robe in beutel 3%;\
             nimm umhang 2 aus beutel 3%;\
             ziehe umhang an%;
/def feuu = ziehe robe aus%;\
            steck robe in beutel 3%;\
            nimm feuerumhang aus beutel 3%;\
            ziehe feuerumhang an%;



/load sl.mak
/load gross.mak
/load farben.mak
/pre lpmp
/vors 70
/flr /repeat /beep /beep2
/repeat -00:00:01 1 kwer

