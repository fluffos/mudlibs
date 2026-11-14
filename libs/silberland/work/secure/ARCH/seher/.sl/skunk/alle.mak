/def MACROFILE = ~/tf-dir/macros.tf
/def HILITEFILE = ~/tf-dir/hilite.tf
/def GAGFILE = ~/tf-dir/gag.tf
/def TRIGFILE = ~/tf-dir/trig.tf
/def BINDFILE = ~/tf-dir/bind.tf
/def HOOKFILE = ~/tf-dir/hook.tf
/def WORLDFILE = ~/tf-dir/world.tf
/def LOGFILE = tiny.log


/def p = 1%; 4%; 6%;
/def d = 3%;
/def f = 1%; 2%; 3%; 5%; 6%;
/def vzwerg = ve beutel%;
/def vsoeldner = ve lederruestung%; ve kupferschild%; ve saebel%;
/def vsoldat = ve eisenschild%; ve eisenpanzer%; ve lederstiefel%; ve kampfschwert%;
/def vwaechter = ve zwergenaxt%;ve kettenzeug%;ve lederstiefel%;ve kettenhemd

/def ik = nb karotte%;iss karotte%;
/def in = nb nuss%;iss nuss%;
/def ist = nb stangerl%;iss stangerl%;
/def iki = nb kipferl%;iss kipferl%;
/def is = nb semmel%;iss semmel%;
;/def wegaus = ultrakurz
;/def wegan = lang

/alias pine /sh pine
/def -i xtitle = /echo -r \033]2;%*\07

/def -b'^[[3~' bs = /dokey BSPC

/def -b'^[OQ' d1 = /d
/def -b'^[OR' f1 = /f
/def -b'^[OS' p1 = /p
/def -b'^[[17~' d2 = /d
/def -b'^[[18~' f2 = /f
/def -b'^[[19~' p2 = /p
/def -b'^[[12~' d3 = /d
/def -b'^[[13~' f3 = /f
/def -b'^[[14~' p3 = /p
/def -b'^[[[B' d4 = /d
/def -b'^[[[C' f4 = /f
/def -b'^[[[D' p4 = /p

/def -b'^[[|' schau = schau

/def na = /edit -c0 autonehmen1%;/edit -c0 autonehmen2%;/edit -c0 autonehmen3%;                                             
/def ne = /edit -c100 autonehmen1%;/edit -c100 autonehmen2%;/edit -c100 autonehmen3%;                                       
/def -p10 -au -mregexp -t'^Du nimmst .* ([A-Z][a-z]+).' autonehmen1 = sb %P1                                                         
/def -p15 -au -mregexp -t'^Du nimmst [0-9]+ ([A-Z][a-z]+).' autonehmen2 = geld                                                      
/def -p20 -au -mregexp -t'^Du nimmst ein Paar ([A-Z][a-z]+).' autonehmen3 = sb %P1                                                   
/na

/def mars=/sh finger @mars
/def pine=/sh pine
/require alias.tf

/def druidtank = /set i $[(%maxlp - %lebp)*15 - 100]%;/eval gib %i muenzen an druide
/def kathtank = /set i $[(%maxlp - %lebp)*10-50]%;/eval opfere %i muenzen%;/eval denk %i
/alias ktank /kathtank
/alias dtank /druidtank
/def laod = /load %*
