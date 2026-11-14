/def kathtank = /set i $[(%maxlp - %lebp)*10-50]%;/eval opfere %i muenzen%;/eval denk %i
/def gargylstart=fluchtrichtung betrete kathedrale%;vorsicht 100%;unt statue
/def flucht=/kathtank%;raus
/def stop=/purge gargyl*%;/def flucht=
/def -t'Du hast ja gar keine Muenzen.' gargylstop=/stop
/def -t'Du pluenderst die Leiche.' gargylnext=unt statue